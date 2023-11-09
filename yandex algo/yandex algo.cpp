#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> prices, clicks;
    int n, a, price = 0;
    cin >> n;
    for (int i = 0; i != n; i++) {
        cin >> a;
        prices.push_back(a);
    }
    for (int i = 0; i != n; i++) {
        cin >> a;
        clicks.push_back(a);
    }
    sort(clicks.begin(), clicks.end());
    sort(prices.begin(), prices.end());
    for (int i = 0; i != n; i++) {
        price += (clicks[i] * prices[i]);
    }
    cout << price;
}