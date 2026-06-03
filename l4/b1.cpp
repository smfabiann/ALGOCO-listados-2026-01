#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    long long m;
    cin >> n >> m;
    vector<pair<int, long long>> researchers(n);
    for (int i=0; i<n; i++) {
        int a; long long s;
        cin >> a >> s;
        researchers[i] = {a, s};
    }
    
    return 0;
}