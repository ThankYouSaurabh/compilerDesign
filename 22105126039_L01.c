/*
    Lab: 01
    Date: 22/08/2025

    Write a program to find the number of characters, digits, special characters, words, space, lines, in a given text data.
*/

#include<stdio.h>
#include<string.h>

int main(){
    int size = 1000;
    char Text[size];

    printf("Enter the text: ");
    fgets(Text, size, stdin);  // Read input string from user

    int count = 0,    // Alphabets
        Wcount = 0,   // Whitespaces
        Dcount = 0,   // Digits
        Scount = 0,   // Special Symbols
        counter = 0;  // Comment character counter

    // Count characters, digits, special characters, words, spaces
    for(int i = 0; i < size; i++){
        char element = Text[i];

        if(element == '\0'){
            break;
        }

        if((element >= 'A' && element <= 'Z') || (element >= 'a' && element <= 'z')){
            count += 1;
        }
        else if(element >= '0' && element <= '9'){
            Dcount += 1;
        }
        else if(element == ' '){
            Wcount += 1;
        }
        else if((element >= 33 && element <= 47) || (element >= 58 && element <= 64) || (element >= 91 && element <= 96) || (element >= 123 && element <= 126)){
            Scount += 1;
        }
    }

    // Count number of characters in the comment (between /* and */)
    for(int i = 0; i < size; i++){
        if(Text[i] == '/' && Text[i+1] == '*'){
            int j = i + 2;
            while(1){
                if(Text[j] == '*' && Text[j+1] == '/')
                    break;

                counter += 1;
                j++;
            }
            break;  // Only consider first comment
        }
    }

    printf("\nNumber of Characters = %d\n", count + Wcount + Dcount + Scount);
    printf("Number of Alphabets = %d\n", count);
    printf("White Space = %d\n", Wcount);
    printf("Number of Words = %d\n", Wcount + 1);
    printf("Number of digits = %d\n", Dcount);
    printf("Number of Special Symbols = %d\n", Scount);

    printf("No. of characters in comment = %d\n", counter);

    return 0;
}
