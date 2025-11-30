// 3. Write a program to check productions is from Regular Grammer or CFG or CSG.

#include <iostream>
#include <string>
using namespace std;

// Check if a character is terminal (lowercase)
bool isTerminal(char c) {
    return (c >= 'a' && c <= 'z');
}

// Check if a character is non-terminal (uppercase)
bool isNonTerminal(char c) {
    return (c >= 'A' && c <= 'Z');
}

int main() {
    string lhs, arrow, rhs;
    
    cout << "Enter production (example: S -> aA): ";
    cin >> lhs >> arrow >> rhs;

    // ------------ REGULAR GRAMMAR CHECK ------------
    bool isRG = false;

    if (lhs.size() == 1 && isNonTerminal(lhs[0])) {
        // A → ε
        if (rhs == "#")
            isRG = true;
        // A → a or A → aB
        else if (rhs.size() == 1 && isTerminal(rhs[0]))
            isRG = true;
        else if (rhs.size() == 2 && isTerminal(rhs[0]) && isNonTerminal(rhs[1]))
            isRG = true;
    }

    if (isRG) {
        cout << "This production is from: Regular Grammar (Type-3)\n";
        return 0;
    }

    // ------------ CONTEXT-FREE GRAMMAR CHECK ------------
    bool isCFG = false;

    // LHS must be a single non-terminal
    if (lhs.size() == 1 && isNonTerminal(lhs[0])) {
        isCFG = true;
    }

    if (isCFG) {
        cout << "This production is from: Context-Free Grammar (Type-2)\n";
        return 0;
    }

    // ------------ CONTEXT-SENSITIVE GRAMMAR CHECK ------------
    bool isCSG = false;

    // RHS must not be shorter (except S -> ε case)
    if (rhs != "#" && rhs.size() >= lhs.size()) {
        isCSG = true;
    }

    if (isCSG) {
        cout << "This production is from: Context-Sensitive Grammar (Type-1)\n";
        return 0;
    }

    // ------------ OTHERWISE Type-0 Grammar ------------
    cout << "This production is from: Type-0 Unrestricted Grammar\n";

    return 0;
}
