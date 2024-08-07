#include<cs50.h>
#include <stdio.h>
#include<string.h>

//max voters and candioates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

//preference[i][j] is jth candidate for voters i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

//Candidates have name, vote count, elimation statis
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

//Array of candidtaes
candidate candidates[MAX_CANDIDATES];

//Number of voters and camndidatesa
int voter_count;
int candidate_count;

//Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate (int min);

int main(int argc, string argv[])
{
    //Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [ candidate ...]\n");
        return 1;
    }

    //Populate array of candidate
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
   if (voter_count > MAX_VOTERS)
   {
     printf("Maximum number of voters is %i\n", MAX_VOTERS);
     return 3;
   }

   // Keep querying for votes
   for (int i = 0; i < voter_count; i++)
   {

    // Query for each rank
    for(int j = 0; j < candidate_count; j++ )
    {
        string name = get_string("Rank %i: ", j + 1);
        if (!vote(i, j, name))
      {
        printf("Invalid vote. \n");
        return 4;
      }
    }

    printf("\n");
   }

   // Keep holding runoffs until winner exists
    while (true)
  {
    //Calculate votes ghiven remaining candidates
    tabulate();

    //Check if election has been won
    bool won = print_winner();
    if (won)
    {
        break;
    }

    //Eliminate last-place candidates
    int min = find_min();
    bool tie = is_tie(min);

    //If tie, everyone wins
    if(tie)
    {
        for (int i = 0; i < candidate_count; i++)
        {
            if(!candidates[i].eliminated)
            {
                printf("%s\n", candidates[i].name);
            }
        }
        break;
    }

    //Elimainate antyone with minimum number of  votes
    eliminate(min);

    //Reset votes count back to zero
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].votes = 0;
    }
  }
   return 0;
}

//Record preference if vote is valid
bool vote (int voter, int rank, string name)
{
    //TODO
    for(int i = 0; i < candidate_count; i++)
    {
        if(strcmp(name, candidates[i].name) == 0)
        {
            preferences[voter][rank] = i;
            //printf(TRUE: %s was found at %i", candidate[i].name, i);
            return true;
        }
    }
    return false;
}

//Tabulate voters fopr non-eliminated candidates
void tabulate(void)
{
    //TODO
    int j = 0;
   for(int i = 0; i < voter_count; i++)
    {
        if(candidates[preferences[i][j]].eliminated == false)
    {
    candidates[preferences[i][j]].votes++;
    }
    else
    {
        while (j< candidate_count)
        {
            j++;
            if (candidates[preferences[i][j]].eliminated == false)
            {
                candidates[preferences[i][j]].votes++;
                break;
            }
        }
        j = 0;
    }
    }
    return;
}

//Print the winner of the election, if there is one
bool print_winner(void)
{
    //TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes > voter_count / 2)
        {
        printf("%s\n", candidates[i].name);
        return true;
        }
        }
        return false;
    }

//Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    //TODO
    int minimum = voter_count;
    for (int i = 0; i< candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes < minimum)
        {
            minimum = candidates[i].votes;
        }
    }
    return minimum;
}

//Return true if election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    //TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes !=min)
        {
            return false;
        }
    }
    return true;
}

//Eliminate the candidate ( or candidates) in last place
void eliminate (int min)
{
    //TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}