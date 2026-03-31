#include <iostream>
#include <vector>

using namespace std;

int f[200005];
const int OFF = 100000;

int main() {
    int n, b;
    if (!(cin >> n >> b)) return 0;

    vector<int> v(n);
    int pos = -1;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == b) pos = i;
    }

    int suma = 0;
    f[OFF]++; 

    for (int i = pos - 1; i >= 0; i--) {
        if (v[i] > b) suma++;
        else suma--;
        f[suma + OFF]++;
    }

    long long total = 0;
    suma = 0;
    total += f[OFF]; 

    for (int i = pos + 1; i < n; i++) {
        if (v[i] > b) suma++;
        else suma--;
        total += f[-suma + OFF];
    }
    cout << total << endl;

    return 0;
}