#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

struct caca {
    vector<int> score;
    string name;
};

int main() {
    int T, n;
    cin >> T;

    for (int cases = 0; cases < T; cases++) {
        cin >> n;
        vector<caca> c;

        for (int i = 0; i < n; i++) {
            string obj, t, classes;
            cin >> obj >> classes >> t;
            obj = obj.substr(0, obj.size() - 1);

            stringstream ss(classes);
            string clase;
            vector<int> tokens;

            while (getline(ss, clase, '-')) {
                if (clase == "lower")       tokens.push_back(-1);
                else if (clase == "middle") tokens.push_back(0);
                else if (clase == "upper")  tokens.push_back(1);
            }

            vector<int> score;
            for (int j = tokens.size() - 1; j >= 0; j--)
                score.push_back(tokens[j]);

            c.push_back({score, obj});
        }

        sort(c.begin(), c.end(), [](const caca& a, const caca& b) {
            int len = max(a.score.size(), b.score.size());
            for (int i = 0; i < len; i++) {
                int ai = (i < (int)a.score.size()) ? a.score[i] : 0;
                int bi = (i < (int)b.score.size()) ? b.score[i] : 0;
                if (ai != bi) return ai > bi;
            }
            return a.name < b.name;
        });

        for (auto& p : c)
            cout << p.name << "\n";
        cout << "==============================\n";
    }
    return 0;
}