#define ITEM char
#define IS_NUM(c) ( (c) >= '0' && (c) <= '9' )
#define IS_ALPHA(c) ( ((c) >= 'a' && (c) <= 'z') || ((c) >= 'A' && (c) <= 'Z') )

#include <stdio.h>
#include "../../custom_headers/stack.h"

int precedence(ITEM);

int main(void)
{
    printf("\n---------- INFIX TO POSTFIX ----------\n");
    printf("--------------------------------------\n");

    int c, i = 0;
    Stack s = create();
    printf("Enter an infix expression: ");
    while ((c = getchar()) != '\n' && c != EOF) {
        if (!i) {
            printf("Postfix Expression: ");
            i++;
        }
        
        if ( IS_NUM(c) || IS_ALPHA(c) )
            putchar(c);

        switch (c) {
            case '(':
                push(s, c);
                break;

            case ')':
            {
                ITEM item;
                while ((item = pop(s)) != '(') {
                    putchar(' ');
                    putchar(item);
                }
                break;
            }

            case '+': case '-':
            case '*': case '/':
            case '^':
            {
                while ( !is_empty(s) && 
                        peek(s) != '(' &&
                        precedence(c) <= precedence( peek(s) ) )
                {
                    putchar(' ');
                    putchar( pop(s) );
                }
                
                putchar(' ');
                push(s, c);
                break;
            }
        }
    }

    while ( !is_empty(s) ) {
        putchar(' ');
        putchar( pop(s) );
    }

    putchar('\n');
    destroy(s);
    return 0;
}

int precedence(ITEM c)
{
    int operators[] = {
        [0] = 2, [1] = 1,
        [3] = 1, [4] = 3,
        [5] = 2
    };

    return operators[c % 42 % 6];
}