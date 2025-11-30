// 4. Write a program to check whether a string belongs to the grammar or not.

#include <iostream>
#include <string>

using namespace std;

/*
  Grammar:
  S -> aSb
  S -> epsilon
  
  Language: a^n b^n (equal number of a's followed by equal number of b's)
*/

string input;
int pos = 0;

// Function prototype
bool S();

bool S() {
    // Matches 'a' S 'b'
    if (pos < input.length() && input[pos] == 'a') {
        pos++; // consume 'a'
        if (S()) { // check inner S
            if (pos < input.length() && input[pos] == 'b') {
                pos++; // consume 'b'
                return true;
            }
        }
        return false; // Backtracking/Error if b doesn't match a
    }
    // Matches epsilon (base case)
    return true; 
}

int main() {
    cout << "Grammar: S -> aSb | epsilon\n";
    cout << "Enter string to check: ";
    cin >> input;
    
    pos = 0;
    // S() must return true AND we must have consumed the entire string
    if (S() && pos == input.length()) {
        cout << "String is VALID." << endl;
    } else {
        cout << "String is INVALID." << endl;
    }
    
    return 0;
}