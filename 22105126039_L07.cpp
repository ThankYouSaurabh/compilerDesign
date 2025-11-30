#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

map<char, vector<string>> grammar;
map<char, set<char>> firstSets;
map<char, set<char>> followSets;
vector<char> nonTerminals;

bool isTerminal(char c) {
    return !isupper(c) && c != '#';
}

// ---------------- FIRST -----------------
void computeFirst(char nonTerm) {
    if (!firstSets[nonTerm].empty()) return;

    for (const string& prod : grammar[nonTerm]) {
        if (prod == "#") {
            firstSets[nonTerm].insert('#');
            continue;
        }

        bool allEps = true;
        for (char symbol : prod) {
            if (isTerminal(symbol)) {
                firstSets[nonTerm].insert(symbol);
                allEps = false;
                break;
            } else {
                computeFirst(symbol);
                bool hasEps = false;
                for (char f : firstSets[symbol]) {
                    if (f != '#') firstSets[nonTerm].insert(f);
                    else hasEps = true;
                }
                if (!hasEps) {
                    allEps = false;
                    break;
                }
            }
        }
        if (allEps) firstSets[nonTerm].insert('#');
    }
}

// ---------------- FOLLOW -----------------
void computeFollow(char startSym) {

    followSets[startSym].insert('$');  // add end marker to start symbol

    bool changed = true;
    while (changed) {
        changed = false;

        for (map<char, vector<string>>::const_iterator it = grammar.begin();
             it != grammar.end(); ++it) {

            char lhs = it->first;
            const vector<string>& productions = it->second;

            for (const string& prod : productions) {

                set<char> trailer = followSets[lhs];

                for (int i = prod.length() - 1; i >= 0; i--) {
                    char symbol = prod[i];

                    if (!isTerminal(symbol)) {  // Non-terminal
                        int before = followSets[symbol].size();
                        followSets[symbol].insert(trailer.begin(), trailer.end());
                        if (followSets[symbol].size() > before) changed = true;

                        // If FIRST(symbol) contains epsilon, expand trailer
                        if (firstSets[symbol].count('#')) {
                            for (char f : firstSets[symbol]) {
                                if (f != '#') trailer.insert(f);
                            }
                        } else {
                            trailer = firstSets[symbol];
                        }
                    } 
                    else { // terminal
                        trailer.clear();
                        trailer.insert(symbol);
                    }
                }
            }
        }
    }
}

// ---------------- MAIN -----------------
int main() {
    int n;
    cout << "Enter number of rules: ";
    cin >> n;
    cout << "Enter rules (format: S -> AB or A -> # for epsilon):\n";

    char startSym = '\0';

    for (int i = 0; i < n; i++) {
        string s, arrow, rhs;
        cin >> s >> arrow >> rhs;
        grammar[s[0]].push_back(rhs);

        if (find(nonTerminals.begin(), nonTerminals.end(), s[0]) == nonTerminals.end())
            nonTerminals.push_back(s[0]);

        if (i == 0) startSym = s[0];
    }

    for (char nt : nonTerminals) computeFirst(nt);
    computeFollow(startSym);

    cout << "\nFIRST sets:\n";
    for (char nt : nonTerminals) {
        cout << nt << ": { ";
        for (char c : firstSets[nt]) cout << c << " ";
        cout << "}\n";
    }

    cout << "\nFOLLOW sets:\n";
    for (char nt : nonTerminals) {
        cout << nt << ": { ";
        for (char c : followSets[nt]) cout << c << " ";
        cout << "}\n";
    }

    return 0;
}
