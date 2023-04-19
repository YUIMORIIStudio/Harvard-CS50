#include <cs50.h>
#include <stdio.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
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
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
   /*This function keeps track of all the preferences
1. If at any point, the ballot is deemed to be invalid, the program exits
2. The function takes arguments voter, rank, and name
3. For each valid vote, we need to **update the Global preferences array to indicate that the voter has that candidate as their rank preference** (where 0 is the first preference, 1 is the second preference, etc.)
4. If the preference is successfully recorded, the function should return true; the function should return false, otherwise (if, for instance, name is not the name of one of the candidates).
5. preferences[i][j] stores the index of the candidate who is the ith ranked preference for the ith voter*/
bool vote(int voter, int rank, string name)
{
    //loop through each candidate and compare it with the names that the voter keyed in
    for(int i=0; i< candidate_count; i++)
    {
        //if it matches(strcmp), we update the global preferences array(*ie. keep track of each voter`s preferences)
        if(strcmp(candidate[i].name, name)==0){
            preferences[voter][rank]=i;
            return true;
        }
        return false;
    }
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
//loop through each vote that was made to add it to the candidate`s total counts
  for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
             
            if (!candidates[preferences[i][j]].eliminated)
            {
                candidates[preferences[i][j]].votes++;
                break;
            }
        }
    }
    return;
}

/* Print the winner of the election, if there is one
 - If any candidate has more than half of the total votes, their name should be printed and the function should return true. If nobody has won the election yet, the function should return false */
/*With vote, we tracked the preferences of each voter
- With tabulate, we counted each of candidate's total vote count
- Now that we know each candidate's score, we just need to tell the system the qualifying criteria to win the election, and print the candidate's name
- We just need to loop through each candidate's total score and if it is more than half the total vote count, we will print their name
-- If there are 4 voters, a candidate with more than 2 votes will win
-- -If there are 7 voters. a candidate with more than 3 votes will win*/
bool print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > voter_count / 2)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
    int min = voter_count;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes < min && !candidates[i].eliminated)
        {
            min = candidates[i].votes;
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes != min && !candidates[i].eliminated)
        {
            return false;
        }
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min && !candidates[i].eliminated)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
