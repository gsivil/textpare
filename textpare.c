#include <stdio.h>
#include <ctype.h>

#define textA "A.txt"
#define textB "B.txt"


void printall(char text[]);
void printword(char text[], unsigned int wordpos);

int main(void)
{
    printf("Compare %s to %s\n", textA, textB);
    printall(textA);
    for (unsigned int i = 0; i<200; i++)
    {
        printword(textA, i);
        putchar('\n');
    };
    return 0;
}

void printall(char text[])
{
    FILE* fp;
    fp = fopen(text, "r");
    char nextchar = getc(fp);
    while(nextchar != EOF)
    {
        putchar(nextchar);
        nextchar = getc(fp);
    };
    fclose(fp);
}

void printword(char text[], unsigned int wordpos)
{
    FILE* fp;
    fp = fopen(text, "r");
    char nextchar = getc(fp);
    unsigned int curwordpos = 0;
    while((nextchar != EOF) && (curwordpos<wordpos))
    {
        if(isalpha(nextchar))
        {
            putchar(nextchar);    
        }
        if (nextchar == ' ')
        {
            curwordpos = curwordpos+1;
            putchar(nextchar);
        };
        nextchar = getc(fp);
    }
}

