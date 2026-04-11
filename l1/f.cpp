#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n, y;
    cin >> n >> y;

    unordered_set<int> mapa;
    
    for (int i=0; i<y; i++) {
        int k;
        cin >> k;
        mapa.insert(k);
    }
    int m = 0;
    for (int i=0; i<n; i++) {
        if (mapa.find(i) != mapa.end()) {
            m++;
            continue;
        }
        cout << i << endl;
    }

    cout << "Mario got " << m << " of the dangerous obstacles.\n";
    return 0;
}