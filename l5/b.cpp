#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> costs(n);
    for (int i = 0; i < n; ++i) {
        cin >> costs[i];
    }
    int m; cin >> m;
    vector<int> orders(m);
    int max_order = 0;
    for (int i = 0; i < m; ++i) {
        cin >> orders[i];
        if (orders[i] > max_order) {
            max_order = orders[i];
        }
    }
    int maximium = min(30000, max_order);
    vector<int> dp(maximium + 1, 0);
    dp[0] = 1; 
    for (int i = 0; i < n; ++i) {
        int c = costs[i];
        for (int w = c; w <= maximium; ++w) {
            dp[w] += dp[w - c];
            if (dp[w] > 2) {
                dp[w] = 2;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        int s = orders[i];
        
        if (s > maximium || dp[s] == 0) {
            cout << "Impossible\n";
        } else if (dp[s] > 1) {
            cout << "Ambiguous\n";
        } else {
            int actual = s;
            vector<int> r;
            while (actual > 0) {
                for (int j = 0; j < n; ++j) {
                    int c = costs[j];
                    if (actual >= c && dp[actual - c] == 1) {
                        r.push_back(j + 1); 
                        actual -= c;
                        break; 
                    }
                }
            }
            sort(r.begin(), r.end());
            for (size_t j = 0; j < r.size(); ++j) {
                cout << r[j] << (j + 1 == r.size() ? "" : " ");
            }
            cout << "\n";
        }
    }

    return 0;
}