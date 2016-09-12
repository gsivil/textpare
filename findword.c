#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define textin "A.txt"

void printall(char text[], char* theword);


int main(void)
{
    printall(textin, "oo"); 
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
    printf("%d", wordlen);
    while (nextchar != EOF)
    {
        nextchar = getc(fp);
        checkword = 1;
        i = 0;
        while ((i<wordlen) && (checkword))
        {
            nextchar = getc(fp);
            if (nextchar == theword[i])
            {
                checkword = checkword*1;
                printf("%c", nextchar);
            }
            else
            {
                checkword = 0;
            };
            i = i+1;
        };
        if (checkword)
        {

        //    printf("%s", theword);
/*            for (int i=0;i<15;i++)
            {
                nextchar = getc(fp);
                printf("%c", nextchar);
            };
            putchar(' '); 
            */
            permitnewline = 1;
        }
        else if ((nextchar !='\n') && (permitnewline == 1))
            printf(" ");
        if ((nextchar == '\n') && (permitnewline == 1))
        {
            permitnewline = 0;
            printf("\n");
        };
        permitnewline = 0;
        checkword = 1;
    };
}
