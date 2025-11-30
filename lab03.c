/*
Lab: 03    
Date: 12/09/2025

    Q. 3. Write a program to check the given grammar is left-recursive or not if found then remove it.

    Q. 4. Write a program to check the given Grammar is left-factoring or not if found then remove it.

*/

#include <stdio.h>
#include <string.h>

int countLen(char str[])
{
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            length++;
        }
    }
    return length;
}

int countCap(char str[])
{
    int cap = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            cap++;
        }
    }
    return cap;
}

int checkCFG(char strL[], char strR[])
{
    int noVL = countCap(strL);
    if (noVL == 1 && countLen(strL) == 1)
        return 1;
    else
        return 0;
}

int checkLeft(char str[]){
    if(str[0] >= 'A' && str[0] <= 'Z'){
        return 1;
    }

    return 0;
}


int main(){

    int NoProduction[10][2] = {{0},{0}};
    int j = 0;
    char stringL[100], stringR[100], Temp[100], NewR[100];

    printf("Enter the left part of the production: ");
    scanf("%s", stringL);   

    printf("Enter the right part of the production: ");
    scanf("%s", stringR);   

    printf("\nGiven production: %s -> %s\n", stringL, stringR);
    printf("Length of Left string: %d, Right string: %d\n",
           countLen(stringL), countLen(stringR));

    for(int i = 0, z = 0; stringR[i] != '\0'; i++){
        
        if(stringR[i] == '|'){
            NoProduction[j][0] = i;
            NoProduction[j][1] = checkLeft(Temp);
            j++;
            z = 0;
        }
        else{
            Temp[z++] = stringR[i];

        }

    }

    for(int i = 0; i < j; i++){
        printf("%d ", NoProduction[i][1]);
    }

    int counter = 0;
    for(int i = 0; i < 100; i++){
        NewR ;
    }

    if(checkCFG(stringL, stringR))
        printf("It is a CFG\n");
    else
        printf("Please enter a CFG\n");

    printf("%d",checkLeft(stringR));


    return 0;
}
