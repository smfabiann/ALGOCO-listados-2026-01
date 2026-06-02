#include <iostream>
#include <set>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    multiset<int> tareas;
    multiset<int> intervalos;
    int t;
    for (int i=0; i<n;i++) {
        cin>>t;
        tareas.insert(t);
    }
    for (int i=0; i<m;i++) {
        cin>>t;
        intervalos.insert(t);
    }
    auto it1 = tareas.begin();
    auto it2 = intervalos.begin();
    int r = 0;
    while (it1 != tareas.end() && it2 != intervalos.end()) {
        if (*it1 <= *it2) {
            it1++; it2++;
            r++;
        }
        else {
            it2++;
        }
    }

    cout << r << endl;
    return 0;
}