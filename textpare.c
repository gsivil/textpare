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
    for (unsigned int i = 0; i<24; i++)
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
    int tempspace = 0;
    while((nextchar != EOF) && (curwordpos<=wordpos))
    {
        if(!isalpha(nextchar) && (nextchar != '\n'))
        {
            nextchar = getc(fp);
            putchar(nextchar);
        };
        if (nextchar == '\n')
            nextchar = getc(fp);
        if(nextchar == ',')
        {
            putchar(nextchar);
            nextchar = getc(fp);
        }
        if(isalpha(nextchar) && (nextchar != ' '))
        {
            putchar(nextchar);    
            nextchar = getc(fp);
        }
        if ((nextchar == ' ') && (tempspace <1))
        {
            curwordpos = curwordpos+1;
            putchar(nextchar);
            nextchar = getc(fp);
            while(nextchar == ' ')
            {
                nextchar = getc(fp);
                tempspace = tempspace+1;
            };
            tempspace = 0;
        };
    }
}

