#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long credit_card_number;
    do
    {
        credit_card_number = get_long("Number: ");
    }
    while (credit_card_number <= 0);

    int total = 0;

    long checknum = credit_card_number;
    //1st case
    while (checknum > 0)
    {
        //Use modulo to get the lastDigit
        int lastDigit = checknum % 10;
        total += lastDigit;
        //Use division in order to remove the final number
        checknum = checknum / 100;
    }

    //2st case
    //Use division in order to remove the final number first
    checknum = credit_card_number / 10;
    while (checknum > 0)
    {
        //use the lastnumber(actually the last second num, do module to get it, then * 2)
        int lastDigit = checknum % 10 * 2;
        //Determine if the number is greater than 10, if it is greater than 10, you need to add the number Ones digit and the number in the Tens digit
        if (lastDigit < 10)
        {
            //if less than 10, add to total directly
            total += lastDigit;
        }
        else
        {
            //if greater than 10, get the last digit by using modulo, then remove the last digit by using divide(10)
            total += lastDigit % 10;
            lastDigit = lastDigit / 10;
            total += lastDigit;
        }
        //remove the number already add to total, and using while loop to deal with the left number again
        checknum /= 100;
    }

    if (total % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        int length = 2;
        while (credit_card_number >= 100)
        {
            credit_card_number /= 10;
            length++;
        }

        if ((credit_card_number == 34 || credit_card_number == 37) && length == 15)
        {
            printf("AMEX\n");
        }
        else if (credit_card_number >= 51 && credit_card_number <= 55 && length == 16)
        {
            printf("MASTERCARD\n");
        }
        else if (credit_card_number >= 40 && credit_card_number <= 49 && (length == 13 || length == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}
