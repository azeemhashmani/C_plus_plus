#include <stdio.h>
#include <stdlib.h>

/* Declaring structure proto-type
 */
typedef struct NODE
{
    int data;
    struct NODE *previous;
}node;

/* Defining structure
 */
node *topData  =  NULL;

/* Global Variables
 */
unsigned int sizeOfStack;

/* Function Proto-type
 */
void push(int data);
void  pop ();
int top();
bool empty();
unsigned int size();

int  main()
{
    int oper;
    int data;
    unsigned int stackSize;

    while(1)
    {
        printf("\nEnter the operation you want to perform : \n");
        printf("1. Push : Push a data in stack : \n");
        printf("2. Pop : Pop the data out of stack \n");
        printf("3. Top : Display data on top of stack \n");
        printf("4. Empty : Check if stack is empty \n");
        printf("5. Size : Current size of stack \n");
        printf("6. Stop : Stop the stack operation \n");    
       
        printf("\n:");    
        scanf("%d", &oper);
        printf("\n");

        if(oper >= 1 || oper <= 6)
        {
            switch (oper)
            {
            case 1:
                    printf("Enter the data you want to push in stack : ");
                    scanf("%d", &data);
                    push(data);
                    break;

            case 2: 
                   pop();
                   break;

            case 3:
                   data = top();
                   if (topData != NULL)
                   {
                       printf("Top of data = %d \n", data); 
                   }
                   break;
            
            case 4:
                  bool isEmpty; 
                  isEmpty = empty();
                  if (isEmpty)
                  {
                      printf("Stack is empty \n");
                  }
                  else
                  {
                      printf("Stack in not empty \n");
                  }
                  break;

            case 5:
                  stackSize = size();
                  printf("Size of stack = %d \n", stackSize);
                  break;

            case 6:
                  return 0;
                  break;

            default:
                  return 0;
                  break;
           }
        }
        else
        {
            printf("Not a valid operation");
            continue;
        }
    }

    return 0;
}

/* Push data in stack
 */
void push(int data)
{
    /* Declaring temporary node to hold address
     */
    node *temp_node = NULL;

    /* Memory allocation
     */
    temp_node = (node*)malloc(sizeof(node));

    /* Storing data
     */
    temp_node->data     = data;

    /* For the first push operation previous node will be NULL
     */
    if (topData == NULL)
    {
        temp_node->previous = NULL;
    }
    /* For next push operation previous node will be top
     */
    else
    {
        temp_node->previous = topData;
    }

    /* top pointer will point to new memory allocation
     */
    topData             = temp_node;
    sizeOfStack++;               
    printf("Pushed data %d in stack \n", data);
}

/* Pop data from stack
 */
void pop()
{
    node* temp_node;
    int   data;

    if (topData != NULL)
    {
        /* Storing previous node address
         */
        temp_node = topData->previous;


        /* Storing data of current node
         */
        data      = topData->data;

        /* Free current node
         */
        free(topData);

        /* top will be pointing to previous node
         */
        topData       = temp_node;

        sizeOfStack--;
        printf("Popped data from stack = %d \n", data);
    }

    /* top is NULL. No more data availabe in stack
     */
    else
    {
        printf("No more data available in stack \n");
    }
}

/* Top of the data in stack
 */
int top()
{
    if (topData != NULL)
    {
        return topData->data;
    }
    else
    {
        printf("No more data available in stack \n");
        return 0;
    }
}


/* Check if stack is empty
 */
bool empty()
{
    if (topData == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}


/* Size of stack 
 */
unsigned int size()
{
    return sizeOfStack;
}
