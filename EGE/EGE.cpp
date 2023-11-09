#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ifstream fin;
    fin.open("26.txt");
    // окрываем файл для чтения
    int k = 0, f, s;
    vector<pair<int, int>> timetable;
    vector<pair<int, int>> answer;
    fin >> k;
    for (int i = 0; i != k; i++) {
        fin >> f;
        fin >> s;
        timetable.push_back(make_pair(f, s));
    }
    while (!timetable.empty()) {
        int minchempend = 1000000, minchempstart;
        for (pair<int,int> request: timetable) {
            if (request.second < minchempend) {
                minchempend = request.second;
                minchempstart = request.first;
            }
        }
        answer.push_back(make_pair(minchempstart, minchempend));
        for (int i = 0; i != timetable.size(); i++) {
            if ((timetable[i].first < minchempend + 15)) {
                timetable.erase(timetable.begin() + i);
                i -= 1;
            }
        }
        //&& timetable[i].first > minchempstart) || (timetable[i].second < minchempend + 15 && timetable[i].second > minchempstart
    }
    for (pair<int, int> request : answer) {
        cout << request.first << ' ' << request.second << endl;
    }
    cout << (answer.size()) << endl;
    cout << answer[answer.size() - 1].first - answer[answer.size() - 2].second;
}

