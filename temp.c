#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// Function to check if production is left recursive
int isLeftRecursive(char *lhs, char *rhs) {
    if (rhs[0] == lhs[0])  // e.g., A -> Aα
        return 1;
    return 0;
}

// Remove direct left recursion: A -> Aα | β  =>  A -> βA' ; A' -> αA' | ε
void removeLeftRecursion(char *lhs, char rhs[][MAX], int n) {
    char alpha[10][MAX], beta[10][MAX];
    int alphaCount = 0, betaCount = 0;

    for (int i = 0; i < n; i++) {
        if (rhs[i][0] == lhs[0]) {
            strcpy(alpha[alphaCount++], rhs[i] + 1); // store α
        } else {
            strcpy(beta[betaCount++], rhs[i]);       // store β
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
    printf("| ε\n");
}

// Function to detect left factoring (common prefixes)
void leftFactoring(char *lhs, char rhs[][MAX], int n) {
    char prefix[MAX];
    int i, j, k;

    strcpy(prefix, rhs[0]);
    for (i = 1; i < n; i++) {
        k = 0;
        while (rhs[i][k] && prefix[k] && rhs[i][k] == prefix[k])
            k++;
        prefix[k] = '\0';
    }

    if (strlen(prefix) == 0) {
        printf("No Left Factoring.\n");
        return;
    }

    printf("\nAfter Left Factoring:\n");
    printf("%s -> %s%s'\n", lhs, prefix, lhs);
    printf("%s' -> ", lhs);

    for (i = 0; i < n; i++) {
        if (strlen(rhs[i]) > strlen(prefix))
            printf("%s ", rhs[i] + strlen(prefix));
        else
            printf("ε ");
        if (i < n - 1) printf("| ");
    }
    printf("\n");
}

int main() {
    char lhs[MAX];
    char rhs[10][MAX];
    int n;

    printf("Enter the left-hand side (Non-terminal): ");
    scanf("%s", lhs);

    printf("Enter the number of productions for %s: ", lhs);
    scanf("%d", &n);

    printf("Enter the productions (separated by spaces, no '|'):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", rhs[i]);
    }

    int hasLeftRec = 0;
    for (int i = 0; i < n; i++) {
        if (isLeftRecursive(lhs, rhs[i])) {
            hasLeftRec = 1;
            break;
        }
    }

    if (hasLeftRec)
        removeLeftRecursion(lhs, rhs, n);
    else
        leftFactoring(lhs, rhs, n);

    return 0;
}
