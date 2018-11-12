/* Include Header files
 */
#include <stdio.h>


/* Function Proto-type
 */
void printData(int index);

int main()
{
    int index = 0;
    printData(index);

}

/* Recursively call this function
 */
void printData(int index)
{
    if (index <= 10)
    {
        printf("%d \n", index);
        index++;

        printData(index);
    }
}
