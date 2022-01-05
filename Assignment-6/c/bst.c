#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;


typedef struct tree{
    Node *root;
} BST;


BST *initBST(void);
Node *createNode(int);

int insert(BST *, Node *, int);

void printInOrder(Node *);
void printPreOrder(Node *);
void printPostOrder(Node *);
void display(BST *);

void destroyN(Node *);
void destroy(BST *);


int main(void)
{
    printf("-------------------------------------------\n");
    printf("------------ BINARY SEARCH TREE -----------\n");
    printf("-------------------------------------------\n");

    printf("Enter numbers (seperated by spaces): ");

    int c, num = 0;
    BST *bst = initBST();

    do {
        scanf("%d", &num);
        insert(bst, bst->root, num);
    } while ((c = getchar()) != '\n' && c != EOF);

    display(bst);
    destroy(bst);
    return 0;
}


BST *initBST(void)
{
    BST *tree = malloc(sizeof(BST));
    tree->root = NULL;
    return tree;
}


Node *createNode(int data)
{
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}


int insert(BST *tree, Node *node, int data)
{
    if (!tree->root) {
        tree->root = createNode(data);
        return 1;
    }

    if (data == node->data) 
        return -1;

    if (data < node->data) {
        if (node->left)
            return insert(tree, node->left, data);
        
        else {
            node->left = createNode(data);
            return 1;
        }
    }

    if (data > node->data) {
        if (node->right)
            return insert(tree, node->right, data);
        
        else {
            node->right = createNode(data);
            return 1;
        }
    }
}


void display(BST *tree)
{
    printf("\nDifferent Traversals: \n");

    printf("In Order: ");
    printInOrder(tree->root);

    printf("\nPre Order: ");
    printPreOrder(tree->root);

    printf("\nPost Order: ");
    printPostOrder(tree->root);

    printf("\n");
}


void printInOrder(Node *node)
{
    if (node) {
        printInOrder(node->left);
        printf("%d ", node->data);
        printInOrder(node->right);
    }
}


void printPreOrder(Node *node)
{
    if (node) {
        printf("%d ", node->data);
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
}


void printPostOrder(Node *node)
{
    if (node) {
        printPostOrder(node->left);
        printPostOrder(node->right);
        printf("%d ", node->data);
    }
}


void destroy(BST *tree)
{
    if (tree->root)
        destroyN(tree->root);
    
    free(tree);
}

void destroyN(Node *node)
{
    if (node) {
        destroyN(node->left);
        destroyN(node->right);
        free(node);
    }
}