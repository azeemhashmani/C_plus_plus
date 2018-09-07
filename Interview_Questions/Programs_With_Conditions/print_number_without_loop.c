/* Include Header files
 */
#include <stdio.h>


/* Function Proto-type
 */
void print_data(int index);

int main()
{
    int index = 0;
    print_data(index);

}

void print_data(int index)
{
    if (index <= 100)
    {
        printf("%d \n", index);
        index++;

        print_data(index);
    }
}
