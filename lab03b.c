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
            printf("e ");
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


    leftFactoring(lhs, rhs, n);
    
    return 0;
}
