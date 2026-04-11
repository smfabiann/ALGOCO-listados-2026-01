#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool cmp(const string &a, const string &b) {
    return a.substr(0,2) < b.substr(0, 2);
}

int main() {
    int n;
    cin >> n;
    while (n != 0) {


        vector<string> s;

        for (int i = 0; i < n; i++) {
            string t;
            cin >> t;
            s.push_back(t);
        }

        stable_sort(s.begin(), s.end(), cmp);

        for (auto i: s) {
            cout << i << "\n";
        }
        cin >> n;
    }

    return 0;
}