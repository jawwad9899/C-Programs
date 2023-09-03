#include <cs50.h>
#include <stdio.h>
#include <math.h>


int main(void)
{


    long long int nbr, copied;
    nbr = get_long("Number: ");
    if ((log10(nbr) + 1) < 13)
    {
        printf("INVALID\n");
        return 0;
    }

    copied = nbr;

    int sum1 = 0,
        sum2 = 0;
    int is_second = 0;

    while (nbr > 0)
    {

        int sec = (nbr % 10);
        if (is_second)
        {
            if (sec * 2 > 10)
            {
                sum1 += ((sec * 2) - 9);
            }
            else
            {
                sum1 += sec * 2;
            }
        }
        else
        {
            sum2 += sec;
        }
        is_second = !is_second;
        nbr /= 10;
    }

    int result = (sum1 + sum2);

    if (((copied >= 4e12 && copied < 5e12) || (copied >= 4e15 && copied < 5e15)) && (result % 10 == 0))
    {
        printf("VISA\n");
    }
    else if ((copied >= 34e13 && copied < 35e13) || (copied >= 37e13 && copied < 38e13))
    {
        printf("AMEX\n");
    }
    else if (copied >= 51e14 && copied < 56e14)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

