#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    cout << "Enter number of productions: ";
    cin >> n;

    // Store productions: A -> α | β | ...
    map<string, vector<string>> grammar;

    cout << "Enter productions (e.g., E E+T):\n";
    for (int i = 0; i < n; i++) {
        string L, R;
        cin >> L >> R;
        grammar[L].push_back(R);
    }

    cout << "\nGrammar after removing Left Recursion:\n";

    for (auto &rule : grammar) {
        string A = rule.first;
        vector<string> productions = rule.second;

        vector<string> alpha;
        vector<string> beta;

        // Separate α (left recursive) and β (non-left-recursive)
        for (string &p : productions) {
            if (p[0] == A[0])
                alpha.push_back(p.substr(1));   // Remove A
            else
                beta.push_back(p);
        }

        if (alpha.empty()) {
            // No left recursion
            for (string &b : productions)
                cout << A << " -> " << b << endl;
        } else {
            // Left recursion exists
            string Aprime = A + "'";

            // A → β A'
            for (string &b : beta)
                cout << A << " -> " << b << Aprime << endl;

            // A' → α A' | ε
            for (string &a : alpha)
                cout << Aprime << " -> " << a << Aprime << endl;

            cout << Aprime << " -> epsilon" << endl;
        }
    }

    return 0;
}
