#include <cs50.h>
#include <stdio.h>

//Llama population = x+(x/3)+(x/4)
//1. x => start population
//2. the input must be >= 9
//3. y => Ending population size
//4. counting the year (n)


int main(void)
{
    // TODO: Prompt for start size
    //x must be an integer
    //x must be greater than 8

    // TODO: Prompt for end size
    //y must be an integer
    //y must be greater than x

    // TODO: Calculate number of years until we reach threshold

    // TODO: Print number of years


    int x;
    int y;
    //Prompt the users to enter the right num
    do
    {
        x = get_int("Please enter the Starting population: ");
    }
    while (x < 9);
    do
    {
        y = get_int("Please enter the Ending population: ");
    }
    while (y < x);
    //Determining the Number of Years
    //Starting population of the each new year = x + (x / 3)-(x / 4)

    //Defining what is the number of years
    int years = 0;
    //Update the population until the stipulated ending size is reached
    while (x < y)
    {
        x = x + (x / 3) - (x / 4);
        years++;
    };
    //Print the number of years
    printf("Years: %i", years);
}