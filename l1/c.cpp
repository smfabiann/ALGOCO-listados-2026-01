#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();

    for (int cases=0; cases<t; cases++) {
        string word;
        getline(cin, word);

        list<char> lista;
        auto it = lista.begin();
        for (char c: word) {
            if (c == '[') {
                it = lista.begin();
            }
            else if (c == ']') {
                it = lista.end();
            }
            else if (c == '<') {
                if (it != lista.begin()) {
                    auto borrar = it;
                    borrar--;
                    lista.erase(borrar);
                }
            }
            else {
                lista.insert(it, c);
            }
        }

        for (auto i: lista) {
            cout << i;
        }
        cout << endl;
    }   

    return 0;
}