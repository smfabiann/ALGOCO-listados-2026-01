#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int j=0; j<n; j++)
    {
        vector<int> arr;
        int t, iter;
        cin >> iter >> t;
        arr.push_back(t);

        int steps = 0;
        for (int i=1; i<20; i++) {
            cin >> t;
            bool inserted = false;
            for (auto it = arr.begin(); it < arr.end(); it++) {
                if (t < *it) {
                    steps += arr.size() - (it - arr.begin());
                    arr.insert(it, t);
                    inserted = true;
                    break;
                }
            }
            if (!inserted) arr.push_back(t);
        }
        cout << iter << " " << steps << "\n";
    }
    
    return 0;
}