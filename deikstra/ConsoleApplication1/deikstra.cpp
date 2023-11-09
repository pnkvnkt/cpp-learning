#include <fstream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    // === ПРЕОБРАЗОВАНИЕ ИЗ МАТРИЦЫ СОВМЕСТИМОСТИ В СЛОВАРЬ СМЕЖНОСТИ ===

    ifstream fin;
    fin.open("input.txt");
    // окрываем файл для чтения
    ofstream fout;
    fout.open("output.txt");

    int n, k, s, f;
    fin >> n >> s >> f;

    s -= 1;
    f -= 1;
    // в этом словаре хранится список смежности
    map<int, vector<int>> dict;
    // двумерный вектор для матрицы
    vector<vector<int>> matrix(n, vector<int>());
    // ввод матрицы
    for (int i = 0; i != n; i++) {
        for (int j = 0; j != n; j++) {
            fin >> k;
            matrix[i].push_back(k);
        }
    }
    // преобразование в список смежности 
    for (int i = 0; i != n; i++) {
        for (int j = 0; j != n; j++) {
            if (matrix[i][j] != 0 && matrix[i][j] != -1) {
                dict[i].push_back(j);
            }
        }
    }

    // ===== АЛГОРИТМ ДЕЙКСТРЫ =====

    int a;
    int inf = 2147483646;  // получаем максимально возможный int
    vector<int> distances(n, inf), is_visited(n, false);
    /*создаем два вектора,
    * один для  хранения минимального расстояния до этой вершины из нулевой точки, изначально все расстояния считаем бесконечными.
    * второй для отметки пройденных вершин
    */
    distances[s] = 0;
    for (int i = 0; i != n; i++) {
        int min_weight = -1;
        for (int b = 0; b != n; b++) {
            // ищем самый короткий еще непосещенный путь
            if (!is_visited[b] && (min_weight == -1 || (distances[b] < distances[min_weight]))) {
                min_weight = b;
            }
        }
        // отмечаем его посещенным
        is_visited[min_weight] = true;
        // проходим по всем смежным непройденным вершинам, и вычисляем минимум для них
        for (int i = 0; i != dict[min_weight].size(); i++) {
            a = dict[min_weight][i];
            if (!is_visited[a]) {
                if (distances[a] > distances[min_weight] + matrix[min_weight][a]) {
                    distances[a] = distances[min_weight] + matrix[min_weight][a];
                }
            }
        }
    }

    if (distances[f] == inf) {
        fout << -1;
    }
    else {
        fout << distances[f];
    }
    return 0;
}