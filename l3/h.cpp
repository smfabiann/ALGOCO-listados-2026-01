#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long resultado = 0;
const string vocals = "#AEIOU";

bool esVocal(char c) {
    for (char i: vocals) if (c == i) return true;
    return false;
}

bool validar(string word) {
    bool tiene_L = false;
    int n = word.size();

    for (int i = 0; i < n; i++) {
        if (esVocal(word[i])) {     // 3 vocales juntas
            if (i + 2 < n) {
                if (esVocal(word[i+1]) && esVocal(word[i+2])) return false;
            }
        } else {    
                            // 3 consonantes juntas
            if (i + 2 < n) {
                if (!esVocal(word[i+1]) && !esVocal(word[i+2])) return false;
            }
        }
        // tiene una L
        if (word[i] == 'L') tiene_L = true; 
    }

    if (tiene_L) {
        long long combinaciones_palabra = 1;
        
        // estimacion de combinaciones
        for (char i: word) {
            if (i == '.') {
                combinaciones_palabra = combinaciones_palabra * 20;
            } else if (i == '#') {
                combinaciones_palabra = combinaciones_palabra * 5;
            }
        }
        resultado = resultado + combinaciones_palabra; 
        return true;
    }
    return false;
}

void permutaciones(string word, vector<int> positions, string &iterar) {
    if (positions.empty()) {
        if (validar(word)) {
            // cout << "Valido: "<< word << "\n";
        }
        return;
    }
    
    for (char i: iterar) {
        vector<int> pos = positions;
        word[pos.back()] = i;
        pos.pop_back();
        permutaciones(word, pos, iterar);
    }
}

int main() {
    string word;
    cin >> word;
    int n = word.size();

    vector<int> blank_positions;
    for (int i =0; i  < n; i++) {
        if (word[i] == '_') blank_positions.push_back(i);
    }

    string iterar = "#L.";
    permutaciones(word, blank_positions, iterar);
    cout << resultado << endl;
    return 0;
}