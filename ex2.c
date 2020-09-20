#include <stdio.h>

int main()
{
    // Variables definition for menu:
    int menu_choice, is_exit = 0;
    // Variables Definition for Part 1:
    int number1, number2, result;
    char operation;
    // Variables Definition for Part 2:
    int perfect_posi_number, divisors_sum;
    // Variables Definition for Part 3:
    int boom7_posi_number, i, temp, is_first;

    // Checks if the loop should be execute.
    while (!is_exit)
    {
        // Gets a choice for menu.
        printf("Choose an option\n");
        scanf("%d", &menu_choice); // Gets the user choice.
        // Switch-case for menu.
        switch (menu_choice)
        {
            // Checks if the user entered option 1 - Calculator.
            case 1:
                /*
                Part 1: Gets two (int) numbers and an operator
                and prints the operation's result.
                */
                printf("Please enter two numbers\n");
                scanf("%d %d", &number1, &number2); // Gets two numbers from the user.
                printf("Please enter operation\n");
                scanf(" %c", &operation); // Gets an operator from the user.
                // If-structure to determine and calculate the operation.
                if (operation == '/') // Checks if the user choose division.
                    // Checks if the user try to divide by 0.
                    if (number2 == 0)
                    {
                        printf("Error\n");
                        break;
                    }
                    else
                        result = number1 / number2;
                else if (operation == '%') // Checks if the user choose modulo.
                    result = number1 % number2;
                else if (operation == '*') // Checks if the user choose multiplication.
                    result = number1 * number2;
                else if (operation == '+') // Checks if the user choose addition.
                    result = number1 + number2;
                else if (operation == '-') // Checks if the user choose subtraction.
                    result = number1 - number2;
                printf("%d\n", result);
                break;
            // Checks if the user entered option 2 - Perfect++.
            case 2:
                /*
                Part 2: Gets a positive number and
                prints either it Perfect++ or not.
                */
                printf("Please enter a number\n");
                scanf("%d", &perfect_posi_number); // Gets number from the user.
                divisors_sum = 0; // Reset the sum variable to 0.
                // For loop from 1 to the input number divided by 2.
                for (i = 1; i <= perfect_posi_number/2; i++)
                    // Checks if i is a divisor or not.
                    if (perfect_posi_number % i == 0)
                        divisors_sum+=i; // If so, add the divisor to the divisors sum.
                // Checks if the number equals the sum of divisors, or not.
                if (perfect_posi_number == divisors_sum)
                    printf("Perfect++\n");
                else
                    printf("Not perfect++\n");
                break;
                // Checks if the user entered option 3 - 7 Boom.
            case 3:
                /*
                Part 3: Gets a positive number and return all numbers from 1 to
                the number that divisible by 7 or has 7 as a digit.
                */
                printf("Please enter a number for 7 boom game\n");
                scanf("%d", &boom7_posi_number); // Gets number from the user.
                is_first = 1; // Indicates if the divided number is the first in the list or not.
                printf("[");
                // For loop to determine the number divisors.
                for (i = 7; i <= boom7_posi_number; i++)
                {
                    temp = i; // Temporarily holds the divided number.
                    // Checks if the number is divisible by 7.
                    if(i % 7 == 0)
                    {
                        // Checks if the number is the first number found.
                        if (!is_first)
                            printf(",");
                        else
                            is_first = 0; // not the first number anymore.
                        printf("%d", i);
                    }
                    else // If not, it will loop through the digits.
                        // While loop to loop through the number digits.
                        while (temp)
                        {
                            // Checks if the last number equal 7.
                            if (temp % 10 == 7)
                            {
                                // Checks if the number found isn't the first.
                                if (!is_first)
                                    printf(","); // If not the first number, prints a comma.
                                else
                                    is_first = 0; // not the first number anymore.
                                printf("%d", i);
                            }
                            temp/=10; // Divide the number by 10. Get rid of the last digit.
                        }
                }
                printf("]\n");
                break;
            case 4:
                // Part 4: Prints bye and exit the loop.
                printf("Bye\n");
                is_exit = 1; // Change flag variable to "true"-1.
                break;
            default:
                // Prints "Input Error" if the choice is invalid.
                printf("Input error\n");
        }
    }
    return 0;
}
