#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    long long int n;
    cin >> n;
    vector<long long int> pilares;
    for (int i=0; i<n; i++) {
        long long int t;
        cin >> t;
        pilares.push_back(t);
    }

    vector<long long int> max_R(n);
    vector<long long int> max_L(n);
    max_R[0] = pilares[0];
    max_L[n-1] = pilares[n-1];
    for (long long int i=1; i<n; i++) {
        max_R[i] = max(max_R[i-1], pilares[i]);
    }

    for (long long int i=n-2; i>=0; i--) {
        max_L[i] = max(max_L[i+1], pilares[i]);
    }

    // for (auto i: max_R) cout << i << " ";
    // cout << "\n";
    // for (auto i: max_L) cout << i << " ";
    // cout << "\n";

    long long int salto = 0;
    for (long long int i=0; i<n; i++) {
        long long int pilar = pilares[i];
        long long int h = min(max_R[i], max_L[i]);
        if (salto < h - pilar) {
            salto = h - pilar;
            // cout << "a> " << i << "\n";
            // cout << "b<" << salto << "\n";
            // cout << "c<" << h << "\n";
            // cout << "d<" << pilar << "\n";
        }
    }

    cout << salto << endl;
    return 0;
}