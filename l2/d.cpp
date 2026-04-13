#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

// no tenia ni idea que ya esta implementado en c++ el estable sort
void stable_sort_sigma(vector<vector<string>>& canciones, int index) {
    stable_sort(canciones.begin(), canciones.end(),
        [index](const vector<string>& a, const vector<string>& b) {
            return a[index] < b[index];
        }
    );
}
int main() {
    string atributos;
    getline(cin, atributos);
    istringstream ss(atributos);

    unordered_map<string, int> attr_index;
    vector<string> attr_list;
    string attr;
    int idx = 0;
    while (ss >> attr) {
        attr_index[attr] = idx++;
        attr_list.push_back(attr);
    }

    int n;
    cin >> n;
    cin.ignore();

    vector<vector<string>> canciones(n); // la wea no tenia un tamaño fijo antes

    for (int i = 0; i < n; i++) {
        string cancion;
        getline(cin, cancion);
        istringstream ssCancion(cancion);
        string palabra;
        while (ssCancion >> palabra) {
            canciones[i].push_back(palabra);
        }
    }

    int m;
    cin >> m;
    cin.ignore();

    vector<string> instrucciones(m);
    for (int i = 0; i < m; i++) {
        getline(cin, instrucciones[i]);
    }


    // printeamos el resultado de stable sort
    for (const auto& instr : instrucciones) {
        stable_sort_sigma(canciones, attr_index[instr]);
        
        for (auto const& atri : attr_list) {
            cout << atri << " ";
        }

        cout << "\n";
        // printeamos las canciones
        for (size_t i = 0; i < canciones.size(); i++) {
            for (const auto& pene : canciones[i]) {
                cout << pene << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }


    return 0;
}