/*
    Lab: 02
    Date: 29/08/25
    Write a program to check a grammar from given production.
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

int checkRegular(char str1[], char str2[])
{
    int noVL = countCap(str1);
    int noVR = countCap(str2);
    int lenR = countLen(str2);
    int index = -1;

    if (!(noVL == 1 && countLen(str1) == 1))
        return 0;

    if (noVR > 1)
        return 0;

    if (noVR == 0)
    {
        for (int i = 0; str2[i] != '\0'; i++)
        {
            if (!(str2[i] >= 'a' && str2[i] <= 'z'))
                return 0;
        }
        return 1;
    }

    if (noVR == 1)
    {
        for (int i = 0; str2[i] != '\0'; i++)
        {
            if (str2[i] >= 'A' && str2[i] <= 'Z')
            {
                index = i;
                break;
            }
        }

        if (!(index == 0 || index == lenR - 1))
            return 0;

        for (int i = 0; str2[i] != '\0'; i++)
        {
            if (i == index)
                continue;

            if (!(str2[i] >= 'a' && str2[i] <= 'z'))
                return 0;
        }
        return 1;
    }

    return 0;
}

int checkCFG(char str1[], char str2[])
{
    int noVL = countCap(str1);
    if (noVL == 1 && countLen(str1) == 1)
        return 1;
    else
        return 0;
}

int checkCSG(char str1[], char str2[])
{
    int LHSlen = countLen(str1);
    int RHSlen = countLen(str2);

    if (LHSlen >= 1 && RHSlen >= LHSlen)
        return 1;
    else
        return 0;
}

int checkUG(char str1[], char str2[])
{
    int LHSlen = countLen(str1);
    if (LHSlen >= 1)
        return 1;
    else
        return 0;
}

int main()
{
    char stringL[100], stringR[100];

    printf("Enter the left part of the production: ");
    scanf("%99s", stringL);   // Limit input to prevent overflow

    printf("Enter the right part of the production: ");
    scanf("%99s", stringR);   // Limit input to prevent overflow

    printf("\nGiven production: %s -> %s\n", stringL, stringR);
    printf("Length of Left string: %d, Right string: %d\n",
           countLen(stringL), countLen(stringR));

    if (checkRegular(stringL, stringR))
    {
        printf("Regular Grammar\n");
    }
    else if (checkCFG(stringL, stringR))
    {
        printf("Context-Free Grammar\n");
    }
    else if (checkCSG(stringL, stringR))
    {
        printf("Context-Sensitive Grammar\n");
    }
    else if (checkUG(stringL, stringR))
    {
        printf("Unrestricted Grammar\n");
    }
    else
    {
        printf("Invalid Production\n");
    }

    return 0;
}
