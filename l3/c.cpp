#include <bits/stdc++.h>
using namespace std;

string wff;
int pos;

int eval(const map<char,int>& env) {
    char c = wff[pos++];
    if (c >= 'p' && c <= 't') return env.at(c);
    if (c == 'N') return 1 - eval(env);
    int w = eval(env), x = eval(env);
    if (c == 'K') return w & x;
    if (c == 'A') return w | x;
    if (c == 'C') return (1 - w) | x;
    if (c == 'E') return 1 - (w ^ x);
    return 0;
}

void collectVars(set<char>& vars) {
    if (pos >= (int)wff.size()) return;
    char c = wff[pos++];
    if (c >= 'p' && c <= 't') { vars.insert(c); return; }
    if (c == 'N') { collectVars(vars); return; }
    collectVars(vars); collectVars(vars);
}

bool esTautologia;
vector<char> vars;
map<char,int> asignacion;

void backtrack(int idx) {
    // caso base: ya asignamos todas las variables
    if (idx == (int)vars.size()) {
        pos = 0;
        if (!eval(asignacion))
            esTautologia = false; // encontramos un contraejemplo
        return;
    }

    // probamos asignar 0 a la variable actual
    asignacion[vars[idx]] = 0;
    backtrack(idx + 1);

    // probamos asignar 1 a la variable actual
    asignacion[vars[idx]] = 1;
    backtrack(idx + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> wff && wff != "0") {
        pos = 0;
        set<char> varSet;
        collectVars(varSet);
        vars.assign(varSet.begin(), varSet.end());

        esTautologia = true;
        asignacion.clear();
        backtrack(0);

        cout << (esTautologia ? "tautology" : "not") << "\n";
    }
}