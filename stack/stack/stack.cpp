#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	stack <char> stackBracket;
	string expression;
	int otkr = 0, zakr = 0;
	std::cout << "Enter string" << endl;
	cin >> expression;
	for (char a : expression) {
		if (a == '(' || a == '{' || a == '[') {
			stackBracket.push(a);
		}
		else {
			if (a == ')' && !(stackBracket.top() == '(')) {
				break;
			} 
			else if (a == '}' && !(stackBracket.top() == '{')) {
				break;
			} 
			else if (a == ']' && !(stackBracket.top() == '[')) {
				break;
			}
			stackBracket.pop();
		}
	}
	if (stackBracket.empty()) {
		cout << "OK";
	}
	else {
		cout << "ERROR";
	}
}
