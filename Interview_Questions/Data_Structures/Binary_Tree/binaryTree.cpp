/* Include Header Files 
 */
#include <stdio.h>
#include <stdlib.h>

/* Pre-processor directives
 */
#define NUM_OPERATIONS  8

/* Structure Proto-types
 */
typedef struct BINARY_TREE
{
    int data;
    struct BINARY_TREE *left;
    struct BINARY_TREE *right;
}BinaryTreeNode;


/* Function Proto-type
 */
void insertNode(BinaryTreeNode **btn, int data);
void printInorderBinaryTree(BinaryTreeNode *btn);
void printPreorderBinaryTree(BinaryTreeNode *btn);
void printPostorderBinaryTree(BinaryTreeNode *btn);


int main()
{
    int data = 0;
    BinaryTreeNode *btn = NULL;

    for (int index = 0; index < NUM_OPERATIONS; index++)
    {
        printf ("Enter the number you want to add in binary tree \n");
        scanf("%d", &data);
    
        insertNode(&btn, data);
    }

    printf("\nPrinting Inorder Binary Tree : \n");
    printInorderBinaryTree(btn);

    printf("\nPrinting Preorder Binary Tree : \n");
    printPreorderBinaryTree(btn);

    printf("\nPrinting Postorder Binary Tree : \n");
    printPostorderBinaryTree(btn);

    printf("\n");
}


void insertNode(BinaryTreeNode **btn, int data)
{
    BinaryTreeNode *tmpBtn;

    if (*btn == NULL)
    {
        tmpBtn = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
        tmpBtn->data = data;
        tmpBtn->left = NULL;
        tmpBtn->right = NULL;

        *btn = tmpBtn;
    }
    else
    {
        if ((*btn)->data > data)
        {
            insertNode((&(*btn)->left), data);
        }
        else
        {
            insertNode((&(*btn)->right), data);
        }     
    }
}

void printInorderBinaryTree(BinaryTreeNode *btn)
{
    if (btn != NULL)
    {
        printInorderBinaryTree(btn->left);

        printf("%d, ", btn->data);

        printInorderBinaryTree(btn->right);
    }
}


void printPreorderBinaryTree(BinaryTreeNode *btn)
{
    if (btn != NULL)
    {
        printf("%d, ", btn->data);
        
        printPreorderBinaryTree(btn->left);

        printPreorderBinaryTree(btn->right);
    }
}


void printPostorderBinaryTree(BinaryTreeNode *btn)
{
    if (btn != NULL)
    {
        printPostorderBinaryTree(btn->left);
        
        printPostorderBinaryTree(btn->right);

        printf("%d, ", btn->data);
    }
}
