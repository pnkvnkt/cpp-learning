#include <iostream>
#include <vector>
#include <map>
using namespace std;

//if (find(steps.begin(), steps.end(), a) == steps.end()) {
//	// если есть в векторе steps
//	DFS(a);
//}
vector<int> is_visited(4, false);
vector<long> w(4, 9000000000);
map<int, vector<int>> dict;
map<int, vector<long>> b;
int Y;
void A(int a, long T) {

}
int main()
{
	cin >> Y;
	dict[12] = { 23, 41 };
	dict[23] = { 12, 34 };
	dict[34] = { 23, 41 };
	dict[41] = { 12, 34 };
	long R1, R2, R3, G1, G2, G3, T1, T2, T3, R4, G4, T4;
	cin >> R1 >> G1 >> T1;
	cin >> R2 >> G2 >> T2;
	cin >> R3 >> G3 >> T3;
	cin >> R4 >> G4 >> T4;
	b[45] = { R2, G2, T2 };
	b[53] = { R1, G1, T1 };
	b[57] = { R3, G3, T3 };
	b[75] = { R4, G4, T4 };
	for (int next : dict[12]) {
		A(next, b[12+next]);
	}

}