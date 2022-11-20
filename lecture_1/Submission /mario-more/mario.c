#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Declare a variable, the purpose is to store the integer entered by the keyboard.
    int number;
    //If the value input by the user is out of scope, then use do-while loop
    do
    {
        number = get_int("PLEASE INSERT THE NUMBER BETWEEN 1 AND 8:\n");
    }
    while (number < 1 || number > 8);

    //create a nested for loop, with the outer layer representing rows and the inner layer representing columns
    for (int i = 0; i < number; i++)
    {
        //print the space for column
        for (int j = 0; j < number - 1 - i; j++)
        {
            printf(" ");
        }
        
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        //print the space between left and right
        printf("  ");
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }

}
