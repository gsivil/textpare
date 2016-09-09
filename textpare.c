#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define textA "A.txt"
#define textB "B.txt"


void printall(char text[]);
void printwords(char text[], unsigned int wordbeg, unsigned int wordend);
void longline();
void mywait(double seconds);
void printoneword(char text[], unsigned int wordpos);

int main(void)
{
    srand(time(0));
    printf("Compare %s to %s\n", textA, textB);
    longline();
    unsigned int i = rand()%39000;
    unsigned int j = i+1;
    for (i=0;i<1000;i=i+1)
    {
        printoneword(textA, i);
    };
    putchar('\n');
    longline();
    return 0;
}
void printoneword(char text[], unsigned int wordpos)
{
    printwords(text, wordpos, wordpos+1);
    mywait(0.01);
}
void mywait(double seconds)
{
    fflush(stdout);
    usleep(1000000*seconds);
};
void longline()
{
    for (int i =10;i<80;i++)
    {
        printf("_");
    };
    printf("\n");
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
        if(!isalnum(nextchar) && (!isspace(nextchar)) && (!ispunct(nextchar)))
        {
            nextchar = getc(fp);
        };
        if((isalnum(nextchar) || (ispunct(nextchar)))&& (!isspace(nextchar)))
        {
            if ((curwordpos<wordend) && (curwordpos>=wordbeg))
                putchar(nextchar);    
            nextchar = getc(fp);
        }
        if ((isspace(nextchar)) && (tempspace <1))
        {
            if (nextchar == 13)
                nextchar = getc(fp);
            curwordpos = curwordpos+1;
            if ((curwordpos<wordend) && (curwordpos>=wordbeg))
                putchar(nextchar);
            nextchar = getc(fp);
            while(isspace(nextchar))
            {
                nextchar = getc(fp);
                tempspace = tempspace+1;
            };
        };
        tempspace = 0;
        if (curwordpos >= wordend)
            break;
        };
}

