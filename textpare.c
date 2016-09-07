#include <stdio.h>

#define textA "A.txt"
#define textB "B.txt"


void printall(char text[]);

int main(void)
{
    printf("Compare %s to %s\n", textA, textB);
    printall(textA);
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


