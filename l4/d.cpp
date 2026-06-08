#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, t;
    cin >> n;
    vector<int> prices(n);
    for (int i=0; i<n; i++) {
        cin>>t;
        prices[i] = t;
    }
    sort(prices.rbegin(), prices.rend());
    // for (int i : prices) cout << i << " ";
    // cout << "\n";

    int max_discounts = n/3;
    long long r = 0;
    for (int i=0; i < max_discounts; i++) {
        int pos = 3*i + 2;
        r = r + prices[pos];
    }
    cout << r << "\n";
    return 0;
}