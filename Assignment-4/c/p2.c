#define OPERATOR(c) ( (c) == '+' || \
    (c) == '-' || (c) == '*' || \
    (c) == '/' || (c) == '^' )

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../custom_headers/stack.h"

int operand(void);

int main(void)
{
    printf("\n---------- EVALUATE POSTFIX EXPRESSIONS ----------\n");
    printf("--------------------------------------------------\n");

    printf("Please make sure to add spaces between numbers.\n");
    printf("\nPostfix Expression: ");

    int c;
    Stack s = create();
    while ( (c = getc(stdin)) != '\n' ) {
        if (c >= '0' && c <= '9') {
            ungetc(c, stdin);
            ITEM num = operand();
            push(s, num);
        }

        if ( OPERATOR(c) && len(s) <= 1 ) {
            printf("\nError: Invalid postfix expression.\n");
            return EXIT_FAILURE;
        }

        switch(c) {
            
            case '+':
                push(s, pop(s) + pop(s));
                break;
            
            case '-':
            {
                ITEM num = pop(s);
                push(s, pop(s) - num);
                break;
            }
            
            case '*':
                push(s, pop(s) * pop(s));
                break;
            
            case '/':
            {
                ITEM num = pop(s);
                push(s, pop(s) / num);
                break;
            }
            
            case '^':
            {
                ITEM num = pop(s);
                push( s, pow( pop(s), num ) );
                break;
            }

            default:
                break;

        }
    }

    printf("Result: %d\n\n", pop(s));
    destroy(s);
    return 0;
}

int operand(void)
{
    int c, i = 0;
    char *s = NULL;
    while ( (c = getc(stdin)) >= '0' && c <= '9' ) {
        s = realloc(s, sizeof(char) * (i + 1));
        s[i++] = c;
    }
    ungetc(c, stdin);
    s[i] = '\0';
    ITEM num = atoi(s);
    free(s);
    return num;
}