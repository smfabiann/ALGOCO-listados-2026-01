#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;

    set<int> shop;
    vector<int> joe;

    for (int i=0; i<n; i++) {
        int t; cin >> t;
        shop.insert(t);
    }
    for (int i=0; i<m; i++) {
        int t; cin >> t;
        joe.push_back(t);
    }
    // Long long de mierda
    long long wasted = 0;
    for (int i : joe) {
        auto it = shop.lower_bound(i);
        wasted += *it - i;
    }

    cout << wasted << endl;
    return 0;
}