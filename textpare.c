#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define textA "A.txt"
#define textB "B.txt"
#define maxsize 1000000

void printall(char text[]);
void printwords(char outstring[], char text[], unsigned int wordbeg, unsigned int wordend);
void longline();
void mywait(double seconds);
void printoneword(char outstring[], char text[], unsigned int wordpos);
int diffword(char outstring[], const char teststring[]);

int main(void)
{
    srand(time(0));
    printf("Compare %s to %s\n", textA, textB);
    longline();
    char outstring[maxsize];
    unsigned int i = 0; 
    printoneword(outstring, textA, i);
    putchar('\n');
    longline();
    longline();
    printf("%s", outstring);
    i  = 0;
    unsigned int appear = 0;
    char teststring[] = "prey";
    while (i<10000)
    {
        printoneword(outstring, textA, i);
        if (diffword(outstring,teststring))
        {
            appear = appear+1;
            printf("\n\t\t\t\t\t\t\t\t\t\t(%d)\n",appear);
            mywait(0.2);
        }
    i = i+1;
    };
    printf("\nThe word %s appears %d times\n", teststring, appear);
    return 0;
}
int diffword(char outstring[], const char teststring[])
{
    int match = 1;
    unsigned int i =0;
    while (i<strlen(teststring))
    {
        if (outstring[i] != teststring[i])
        {
            match =0;
            break;
        };
        i = i+1;
    };
    if (strlen(outstring) != strlen(teststring))  
        match = 0;
    return match;
}
void printoneword(char outstring[], char text[], unsigned int wordpos)
{
    
    printwords(outstring, text, wordpos, wordpos+1);
    //mywait(0.000001);
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

void printwords(char outstring[], char text[], unsigned int wordbeg, unsigned int wordend)
{
    FILE* fp;
    fp = fopen(text, "r");
    char nextchar = getc(fp);
    unsigned int curwordpos = 0;
    unsigned int index = 0;
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
            {
                putchar(nextchar);    
                outstring[index++] = nextchar;
//                strcpy(outstring, &nextchar);
            };
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
    outstring[index] = '\0';
}

