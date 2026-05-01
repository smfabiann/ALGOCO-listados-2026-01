#include <iostream>
#include <math.h>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    unordered_map<char, vector<int>> original;
    vector<char> f = {
        'A','B','C','D',
        'E','F','G','H',
        'I','J','K','L',
        'M','N','O','.'
    };
    int k = 0;
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
        original[f[k++]] = {i,j};
    };
    int total = 0;
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
        char temp;
        cin >> temp;
        if (temp == '.') continue;
        total += abs(i-original[temp][0]) + abs(j-original[temp][1]);
    };
    cout << total << endl;


    return 0;
}