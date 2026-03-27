#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    int casos;
    cin >> casos;

    for (int i=0; i<casos; i++) {
        string p;
        int n;
        deque<int> l;

        cin >> p;
        cin >> n;
        string temp;
        cin >> temp;
        // procesar la lista
        string buffer;
        for (char carac: temp) {
            if (isdigit(carac)) {
                buffer += carac;
            } else if (carac == ',' || carac == ']') {
                if (!buffer.empty()) {
                    l.push_back(stoi(buffer));
                    buffer = "";
                }
            }
        }
        
        bool valido = true;
        bool isfront = true;
        for (char c: p) {
            if (c == 'R') {
                isfront = !isfront;
            } else if (c == 'D') {
                if (l.empty()) {
                    cout << "error" << "\n";
                    valido = false;
                    break;
                }
                if (isfront) {
                    l.pop_front();
                } else {
                    l.pop_back();
                }
            }
        }
        if (valido) {
            cout << "[";
            if (isfront) {
                for (auto it = l.begin(); it != l.end(); ++it) {
                    cout << *it;
                    if (next(it) != l.end()) cout << ",";
                }
            } else {
                for (auto it = l.rbegin(); it != l.rend(); ++it) {
                    cout << *it;
                    if (next(it) != l.rend()) cout << ",";
                }
            }
            
            cout << "]\n";
        }
        
    }
    return 0;
}