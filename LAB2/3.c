// WAP to implement DFA that accepts the string having the substring as 001 oven an alphabet E={0,1}

#include <stdio.h>
#include <string.h>

// Function to simulate the DFA
int DFA_accepts_substring_001(char *str) {
    int state = 0;  // Start state is q0

    for (int i = 0; i < strlen(str); i++) {
        char current = str[i];

        switch (state) {
        case 0:  // q0 state
            if (current == '0') {
                state = 1;  // Move to q1
            }
            // Stay in q0 for '1'
            break;

        case 1:  // q1 state
            if (current == '0') {
                state = 2;  // Move to q2
            } else {
                state = 0;  // Go back to q0 on '1'
            }
            break;

        case 2:  // q2 state
            if (current == '1') {
                state = 3;  // Move to q3 (substring "001" found)
            }
            // Stay in q2 for '0'
            break;

        case 3:  // q3 state (accepting state)
            // Stay in q3 regardless of input, substring "001" found
            return 1;
        }
    }

    // Accept only if the final state is q3
    return state == 3;
}

int main() {
    char input[100];

    printf("Enter a binary string: ");
    scanf("%s", input);

    if (DFA_accepts_substring_001(input)) {
        printf("The string is accepted by the DFA (contains substring 001).\n");
    } else {
        printf("The string is rejected by the DFA (does not contain substring 001).\n");
    }

    return 0;
}
