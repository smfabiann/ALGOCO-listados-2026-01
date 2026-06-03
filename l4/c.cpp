#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;

int main() {
    int pole_distance = 6;
    int l, d, n;
    cin >> l >> d >> n;

    int t;
    vector<int> pajaros(l, 0);
    for (int i=0; i<n; i++) {
        cin >> t;
        pajaros[t] = 1;
    }
    
    
    return 0;
}