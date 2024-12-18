//  Program to implement a DFA over {0,1} that accept strings contianing even number of 1
#include <stdio.h>

int simulateNFA(char *input) {
    int currentState = 0;
    int i = 0;
    
    while (input[i] != '\0') {
        char inputSymbol = input[i];
        switch (currentState) {
            case 0:
                if (inputSymbol == '0') {
                    currentState = 1;
                }
                break;

            case 1:
                if (inputSymbol == '1') {
                    currentState = 2;
                } else if (inputSymbol == '0') {
                    currentState = 1;
                }
                break;

            case 2:
                break;
        }
        i++;
    }

    if (currentState == 2) {
        printf("String accepted\n");
        return 1;
    } else {
        printf("String rejected\n");
        return 0;
    }
}

int main() {
    char input[100];
    printf("Enter input string: ");
    scanf("%s", input);
    simulateNFA(input);
    return 0;
}
