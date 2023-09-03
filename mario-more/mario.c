#include <cs50.h>
#include <stdio.h>


void print_blocks_db(int n);

int main(void)
{
    int blocks = 0;
    do
    {
        blocks  = get_int("Height: ");
    }
    while (blocks <= 0 || blocks > 8);

    print_blocks_db(blocks);
}

void print_blocks_db(int n)
{

    if (n == 1)
    {
        printf("#  #\n");
        return;
    }

    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i - 1; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < n - i + 1; j++)
        {
            printf("#");
        }
        // loop for printing 2 spaces between blocks
        for (int j = 0; j < 2; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < n - i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
