// WAP to implement DFA that accepts all the strings ending with 01.
#include <stdio.h>
#include <string.h>

// Function to simulate the DFA
int DFA_accepts_end_01(char *str) {
    int state = 0;  // Start state is q0

    for (int i = 0; i < strlen(str); i++) {
        char current = str[i];

        switch (state) {
        case 0:  // q0 state
            if (current == '0') {
                state = 1;  // Move to q1
            } else {
                state = 0;  // Stay in q0
            }
            break;

        case 1:  // q1 state
            if (current == '0') {
                state = 1;  // Stay in q1
            } else if (current == '1') {
                state = 2;  // Move to q2 (valid ending "01")
            }
            break;

        case 2:  // q2 state (accepting state)
            if (current == '0') {
                state = 1;  // Move to q1
            } else {
                state = 0;  // Go back to q0
            }
            break;

        default:
            return 0;  // If in a dead state, reject
        }
    }

    // Accept if the final state is q2 (ends with "01")
    return state == 2;
}

int main() {
    char input[100];

    printf("Enter a binary string: ");
    scanf("%s", input);

    if (DFA_accepts_end_01(input)) {
        printf("The string is accepted by the DFA (ends with 01).\n");
    } else {
        printf("The string is rejected by the DFA (does not end with 01).\n");
    }

    return 0;
}
