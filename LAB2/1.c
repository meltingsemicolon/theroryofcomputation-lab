// WAP to implement DFA that accepts the strings starting with 01.

#include <stdio.h>
#include <string.h>

// Function to simulate the DFA
int DFA_accepts_01(char *str) {
    int state = 0;  // Start state is q0

    for (int i = 0; i < strlen(str); i++) {
        char current = str[i];

        switch (state) {
        case 0:  // q0 state
            if (current == '0') {
                state = 1;  // Move to q1
            } else {
                state = -1;  // Move to dead state
            }
            break;

        case 1:  // q1 state
            if (current == '1') {
                state = 2;  // Move to q2
            } else {
                state = -1;  // Move to dead state
            }
            break;

        case 2:  // q2 state (accepting state)
            // Once in q2, remain in q2 for any input
            break;

        default:  // Dead state
            return 0;  // Reject the string
        }
    }

    // Accept if the final state is q2
    return state == 2;
}

int main() {
    char input[10];

    printf("Enter a binary string: ");
    scanf("%s", input);

    if (DFA_accepts_01(input)) {
        printf("The string is accepted by the DFA (starts with 01).\n");
    } else {
        printf("The string is rejected by the DFA (does not start with 01).\n");
    }

    return 0;
}
