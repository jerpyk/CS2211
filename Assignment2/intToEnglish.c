/* Program Name: intToEnglish.c
Program Description: The program receives an integer value from 1-999
and converts it into the english word for the number
Author: Eunsung Kim, 251275156*/
#include <stdio.h>
#include <stdbool.h>

int main()
{
    // set variables
    int value; 
    // array of strings for digits created with 2D char array (10 elements of 10 char length)
    char tens[10][10] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    char teens[10][10] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char ones[10][10] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    bool hasTeens = false;

    // repeat until user quits
    while (1)
    {
        printf("Please enter a value (1-999, 0 to quit): ");
        // get user input of integer from 1-999
        scanf("%d", &value);
        // check if the user wants to quit
        if (value == 0)
        {
            break;
        }
        printf("You entered the number ");

        // Check if the number has hundreds digit
        if (value >= 100)
        {
            // if so, print the hundreds digit from the ones array
            printf("%s hundred ", ones[value / 100]);
            // remove the hundreds digit by getting the remainder after dividing by 100
            value = value % 100;
        }

        // check if the number has tens digit, excluding the teen numbers
        if (value >= 20)
        {
            // if so, print the tens digit from the tens array
            printf("%s", tens[value / 10]);
            // include the dash if ones digit is not a 0
            if (value % 10 != 0)
            {
                printf("-");
            }
            // remove the tens digit by getting the remainder after dividing by 10
            value = value % 10;
        }
        // check if the number has teens
        else if (value > 10 && value < 20)
        {
            // print the teens by from the teens array
            printf("%s", teens[value % 10]);
            value = value % 10;
            // set teens present to true
            hasTeens = true;
        }
        // check if the number ends with 10
        else if (value == 10)
        {
            printf("ten");
            value = value % 10;
        }
        // Move to ones digit and print only if there is no teen numbers
        if (!hasTeens)
        {
            printf("%s", ones[value]);
        }
        // print blank line
        printf("\n\n");
        // reset variables
        hasTeens = false;
    }
}
