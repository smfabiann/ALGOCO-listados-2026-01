#include <iostream>
#include <vector>
using namespace std;

bool esCuadrado(vector<int> a, vector<int> b, vector<int> c) {
    // una en cima de la otra
    if (b[0] + a[1] == a[0] && c[0] + a[1] == a[0]) {
        if (b[1] + c[1] == a[0]) return true;
    }

    // las siguientes al tado de otra
    if (a[0] == b[0] && a[0] == c[0] && b[0] == c[0]) {
        if (a[1] + b[1] + c[1] == a[0]) return true; 
    }

    return false;
}

int main() {
    int temp;
    vector<int> A;
    vector<int> B;
    vector<int> C;
    
    for (int i=0; i<2; i++) {cin >> temp; A.push_back(temp);}
    for (int i=0; i<2; i++) {cin >> temp; B.push_back(temp);}
    for (int i=0; i<2; i++) {cin >> temp; C.push_back(temp);}

    if (esCuadrado(A, B, C) || esCuadrado(A, {B[1], B[0]}, C) || esCuadrado(A, B, {C[1], C[0]}) || esCuadrado(A, {B[1], B[0]}, {C[1], C[0]})) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}