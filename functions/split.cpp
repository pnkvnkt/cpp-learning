#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	vector <string> mas;
	string str, a = "";
	cin >> str;

	for (int i = 0; i != str.length(); i++) {
		if (str[i] == ' ') {
			mas.push_back(a);
			a = "";
		}
		else {
			a += str[i];
		}
	}

	for (string i : mas) {
		cout << i << ' ';
	}
}
