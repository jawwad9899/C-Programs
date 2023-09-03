#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void encrypt(string s, int key);

int main(int argc, string argv[])
{
    int key = atoi(argv[1]);

    string txt = get_string("plaintext: ");
    encrypt(txt, key);
    printf("ciphertext: %s\n", txt);
}

// C[i] = (P[i] + k) % 26
void encrypt(string s, int key)
{
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        if (ispunct(s[i]))
        {
            continue;
        }
        char *p = &s[i];
        *p += key;
    }
}
// 33 to 64 &&91 to 96 &&123 to 126