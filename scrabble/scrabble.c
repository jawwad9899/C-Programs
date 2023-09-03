#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Declarations Of Functions!
int compute_score(string word);
int get_point(char c);
void winner(int score1, int score2);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    winner(score1,score2);
}
// Function That Computes Score And Returns It!
int compute_score(string word)
{
    int points = 0;
    int len = strlen(word);
    for (int i = 0; i < len; i++)
    {
        points += get_point(word[i]);
    }
    return points;
}
// Function That Declares The Winner!
void winner(int score1, int score2)
{
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
// Function That Returns The Point For The Corresponding Character
int get_point(char c)
{
    c = tolower(c);
    int start_char = 97;
    int length = 26;
    for (int i = 0, j = start_char; j < (start_char + length); i++, j++)
    {
        if (j == c)
        {
            return POINTS[i];
        }
    }
    return 0;
}