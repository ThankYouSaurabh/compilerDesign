/*
Lab: 03    
Date: 12/09/2025

    Q. 3. Write a program to check the given grammar is left-recursive or not if found then remove it.

    Q. 4. Write a program to check the given Grammar is left-factoring or not if found then remove it.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int LeftRecursive(char *lhs, char *rhs) {
    if (rhs[0] == lhs[0])
        return 1;
    return 0;
}

void removeLeftRecursion(char *lhs, char rhs[][MAX], int n) {
    char alpha[10][MAX], beta[10][MAX];
    int alphaCount = 0, betaCount = 0;

    for (int i = 0; i < n; i++) {
        if (rhs[i][0] == lhs[0]) {
            strcpy(alpha[alphaCount++], rhs[i] + 1); 
        } else {
            strcpy(beta[betaCount++], rhs[i]);     
        }
    }

    if (alphaCount == 0) {
        printf("No Left Recursion.\n");
        return;
    }

    printf("\nAfter removing left recursion:\n");
    printf("%s -> ", lhs);
    for (int i = 0; i < betaCount; i++) {
        printf("%s%s' ", beta[i], lhs); 
        if (i < betaCount - 1) printf("| ");
    }
    printf("\n");

    printf("%s' -> ", lhs);
    for (int i = 0; i < alphaCount; i++) {
        printf("%s%s' ", alpha[i], lhs); 
        if (i < alphaCount - 1) printf("| ");
    }
    printf("| e\n");
}

int main() {
    char lhs[MAX];
    char rhs[10][MAX];
    int n;
    char ch;

    do
    {
        printf("Enter the left-hand side (Non-terminal): ");
        scanf("%s", lhs);

        printf("Enter the number of productions for %s: ", lhs);
        scanf("%d", &n);

        printf("Enter the productions (separate by spaces):\n");
        for (int i = 0; i < n; i++) {
            scanf("%s", rhs[i]);
        }

        int LeftRec = 0;
        for (int i = 0; i < n; i++) {
            if (LeftRecursive(lhs, rhs[i])) {
                LeftRec = 1;
                break;
            }
        }

        if (LeftRec)
            removeLeftRecursion(lhs, rhs, n);

        printf("Want to check next production (enter Y or y): ");
        scanf(" %c",&ch);
    } while ((ch == 'Y') || (ch == 'y'));
    
    return 0;
}
