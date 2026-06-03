#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long m;
    if (!(cin >> n >> m)) return 0;
    
    vector<pair<long long, long long>> researchers(n);
    for (int i = 0; i < n; i++) {
        cin >> researchers[i].first >> researchers[i].second;
    }
    
    sort(researchers.begin(), researchers.end());

    priority_queue<long long, vector<long long>, greater<long long>> pc;

    int r = 0;

        for (int i = 0; i < n; i++) {
        long long a = researchers[i].first;
        long long s = researchers[i].second;


        while (!pc.empty() && pc.top() + m < a) {
            pc.pop();
        }

        if (!pc.empty() && pc.top() <= a) {
            pc.pop();
            r++;
        }
        pc.push(a + s);
    }

    cout << r << "\n";

    return 0;
}