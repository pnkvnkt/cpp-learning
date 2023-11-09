#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> steps;
// в этом векторе хранятся шаги при обходе в глубину и ширину
map<int, vector<int>> dict;
// в этом словаре хранится список смежности

void DFS(int n) {
    steps.push_back(n);
    // === РЕКУРСИВНЫЙ АЛГОРИТМ ПОИСКА ВГЛУБЬ ===

    for (int a : dict[n]) {
        if (find(steps.begin(), steps.end(), a) == steps.end()) {
            // если есть в векторе steps
            DFS(a);
        }
    }
}


int main()
{
    // === ПРЕОБРАЗОВАНИЕ ИЗ МАТРИЦЫ СОВМЕСТИМОСТИ В СЛОВАРЬ СМЕЖНОСТИ ===

    cout << "Enter the number of graphs" << endl;
    int n, k;
    cin >> n;
    // двумерный вектор для матрицы
    vector<vector<int>> matrix(n, vector<int>());
    // ввод матрицы
    cout << "digit is a weight of the path, 0 means there isnt a path" << endl;
    for (int i = 0; i != n; i++) {
        cout << "enter line of matrix" << endl;
        for (int j = 0; j != n; j++) {
            cin >> k;
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
    // вывод
    for (int i = 0; i != n; i++) {
        cout << i << ": ";
        for (int a : dict[i]) {
            cout << a << ", ";
        }
        cout << endl;
    }

    // === ОБХОД В ГЛУБИНУ ===

    DFS(0);
    cout << "DFS : ";
    for (int i : steps) {
        cout << i;
    }

    // === ОБХОД В ШИРИНУ ===

    stack<int> queue;
    // стек для алгоритма
    // steps снова вектор для хранения шагов
    steps.clear();
    // первое значение - 0
    queue.push(0);
    steps.push_back(0);
    // пока стек не пустой, то мы  не прошли все вершины
    while (!queue.empty()) {
        //  вытаскиваем число из стека
        int cur = queue.top();
        queue.pop();
        // проходим по смежным вершинам для текущей вершины
        for (int a : dict[cur]) {
            if (find(steps.begin(), steps.end(), a) == steps.end()) {
                // если по ней еще не прошли, то добавляем в стек, и отмечаем ее пройденной
                queue.push(a);
                steps.push_back(a);
            }
        }
    }
    // вывод
    cout << endl << "BFS : ";
    for (int i : steps) {
        cout << i;
    }
    return 1;
}

