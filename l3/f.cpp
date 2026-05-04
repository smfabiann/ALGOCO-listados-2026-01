#include <iostream>
using namespace std;

int bitshfit_noncircular(int x) {
    return x ^ ((x << 1) % 256);
}

int fuerzabruta(int b) {
    for (int x = 0; x <= 255; x++) {
        if (bitshfit_noncircular(x) == b)
            return x;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        cout << fuerzabruta(b);
        cout << " ";
    }
    cout << endl;
    
    return 0;
}