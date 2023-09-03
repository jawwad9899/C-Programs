#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get user name
    string name = get_string("What's your name? ");
    // Display user name with hello on screen
    printf("hello, %s\n", name);

}