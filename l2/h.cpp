#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
    int n; cin >> n;
    

    while (n != 0) {
        vector<int> v1;
        map<int, int> m;
        multiset<int> ms;
        for (int i=0; i<n; i++) {
            int t; cin >> t;
            v1.push_back(t);
        }
        for (int i=0; i<n; i++) {
            int t; cin >> t;
            ms.insert(t);
        }
        auto it = ms.begin();
        vector<int> sorted_v1 = v1;
        sort(sorted_v1.begin(), sorted_v1.end());
        for (int i: sorted_v1) {
            m[i] = *it++;
        }

        for (int i : v1) {
            cout << m[i] << "\n";
        }
        cin >> n;
    }

    return 0;
}