#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define textA "A.txt"
#define textB "B.txt"


void printall(char text[]);
void printwords(char text[], unsigned int wordbeg, unsigned int wordend);
void longline();

int main(void)
{
    printf("Compare %s to %s\n", textA, textB);
    printall(textA);
    longline();
    unsigned int i = 0;
    unsigned int j = 100;
    printwords(textA, i, j);
    longline();
    return 0;
}
void longline()
{
    for (int i =0;i<80;i++)
        printf("_");
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

void printwords(char text[], unsigned int wordbeg, unsigned int wordend)
{
    FILE* fp;
    fp = fopen(text, "r");
    char nextchar = getc(fp);
    unsigned int curwordpos = 0;
    int tempspace = 0;
    while(nextchar != EOF)
    {
        if(!isalnum(nextchar) && (nextchar != '\n'))
        {
            nextchar = getc(fp);
            if ((curwordpos<=wordend) && (curwordpos>=wordbeg))
                putchar(nextchar);
        };
        if (nextchar == '\n')
            nextchar = getc(fp);
        if((nextchar == ',') && (nextchar == '.'))
        {
            if ((curwordpos<=wordend) && (curwordpos>=wordbeg))
                putchar(nextchar);
            nextchar = getc(fp);
        }
        if(isalnum(nextchar) && (nextchar != ' '))
        {
            if ((curwordpos<=wordend) && (curwordpos>=wordbeg))
                putchar(nextchar);    
            nextchar = getc(fp);
        }
        if ((isspace(nextchar)) && (tempspace <1))
        {
            curwordpos = curwordpos+1;
            if ((curwordpos<=wordend) && (curwordpos>=wordbeg))
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

