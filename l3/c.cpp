#include <iostream>
#include <string>
#include <map>
using namespace std;

string wff;
int pos;

int eval(map<char,int>& env) {
    char c = wff[pos++];
    if (c >= 'p' && c <= 't') return env[c];
    if (c == 'N') return !eval(env);
    int w = eval(env);
    int x = eval(env);
    if (c == 'K') return w && x;
    if (c == 'A') return w || x;
    if (c == 'C') return !w || x;
    if (c == 'E') return w == x;
    return 0;
}

int main() {
    while (cin >> wff && wff != "0") {
        // juntar las variables que aparecen
        string vars = "";
        for (char c : wff)
            if (c >= 'p' && c <= 't' && vars.find(c) == string::npos)
                vars += c;

        int n = vars.size();
        bool taut = true;

        // probar todas las combinaciones
        for (int mask = 0; mask < (1 << n) && taut; mask++) {
            map<char,int> env;
            for (int i = 0; i < n; i++)
                env[vars[i]] = (mask >> i) & 1;
            pos = 0;
            if (!eval(env)) taut = false;
        }

        cout << (taut ? "tautology" : "not") << "\n";
    }
}