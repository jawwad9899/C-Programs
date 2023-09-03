#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int n;

    do
    {
        n = get_int("Start Size: ");
    }
    while (n < 9);

    // TODO: Prompt for end size

    int end;
    do
    {
        end = get_int("End Size: ");
    }
    while (end < n);

    // TODO: Calculate number of years until we reach threshold
    int borns, deaths = n / 4, llambas_remain;
    int years = 0;

    while (n < end)
    {
        borns = n / 3;
        deaths = n / 4;
        llambas_remain = n + (borns - deaths);
        n = llambas_remain;
        years++;
    }

    // TODO: Print number of years

    printf("Years: %d\n", years);

}
