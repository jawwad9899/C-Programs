#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(char bit);
int to_binary(int n);

int main(void)
{
    string msg = get_string("Message: ");
    int msg_length = strlen(msg);

    //  Printing Bulbs on console
    for (int i = 0; i < msg_length; i++)
    {
        char str[200];
        int n = to_binary(msg[i]);
        sprintf(str, "%d", n);
        n = strlen(str);
        // printing leading zeros if string is less than 8 characters
        while (n < 8)
        {
            print_bulb('0');
            n++;
        }
        // calling print_bulb function to convert each individual bit into a bulb
        for (int j = 0; j < n; j++)
        {
            print_bulb(str[j]);
        }
        printf("\n");
    }
}
// function takes a number and converts it into binary and returns it
int to_binary(int n)
{
    int binary = 0,
        base = 1;

    while (n > 0)
    {
        binary += (n % 2) * base;
        n /= 2;
        base *= 10;
    }

    return binary;
}
// function takes a character bit and converts it into a on or off bulb
void print_bulb(char bit)
{
    if (bit == '0')
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == '1')
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
