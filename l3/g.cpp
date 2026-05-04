#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool estaEnVector(const string& color, const vector<string>& colores) {
    for (const string& i : colores) if (color == i) return true;
    return false;
}

bool sonOdiados(const string& a, const string& b, unordered_map<string, vector<string>>& odiados) {
    return !odiados[a].empty() && estaEnVector(b, odiados[a]);
}

bool esMejor(vector<string>& nueva, vector<string>& actual, unordered_map<string, int>& pref) {
    for (int i = 0; i < (int)nueva.size(); i++) {
        if (pref[nueva[i]] > pref[actual[i]]) return true;
        if (pref[nueva[i]] < pref[actual[i]]) return false;
    }
    return false;
}

vector<string> colores;
unordered_map<string, vector<string>> odiados;
unordered_map<string, int> pref;
vector<string> pintura_preferida;
vector<bool> usado;
vector<string> actual;
int pinturas;

void backtrack() {
    if ((int)actual.size() == (int)colores.size()) {
        pinturas++;
        if (pintura_preferida.empty() || esMejor(actual, pintura_preferida, pref))
            pintura_preferida = actual;
        return;
    }

    for (int i = 0; i < (int)colores.size(); i++) {
        if (usado[i]) continue;
        if (!actual.empty() && sonOdiados(actual.back(), colores[i], odiados)) continue;

        usado[i] = true;
        actual.push_back(colores[i]);
        backtrack();
        actual.pop_back();
        usado[i] = false;
    }
}

int main() {
    int cases;
    cin >> cases;

    while (cases--) {
        int max_colors = 12;
        pref.clear(); odiados.clear(); colores.clear();
        pintura_preferida.clear(); actual.clear();
        pinturas = 0;

        int n_colors;
        cin >> n_colors;
        for (int i = 0; i < n_colors; i++) {
            string color; cin >> color;
            colores.push_back(color);
            pref[color] = max_colors--;
        }

        int n_pares; cin >> n_pares;
        for (int i = 0; i < n_pares; i++) {
            string a, b; cin >> a >> b;
            odiados[a].push_back(b);
            odiados[b].push_back(a);
        }

        usado.assign(n_colors, false);

        sort(colores.begin(), colores.end(), [](const string& a, const string& b) {
            return a < b;
        });

        backtrack();

        cout << pinturas << "\n";
        for (string i : pintura_preferida) cout << i << " ";
        cout << "\n";
    }

    return 0;
}