#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next; 
} NODE;

typedef struct deque_type {
    int size;
    NODE *front;
    NODE *rear;
} *Deque;

Deque create(void);
int get_rear(Deque);
int get_front(Deque);
bool is_empty(Deque);
void delete_end(Deque);
void delete_front(Deque);
void insert_end(Deque, int);
void insert_front(Deque, int);

void overflow(void);
void underflow(void);

void display_size(Deque);
void display_from_rear(Deque);
void display_from_front(Deque);

void destroy(Deque);

int main(void)
{
    printf("\n---------- DEQUE OPERATION ----------\n");
    printf("-------------------------------------\n");

    Deque d = create();
    int choice, data;

    printf("Choose appropriate operation.\n");
    printf("<1> Diplay elements of DEQUE from front.\n");
    printf("<2> Display elements of DEQUE from back.\n");
    printf("<3> Insert element at front of DEQUE.\n");
    printf("<4> Insert element at back of DEQUE.\n");
    printf("<5> Delete element from front of DEQUE.\n");
    printf("<6> Delete element from back of DEQUE.\n");
    printf("<7> Get element from front of DEQUE.\n");
    printf("<8> Get element from back of DEQUE.\n");
    printf("<9> Display size of Deque.\n");
    printf("<0> Exit! \n");

    printf("\nChoice: ");
    while ( scanf("%d", &choice) != EOF && choice != 0 ) {
        switch (choice) {
            case 1:
                display_from_front(d);
                break;

            case 2:
                display_from_rear(d);
                break;

            case 3:
                printf("Enter element to insert at front of DEQUE: ");
                scanf("%d", &data);
                insert_front(d, data);
                break;

            case 4:
                printf("Enter element to insert at back of DEQUE: ");
                scanf("%d", &data);
                insert_end(d, data);
                break;

            case 5:
                delete_front(d);
                break;

            case 6:
                delete_end(d);
                break;

            case 7:
                printf("Element at front of DEQUE: %d\n", get_front(d));
                break;

            case 8:
                printf("Element at back of DEQUE: %d\n", get_rear(d));
                break;

            case 9:
                display_size(d);
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
        printf("\nChoice: ");
    }

    destroy(d);
    return 0;
}

Deque create(void)
{
    Deque d = malloc(sizeof(struct deque_type));
    d->size = 0;
    d->front = NULL;
    d->rear = NULL;
    return d;
}

bool is_empty(Deque d)
{
    return d->front == NULL;
}

int get_front(Deque d)
{
    if (is_empty(d)) {
        underflow();
        return -1;
    }
    return d->front->data;
}

int get_rear(Deque d)
{
    if ( is_empty(d) ) {
        underflow();
        return -1;
    }
    return d->rear->data;
}

void delete_end(Deque d)
{
    if ( is_empty(d) ) {
        underflow();
    }
    NODE *temp = d->rear;
    d->rear = d->rear->prev;
    d->rear->next = NULL;
    d->size--;
    free(temp);
}

void delete_front(Deque d)
{
    if ( is_empty(d) ) {
        underflow();
    }
    NODE *temp = d->front;
    d->front = d->front->next;
    d->front->prev = NULL;
    d->size--;
    free(temp);
}

void insert_end(Deque d, int data)
{
    NODE *temp = malloc( sizeof(NODE) );
    if ( temp == NULL ) {
        overflow();
        return;
    }
    temp->data = data;
    if ( is_empty(d) ) {
        d->front = temp;
        d->rear = temp;
        temp->prev = NULL;
        temp->next = NULL;
    }
    else {
        temp->next = NULL;
        d->rear->next = temp;
        temp->prev = d->rear;
        d->rear = temp;
    }
    d->size++;
}

void insert_front(Deque d, int data)
{
    NODE *temp = malloc( sizeof(NODE) );
    if ( temp == NULL ) {
        overflow();
        return;
    }
    temp->data = data;
    if ( is_empty(d) ) {
        d->front = temp;
        d->rear = temp;
        temp->prev = NULL;
        temp->next = NULL;
    }
    else {
        temp->prev = NULL;
        d->front->prev = temp;
        temp->next = d->front;
        d->front = temp;
    }
    d->size++;
}

void overflow(void)
{
    printf("\n!!! OVERFLOW !!!\n");
}

void underflow(void)
{
    printf("\n!!! UNDERFLOW !!!\n");
}

void display_size(Deque d)
{
    printf("\nSize of DEQUEN is: %d\n", d->size);
}

void display_from_front(Deque d)
{
    printf("\nDeque: ");
    NODE *temp = d->front;
    while ( temp != NULL ) {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void display_from_rear(Deque d)
{
    printf("\nDeque: ");
    NODE *temp = d->rear;
    while ( temp != NULL ) {
        printf("%d, ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void destroy(Deque d)
{
    NODE *temp = d->front;
    while ( temp != NULL ) {
        d->front = d->front->next;
        free(temp);
        temp = d->front;
    }
    free(d);
}