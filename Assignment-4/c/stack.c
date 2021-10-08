#include <stdio.h>
#include <stdlib.h>
#include "./stack.h"

typedef struct node {
    ITEM data;
    struct node *next;
} NODE;

struct stack_type {
    NODE *top;
};

static void terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack create(void)
{
    Stack s = malloc(sizeof(struct stack_type));
    s->top = NULL;
    return s;
}

void destroy(Stack s)
{
    make_empty(s);
    free(s);
}

void make_empty(Stack s)
{
    while (!is_empty(s))
        pop(s);
}

bool is_empty(Stack s)
{
    return s->top == NULL;
}

bool is_full(Stack s)
{
    return false;
}

void push(Stack s, ITEM data)
{
    NODE *new_node = malloc(sizeof(NODE));
    if (new_node == NULL)
        terminate("Error: Stack Overflow!");

    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}

ITEM pop(Stack s)
{
    if (is_empty(s))
        terminate("Error: Stack Underflow!");

    NODE *temp = s->top;
    ITEM data = temp->data;
    s->top = temp->next;
    free(temp);
    return data;
}