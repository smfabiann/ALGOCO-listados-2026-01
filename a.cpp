#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int posicion = 0;
    stack<int> pila;

    for (int i = 0; i < k; i++) {
        string entrada;
        cin >> entrada;

        if (entrada == "undo") {
            int next;
            cin >> next;
            for (int j=0; j<next;j++) {
                posicion -= pila.top();
                pila.pop();
            }
        } else {
            int num = stoi(entrada);
            pila.push(num);
            posicion += num;
        }
        posicion = ((posicion%n) + n) % n;
    }
    cout << posicion << endl;
    return 0;
}