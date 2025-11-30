// 8. Write a program to check whether a grammar is Operator precedent.
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

// Check if char is non-terminal (uppercase)
bool isNonTerminal(char c) {
    return isupper(c);
}

int main() {
    int n;
    cout << "Enter number of productions: ";
    cin >> n;

    vector<string> lhs(n), rhs(n);

    cout << "Enter productions (Example: E -> E+T):\n";
    for (int i = 0; i < n; i++) {
        string arrow;
        cin >> lhs[i] >> arrow >> rhs[i];
    }

    bool isOPG = true;

    for (int i = 0; i < n; i++) {
        string P = rhs[i];

        // Rule 1: No epsilon allowed
        if (P == "#") {
            cout << "Grammar contains epsilon-production: " 
                 << lhs[i] << " -> " << rhs[i] << endl;
            isOPG = false;
        }

        // Rule 2: No adjacent non-terminals
        for (int j = 0; j < P.length() - 1; j++) {
            if (isNonTerminal(P[j]) && isNonTerminal(P[j + 1])) {
                cout << "Adjacent non-terminals found in: "
                     << lhs[i] << " -> " << rhs[i] << endl;
                isOPG = false;
            }
        }
    }

    if (isOPG)
        cout << "\nGrammar IS an Operator Precedence Grammar.\n";
    else
        cout << "\nGrammar is NOT an Operator Precedence Grammar.\n";

    return 0;
}
