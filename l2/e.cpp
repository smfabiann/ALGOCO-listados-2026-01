#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int freqA[101] = {};
    int freqB[101] = {};
    int total = 0;
    
    for (int cas = 0; cas < n; cas++) {
        int t1, t2;
        cin >> t1 >> t2;
        freqA[t1]++;
        freqB[t2]++;
        total++;
        
        int maxsuma = -1;
        int i = 1, j = 100;
        int caca = freqA[1], cece = freqB[100];
        int count = 0;
        
        while (count < total) {
            while (caca == 0) { i++; caca = freqA[i]; }
            while (cece == 0) { j--; cece = freqB[j]; }   
            int pares = min(caca, cece);
            if (i + j > maxsuma) maxsuma = i + j;
            caca -= pares;
            cece -= pares;
            count += pares;
        }
        cout << maxsuma << "\n";
    }
    return 0;
}