#include <stdio.h>

#define textin "A.txt"

void printall(char text[]);

int main(void)
{
    printall(textin); 
    return 0;
}


void printall(char text[])
{
    FILE* fp;
    fp = fopen(text, "r");
    char nextchar = 'a';
    while (nextchar != EOF)
    {
        nextchar = getc(fp);
        if ((nextchar == 's') || (nextchar == '\n') || (nextchar == 'e') || (nextchar == 'x'))
            printf("%c", nextchar);
        else
            printf(" ");
    };
}
