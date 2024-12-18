//  Program to implement a DFA over {0,1} that accept strings Ends with 01.
#include<stdio.h>
#include<string.h>

char input[20];
int len;
int flag;

void q2(int i) {
    if(input[i]=='\0')
        flag = 1;
}

void q1(int i) {
    if(i < len) {
        if(input[i]=='1') {
            ++i;
            q2(i);		
        }
    }
}

void q0(int i) {
    if(i < len) {
        int k = i;
        if (input[i]=='0') {
            k++;
            q0(k);
            q1(k);
        } else {
            if(input[i]=='1') {
                i++;
                q0(i);
            }
        }
    }
}

int main() {
    printf("\nEnter a string: ");
    gets(input);
    len = strlen(input);
    int i = 0;
    flag = 0;
    q0(i);
    if(flag == 1)
        printf("The string is accepted.\n");
    else
        printf("The string is not accepted.\n");
    return 0;
}
