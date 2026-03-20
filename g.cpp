#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main() {

    string buffer;
    vector<string> v;
    while (cin >> buffer) {
        v.push_back(buffer);
    }
    set<string> ponderaciones;
    int n = v.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i != j) {
                ponderaciones.insert(v[i] + v[j]);
            }
        }
    }

    for (string s : ponderaciones) {
        cout << s << endl;
    }
    
    return 0;
}