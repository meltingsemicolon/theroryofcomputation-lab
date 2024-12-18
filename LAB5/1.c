// Check comments in C
#include<stdio.h>
#include<string.h>

void main() {
    char com[30];
    int len;

    printf("\nEnter Comment: ");
    gets(com);
    len = strlen(com);

    if(com[0] == '/' && com[1] == '/') {
        printf("It is a Single Line Comment");
    } else if(com[0] == '/' && com[1] == '*' && com[len - 1] == '/' && com[len - 2] == '*') {
        printf("It is a Multi Line Comment");
    } else {
        printf("It is not a comment");
    }
}
