#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <cs50.h>

int count_chars(string str);
int count_words(string str);
int count_sentences(string str);
int compute(string str);

int main(void)
{
    // Get Text Input From User
    string str = get_string("Text: ");
    int grade = compute(str);

    // print grade
    if (grade < 0)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }

    return 0;
}

int count_chars(string str)
{
    int len = strlen(str);
    int letters = 0;

    for (int i = 0; i < len; i++)
    {
        if (!ispunct(str[i]) && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
        {
            letters++;
        }
    }
    return (letters);
}

int count_words(string str)
{
    int len = strlen(str);
    int words = 0;

    for (int i = 0; i < len; i++)
    {
        if (str[i] == ' ')
        {
            words++;
        }
    }
    return (words + 1);
}
int count_sentences(string str)
{
    int len = strlen(str);
    int sentences = 0;
    int i = 0;

    while (i < len)
    {
        if (str[i] == '?' || str[i] == '!' || str[i] == '.')
        {
            sentences++;
        }

        i++;
    }
    return sentences;
}
int compute(string str)
{
    int chars_count = count_chars(str);
    int words_count = count_words(str);
    int sentences_count = count_sentences(str);

    float L = (float)chars_count / (float)words_count * 100;
    float S = (float)sentences_count / (float)words_count * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    index = round(index);

    return index;
}