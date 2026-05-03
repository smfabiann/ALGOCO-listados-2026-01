#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string in; cin >> in;
    int target = stoi(in);
    int minmin = 0;

    sort(in.begin(), in.end());
    do {
        int caca = stoi(in);
        if (minmin == 0) {
            if (target < caca) minmin = caca;
        } else {
            if (caca < minmin) minmin = caca;
        }
    } while(next_permutation(in.begin(), in.end()));

    cout << minmin << endl;

    return 0;
}