
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

//Point assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score (string);

int main (void)
{
    //Get input from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    //Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    //TODO : Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins.!");
    }

    else if (score2 > score1)
    {
        printf("Player 2 Wins.!");
    }

    else
    {
        printf("Tie!");
    }
}

int compute_score(string word)
{
    //TODO : Compute and return score for string

int score = 0;

for (int i = 0; i < strlen(word); i++)
{
    if (isupper(word[i]))
    {
        score = score + POINTS[word[i] - 65];
    }

    if (islower(word[i]))
    {
        score = score + POINTS[word[i] - 97];
    }
}
return score;
}