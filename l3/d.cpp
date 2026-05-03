#include <iostream>
#include <vector>
#include <string>
using namespace std;

int target;
int minimominimo = 0;

void permutaciones(string s, int l, int r) {
    if (l == r) {
    } else {
        for (int i = l; i <= r; i++) {
            swap(s[l], s[i]);
            if (minimominimo == 0 && target < stoi(s)) minimominimo = stoi(s);
            if (stoi(s) < minimominimo && target < stoi(s)) minimominimo = stoi(s);  
            permutaciones(s, l + 1, r);
            swap(s[l], s[i]); 
        }
    }
}

int main() {
    string buffer;
    cin >> buffer;
    target = stoi(buffer);

    permutaciones(buffer, 0, buffer.size()-1);

    cout << minimominimo << endl;

    return 0;
}