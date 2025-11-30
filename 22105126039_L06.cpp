// 6. Write a program to remove left factoring.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string lhs, part1, part2;

    cout << "Enter Non-Terminal (example: A): ";
    cin >> lhs;

    cout << "Enter 1st Production RHS (e.g., aB): ";
    cin >> part1;

    cout << "Enter 2nd Production RHS (e.g., aC): ";
    cin >> part2;

    string commonPrefix = "";
    int len = min(part1.length(), part2.length());

    // Find longest common prefix
    for (int i = 0; i < len; i++) {
        if (part1[i] == part2[i]) {
            commonPrefix += part1[i];
        } else {
            break;
        }
    }

    if (commonPrefix.empty()) {
        cout << "\nNo Left Factoring needed.\n";
        return 0;
    }

    // Remaining parts after removing common prefix
    string rem1 = part1.substr(commonPrefix.length());
    string rem2 = part2.substr(commonPrefix.length());

    if (rem1.empty()) rem1 = "e";
    if (rem2.empty()) rem2 = "e";

    // Output result
    cout << "\nGrammar After Left Factoring:\n";
    cout << lhs << " -> " << commonPrefix << lhs << "'\n";
    cout << lhs << "' -> " << rem1 << " | " << rem2 << "\n";

    return 0;
}
