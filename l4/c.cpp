#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int l, d, n;
    cin >> l >> d >> n;

    int t;
    vector<int> pajaros(n);
    for (int i=0; i<n; i++) {
        cin >> t;
        pajaros[i] = t;
    }
    if (n == 0) {
        cout << ((l - 12)/d)+1 << "\n";
        return 0;
    } else if (n == 1) {
        int izq, der;
        if (pajaros[0] != 6) {
            izq = ((pajaros[0] - 6) / d);
        }
        if (pajaros[0] != l-6) {
            der = ((l-6 - pajaros[0]) / d);
        }
        cout << izq + der << "\n";
    }
    sort(pajaros.begin(), pajaros.end());
    int r = 0;
    // limite izquierdo
    if (6 < pajaros[0] && ((pajaros[0] - 6) / d) + 1 > 1) {
        r += ((pajaros[0] - 6) / d);
    };
    // limite derecho
    if (pajaros[n-1] < l-6 && ((l-6 - pajaros[n-1])/d) + 1 > 2) {
        r += (((l-6 - pajaros[n-1])/d) + 1) - 1;
    }
    for (int i = 1; i < n; i++) {
        if (((pajaros[i] - pajaros[i-1])/d) + 1 > 2) {
            r += (((pajaros[i] - pajaros[i-1])/d) + 1) - 2;
        };
    }
    cout << r << "\n";
    return 0;
}