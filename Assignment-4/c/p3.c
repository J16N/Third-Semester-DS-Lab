#define ITEM char

#include <stdio.h>
#include "../../custom_headers/stack.h"

char get_pair(char);

int main(void)
{
    printf("\n---------- EQUAL PARANTHESIS ----------\n");
    printf("---------------------------------------\n");

    int c;
    Stack s = create();
    bool balanced = true;
    printf("Expression: ");
    while ((c = getchar()) != '\n' && c != EOF && balanced) {
        if (c == '(' || c == '{' || c == '[')
            push(s, c);

        if (c == ')' || c == '}' || c == ']') {
            if (is_empty(s))
                balanced = false;
            else {
                ITEM top = pop(s);
                if (get_pair(c) != top)
                    balanced = false;
            }
        }
    }

    printf("%s Parenthesis\n", balanced && is_empty(s) ? "Equal" : "Unqual");
    destroy(s);
    return 0;
}

char get_pair(char c)
{
    int LUT[3] = {'(', '[', '{'};
    return LUT[c % 41 % 10];
}