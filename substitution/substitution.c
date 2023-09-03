#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int get_char_pos(char c);
int contains_punctuation(const char *str);
int has_duplicate_chars(const char *str);

int main(int argc, string argv[])
{

    if ((argc == 1) || (argc > 2))
    {
        printf("Usage: ./substitution key.\n");
        return 1;
    }
    int key_length = strlen(argv[1]);
    if (key_length < 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    if (contains_punctuation(argv[1]))
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }

    if (has_duplicate_chars(argv[1]))
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }

    string txt = get_string("plaintext: ");

    int txt_len = strlen(txt);

    for (int k = 0; k < txt_len; k++)
    {
        int letter_pos = get_char_pos(txt[k]);
        if (letter_pos == -1)
        {
            continue;
        }

        char char_of_key = argv[1][letter_pos];

        if (islower(txt[k]))
        {
            txt[k] = tolower(char_of_key);
        }
        else
        {
            txt[k] = toupper(char_of_key);
        }
        // printf("%c", tolower(char_of_key));
    }
    printf("ciphertext: %s\n", txt);

    return 0;
}

int get_char_pos(char c)
{
    for (int i = 0, j = 'a', k = 'A'; i < 26; i++, j++, k++)
    {
        if (c == j || c == k)
        {
            return i;
        }
    }
    return -1;
}

int has_duplicate_chars(const char *str)
{
    int len = strlen(str);
    int i, j;

    for (i = 0; i < len - 1; i++)
    {
        for (j = i + 1; j < len; j++)
        {
            if (str[i] == str[j])
            {
                return 1; // Found duplicate character
            }
        }
    }

    return 0; // No duplicate character found
}
int contains_punctuation(const char *str)
{
    while (*str)
    {
        if (ispunct(*str) || isdigit(*str))
        {
            return 1; // Found punctuation character
        }
        str++;
    }
    return 0; // No punctuation character found
}