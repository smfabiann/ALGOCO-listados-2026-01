#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long m;
    cin >> n >> m;
    vector<pair<int, long long>> researchers(n);
    for (int i = 0; i < n; i++) {
        cin >> researchers[i].first >> researchers[i].second;
    }
    sort(researchers.begin(), researchers.end());

    multiset<long long> finales;
    finales.insert(researchers[0].first + researchers[0].second);

    int r = 0;
    for (int i=1; i<n; i++) {
        int a = researchers[i].first;
        long long s = researchers[i].second;
        
        auto it = finales.upper_bound(a);
        if (it != finales.begin()) {
            --it;
            if (a - *it <= m) {
                r++;
                finales.erase(it);
            }
        }
        finales.insert(a+s);
    }
    cout << r << "\n";

    return 0;
}