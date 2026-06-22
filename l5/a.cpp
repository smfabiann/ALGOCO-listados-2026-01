#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c, n;
    int cont = 0;
    while ((cin >> c >> n) && cont < 30) {
        vector<pair<int,int>> objetos(n);
        for (int i = 0; i < n; i++) cin >> objetos[i].first >> objetos[i].second;

        vector<vector<int>> knapsack(n+1, vector<int>(c+1, 0));

        for (int i = 1; i <= n; i++) {
            int valor = objetos[i-1].first;
            int peso  = objetos[i-1].second;
            for (int j = 0; j <= c; j++) {
                knapsack[i][j] = knapsack[i-1][j];
                if (j >= peso)
                    knapsack[i][j] = max(knapsack[i][j], knapsack[i-1][j-peso] + valor);
            }
        }

        // Reconstrucción: i va de n a 1 (decreciente), reverse es O(n) vs sort O(n log n)
        int i = n, j = c;
        vector<int> recorrido;
        while (i > 0 && j >= 0) {
            int peso = objetos[i-1].second;
            if (knapsack[i][j] != knapsack[i-1][j]) {
                recorrido.push_back(i - 1);  // índice 0-based directo
                j -= peso;
            }
            i--;
        }
        cout << recorrido.size() << "\n";
        for (int k = recorrido.size()-1; k >= 0; k--) cout << recorrido[k] << " ";
        cout << "\n";

        cont++;
    }
    return 0;
}