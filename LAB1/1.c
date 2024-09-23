// wap to find the prefix sufix ans the substring from the given string.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void prefix(char str[])
{
    int len = strlen(str);
    printf("Prefixes of the string:\n");
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%c", str[j]);
        }
        printf("\n");
    }
}

void suffix(char str[])
{
    int len = strlen(str);
    printf("Suffixes of the string:\n");
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            printf("%c", str[j]);
        }
        printf("\n");
    }
}

void substrings(char str[])
{
    int len = strlen(str);
    printf("Substrings of the string:\n");
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            for (int k = i; k <= j; k++)
            {
                printf("%c", str[k]);
            }
            printf("\n");
        }
    }
}

int main()
{
    char String[MAX_LENGTH];

    printf("Enter the given string: ");
    fgets(String, sizeof(String), stdin);
    String[strcspn(String, "\n")] = '\0'; // Remove newline character from fgets input

    char choice = '0';

    printf("Select an operation:\n");
    printf("1. Prefix\n");
    printf("2. Suffix\n");
    printf("3. Substring\n");
    printf("4. Exit\n");

    while (choice != '4')
    {
        printf("Enter your choice: ");
        scanf(" %c", &choice); // Note the space before %c to consume any leading whitespace

        switch (choice)
        {
        case '1':
            prefix(String);
            break;
        case '2':
            suffix(String);
            break;
        case '3':
            substrings(String);
            break;
        case '4':
            printf("Exiting the program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please enter again.\n");
            break;
        }
    }

    return 0;
}
