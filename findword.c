#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define textin "A.txt"

void printall(char text[], char* theword);


int main(int argc, char* argv[])
{
    char* theword;
    if (argv[1] == '\0')
        theword = "a";
    else
        theword = argv[1];

    theword = "ing";
        printall(textin, theword); 
    putchar('\n');
    return 0;
}


void printall(char text[], char* theword)
{
    FILE* fp;
    fp = fopen(text, "r");
    char nextchar = 'a';
    int permitnewline = 0;
    int checkword = 1;
    int i = 0;
    int wordlen = strlen(theword);
    int words = 0;
    printf("%d", wordlen);
    while (nextchar != EOF)
    {
        nextchar = getc(fp);
        checkword = 1;
        i = 0;
        while ((i<wordlen) && (checkword) && (nextchar != EOF))
        {
            nextchar = getc(fp);
            if (nextchar == theword[i])
            {
                checkword = checkword*1;
            }
            else
            {
                checkword = 0;
            };
            i = i+1;
        };
        if (checkword)
        {
            words = 0;
            printf("%s", theword);
            for (int i=0;((i<150) && (words<7) && (nextchar != EOF));i++)
            {
                nextchar = getc(fp);
                if (isspace(nextchar))
                    words = words+1;
                printf("%c", nextchar);
            };
            putchar(' '); 
            permitnewline = 1;
        }
        else if ((nextchar !='\n') && (permitnewline == 1))
            printf(" ");
        if ((nextchar == '\n') && (permitnewline == 0))
        {
            permitnewline = 0;
            printf("\n");
        };
        permitnewline = 0;
        checkword = 1;
    };
}
