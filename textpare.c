#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <locale.h>

#define textA "A.txt"
#define textB "B.txt"
#define maxsize 8000000

void printall(char text[]);
void printwords(char outstring[], char text[], unsigned int wordbeg, unsigned int wordend);
void longline();
void mywait(double seconds);
void printoneword(char outstring[], char text[], unsigned int wordpos);
int diffword(char outstring[], const char teststring[]);

int main(void)
{
    setlocale(LC_ALL, "");
    srand(time(0));
    printf("Compare %s to %s\n", textA, textB);
    longline();
    char outstring[maxsize];
    unsigned int i = 0; 
    putchar('\n');
    longline();
    longline();
   // printf("%s", outstring);
    i  = 0;
    unsigned int appear = 0;
    char teststring[] = "will";
    printwords(outstring, textA, 0, maxsize);
//    for (int i=0;i<18000;i++)
 //       printf("%d %lc\n", i, i);
     putchar('\n');
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
    long long int i = 0;
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
//                putchar(nextchar);    
                    putchar(32);
                outstring[index++] = nextchar;
            }

            nextchar = getc(fp);
        }
        if ((isspace(nextchar)) && (tempspace <1))
        {
            if (nextchar == 13)
            {
                nextchar = getc(fp);
            };
            curwordpos = curwordpos+1;
            if ((curwordpos<wordend) && (curwordpos>=wordbeg))
            {
               // putchar(nextchar);
                if (nextchar == ' ')
                    printf("%lc",'.');
                if (nextchar == '\n')
                    putwchar('\n');
            };
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

