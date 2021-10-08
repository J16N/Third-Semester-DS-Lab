#ifndef STACK_H
#define STACK_H

#ifndef ITEM
#define ITEM int
#endif

#include <stdbool.h>

typedef struct stack_type *Stack;

Stack create(void);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, ITEM i);
ITEM pop(Stack s);

#endif