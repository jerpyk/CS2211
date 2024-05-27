/*Program Name: converter.c
Program Description: the program provides conversion between different units
when the user provides the value to be converted
Author: Eunsung Kim, 251275156*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    // set variables
    int choice1;
    char choice2;
    float value;
    bool validInput = false;

    // Return to main menu until user quits
    while (1)
    {
        // Prompt the user for an input of a integer number
        printf("What do you want to do?\n");
        printf("1 - Conversion between Kilograms and Pounds\n");
        printf("2 - Conversion between Hectares and Acres\n");
        printf("3 - Conversion between Litres and Gallons\n");
        printf("4 - Conversion betwen Kilomtere and Mile\n");
        printf("5 - Quit\n");

        // loop until a valid input is found
        while (!validInput)
        {
            // get user input
            scanf("%d", &choice1);
            // Switch statement for valid inputs 1,2,3,4,5 and prompting the user
            switch (choice1)
            {
            case 1:
                printf("Enter K for conversion from Kilograms to Pounds.\n");
                printf("Enter P for conversion from Pounds to Kilograms.\n");
                // valid input is set true, and excape the switch statement
                validInput = true;
                break;
            case 2:
                printf("Enter H for conversion from Hectares to Acres.\n");
                printf("Enter A for conversion from Acres to Hectares.\n");
                validInput = true;
                break;
            case 3:
                printf("Enter L for conversion from Litres to Gallons.\n");
                printf("Enter G for conversion from Gallons to Litres.\n");
                validInput = true;
                break;
            case 4:
                printf("K for conversion from Kilometre to Mile.\n");
                printf("M for conversion from Mile to Kilometre.\n");
                validInput = true;
                break;
            case 5:
                exit(0);
            // Every other input are invalid
            default:
                printf("Invalid input. Try again.\n");
            }
        }

        // reset validInput and repeat until valid input is given
        validInput = false;
        while (!validInput)
        {
            // put blank space before %c to skip any white spaces
            scanf(" %c", &choice2);
            if (choice1 == 1)
            {
                // conversion from kilogram to pound
                if (choice2 == 'k' || choice2 == 'K')
                {
                    validInput = true;
                    printf("Please enter a value in kilograms: ");
                    scanf("%f", &value);
                    // print out the conversion
                    printf("\nYour conversion is %f pounds.\n", value * 2.20462);
                    break;
                }
                // conversion from pound to kilogram
                else if (choice2 == 'p' || choice2 == 'P')
                {
                    validInput = true;
                    printf("Please enter a value in pounds: ");
                    scanf("%f", &value);
                    printf("\nYour conversion is %f kilograms.\n", value / 2.20462);
                    break;
                }
            }
            else if (choice1 == 2)
            {
                // conversion from hectare to acre
                if (choice2 == 'h' || choice2 == 'H')
                {
                    validInput = true;
                    printf("Please enter a value in hectares: ");
                    scanf("%f", &value);
                    printf("\nYour conversion is %f acres.\n", value * 2.47105);
                    break;
                }
                // conversion from acre to hectare
                else if (choice2 == 'a' || choice2 == 'A')
                {
                    validInput = true;
                    printf("Please enter a value in acres: ");
                    scanf("%f", &value);
                    printf("\nYour conversion is %f hectares.\n", value / 2.47105);
                    break;
                }
            }
            else if (choice1 == 3)
            {
                // conversion from litre to gallon
                if (choice2 == 'l' || choice2 == 'L')
                {
                    validInput = true;
                    printf("Please enter a value in litres: ");
                    scanf("%f", &value);
                    printf("\nYour conversion is %f gallons.\n", value * 0.264172);
                    break;
                }
                // conversino from gallon to litre
                else if (choice2 == 'g' || choice2 == 'G')
                {
                    validInput = true;
                    printf("Please enter a value in gallons: ");
                    scanf("%f", &value);
                    printf("\nYour conversion is %f litres.\n", value / 0.264172);
                    break;
                }
            }
            else if (choice1 == 4)
            {
                // conversion from kilomtre to mile
                if (choice2 == 'k' || choice2 == 'K')
                {
                    validInput = true;
                    printf("Please enter a value in kilometres: ");
                    scanf("%f", &value);
                    printf("\nYour conversion is %f miles.\n", value * 0.621371);
                    break;
                }
                // conversion from mile to kilometre
                else if (choice2 == 'm' || choice2 == 'M')
                {
                    validInput = true;
                    printf("Please enter a value in miles: ");
                    scanf("%f", &value);
                    printf("\nYour conversion is %f kilometres.\n", value / 0.621371);
                    break;
                }
            }
            // handle invalid input
            printf("Invalid input. Try again.\n");
        }
        printf("\n");
        // reset before returning to main menu
        validInput = false;
    }

    return 0;
}