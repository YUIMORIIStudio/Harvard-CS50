#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Declare a variable, the purpose is to store the integer entered by the keyboard.
    int number;
    //If the value input by the user is out of scope, then use do-while loop
    do
    {
        number = get_int("PLEASE INSERT THE NUMBER YOU WANT BETWEEN 1 TO 8:");
    }
    while (number > 8 || number <= 0);
    //create a nested for loop, with the outer layer representing rows and the inner layer representing columns
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            //When the value of i+j < number -1, print a space
            if (i + j < number - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        //move to the next round
        printf("\n");
    }
}