#include <iostream>
#include <vector>
using namespace std;

bool esPrimo(int n) {
    if (n <= 1) return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {

    int q;
    cin >> q;

    for (int i=0; i < q; i++) {
        int stones;
        cin >> stones;
        vector<int> buff;
        for (int i=1; i<stones+3; i++) buff.push_back(i);
        bool turno = 1;   // 1 ALICE, 0 BOB 

        while (stones != 0) {
            int candidato = 1;

            for (int i = buff.size() - 1; i >= 0; i--) {
                int p = buff[i];
                
                if (esPrimo(p)) {
                    if (stones - (p - 1) >= 0) {
                        candidato = p;
                        break; 
                    }
                }
            }

            cout << "Candidato para piedras: " << stones << "\n";
            if (candidato > 1) {
                stones = stones - (candidato - 1);
            } else {
                stones--;
            }
            cout << "---> Restantes " << stones << "\n";
            turno = !turno;
        }

        if (!turno) {
            cout << "Alice" << "\n";
        } else {
            cout << "Bob" << "\n";
        }
        // cout << "Cambio de caso!!" << "\n";
    }
    return 0;
}
