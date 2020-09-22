#include <stdio.h>

// Function Declaration
void printError();
int getPositiveInput();
// Functions for part 1:
void printHourglass();
// Functions for part 2:
void convertBase();
void rec(int, int);
// Functions for part 3:
void floatingPointNumber();
// Function for part 4:
int Exit();

int main()
{
    // Variable Definition for menu.
    int choice, menu_flag = 1;

    // Do-while loop to loop until the user exits.
    do
    {
        // The user input a number.
        printf("Choose an option\n");
        choice = getPositiveInput(); // Gets a positive number as input.

        // Switch-case for menu.
        switch (choice)
        {
            case 1:
                // Part 1: Printing hourglass.
                printHourglass();
                break;
            case 2:
                // Part 2: Converting base-10 to N-base.
                convertBase();
                break;
            case 3:
                // Part 3: Number with floating point.
                floatingPointNumber();
                break;
            case 4:
                // Part 4: Exit.
                menu_flag = Exit();
                break;
            default:
                printError();
        }
    } while (menu_flag);
    return 0;
}

/*
    The function prints an error message to thescreen.
*/
void printError()
{
    printf("Input error\n");
    return;
}

/*
    The function asks the user for input, and checks
    if the input is valid for parts 1 and 2.
    The function return the number the user inserted if the
    number is valid and -1 if the number is invalid.
    Only positive numbers will be valid.
*/
int getPositiveInput()
{
    int number = 0; // Variable for the returned number.
    int num_flag = 0; // Checks if a number already been logged.
    int true_flag = 1; // Checfs if the function should return number or -1.
    char temp_char; // Temporary variable to hold each char of user input.
    // Do-while loop to loop through user input chars.
    do
    {
        scanf("%c", &temp_char); // Read char from buffer.

        // Checks if the first char entered is Enter. If so, the input is illegal.
        if (temp_char == 10 && !num_flag)
            true_flag = 0;
        // Checks if the char is between 0 to 9 (a digit).
        else if (temp_char >= '0' && temp_char <= '9')
        {
            // If so, add it
            number = number * 10 + (temp_char - '0');
            num_flag = 1;
        }
        else if (temp_char != 10)
            true_flag = 0;
    } while (temp_char != 10);
    if (true_flag)
        return number;
    else
        return -1;
}

/*
    The function asks the user for a positive number and prints hourglass-like structure.
    the number of chars in a row will equal the input number.
*/
void printHourglass()
{
    // Variable Definition for Part 1.
    int positive_number, i, j;
    int sum_l_col, sum_r_col;

    printf("Enter a positive number\n");
    positive_number = getPositiveInput(); // Gets a number from the user.

    sum_l_col = positive_number - 1 - (positive_number - 1) % 2;
    sum_r_col = positive_number - 1;

    // Checks if the number the user insert is negative.
    if (positive_number <= 0)
    {
        // If so, the input is invalid, an error message will print to the screen.
        printError();
        return;
    }
    for (i = 0; i < (positive_number+positive_number%2)-1; i++)
    {
        for (j = 0; j < positive_number; j++)
        {
            if (sum_l_col > i + j && j >= i || sum_l_col == i + j)
                printf("*");
            else if (sum_r_col < i + j && j - i <= (positive_number + 1) % 2)
                printf("*");
            else if(sum_r_col == i + j)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return;
}

// Functions to part 2.

void convertBase()
{
    // Variable Definition for Part 2.
    int base10_number, n_base;

    printf("Please enter a number in base 10\n");
    base10_number = getPositiveInput(); // Gets a positive number from the user in base 10.

    // Checks if the number is negatuve.
    if (base10_number < 0)
    {
        // If so, the input is invalid and an error message will be printed.
        printError();
        return;
    }

    printf("Please enter a base\n");
    n_base  = getPositiveInput(); // Gets a positive number representing the new base.

    // Checks if the base lower than 3 or bigger than 10.
    if (n_base < 2 || n_base > 10)
    {
        // If so, the inserted base is invalid, and an error message will be printed.
        printError();
        return;
    }
    rec(base10_number, n_base); // Call to a recursive function that calculte an prints the converted number.
    printf("\n");
    return;
}

/*
    The function gets as input two integers. a number in base 10 and a number of the new base.
    The function prints the number after conversion to the new base.
*/
void rec(int base10_number, int n_base)
{
    int temp;

    // Checks if the number equal 0.
    if (!base10_number)
        // If so, breaks the recursion.
        return;
    temp = base10_number/n_base; // holds the divided number to send to the next recursion.

    rec(temp, n_base); // Call again to the recursion.

    printf("%d", base10_number % n_base); // After the recursion ends, will prints the digits from last to first.
}

// Functions to part 3.
/*
    The function asks the user for input and checks if the input is valid for part 3.
    if the input is valid, the function will also calculate the sum of the whole digits and
    the sum of the fraction digits, and print them to the screen.
*/
void floatingPointNumber()
{
    // Variables Definition
    int is_first = 1, is_left = 1, left_sum = 0, right_sum = 0, true_flag = 1, is_one_side = 0;
    char temp_char;

    printf("Please enter a real number\n");

    // Do-While loop to loop through the user input chars.
    do
    {
        // Read a char from the buffer.
        scanf("%c", &temp_char);

        // Checks if the char is the first one and equal Enter,
        if (temp_char == 10 && is_first)
            // If so, the validity flag will turn to 0. the input is invalid.
            true_flag = 0;
        // Checks if the currect char being checked is the first.
        if (is_first)
        {
            // Checks if the char equal '.'.
            if (temp_char == '.')
            {
                // If so, the left number is finished and now will start the right number. therefore, left flag will turn off.
                is_left = 0;
            }
            // Else, Checks if the char is between '0' and '9' - a digit.
            else if (temp_char >= '0' && temp_char <= '9')
            {
                // Checks if the left flag is turn on.
                if (is_left)
                    // If so, the char value will add to the left number sum.
                    left_sum += (temp_char - '0');
                // a number to the left or right of the dot exist. at least one side flag turn on.
                is_one_side = 1;
                /*else
                    right_sum += (temp_char - '0');*/
            }
            // Else, checks if the char doesn't equal '-'.
            else if (temp_char != '-')
                // If so, the input is invalid. validity flag will turn off.
                true_flag = 0;
            // Finished checking the first digit, now first digit flag will turn off.
            is_first = 0;
        }
        // Else, (if the char currently being checked isn't the first).
        else
        {
            // Checks if the char equal '.'.
            if (temp_char == '.')
            {
                // Checks if the number being checked before belong to the left number.
                if (is_left)
                    // If so, the left number is finished and now will start the right number. therefore, left flag will turn off.
                    is_left = 0;
                // Else, it already in the right number, and the dot is present again (in the second time).
                else
                    // Therefore, the input is invalid. validity flag will turn off.
                    true_flag = 0;
            }
            // Else, Checks if the char is between '0' and '9' - a digit.
            else if (temp_char >= '0' && temp_char <= '9')
            {
                // Checks if the number being checked before belong to the left number.
                if (is_left)
                    // If so, the char value will add to the left number sum.
                    left_sum += (temp_char - '0');
                // Else, the number will be add to the right number sum.
                else
                    right_sum += (temp_char - '0');
                // a number to the left or right of the dot exist. at least one side flag turn on.
                is_one_side = 1;
            }
            // Else, if the char doesn't equal Enter.
            else if (temp_char != 10)
                // The input is invalid. validity flag will turn off.
                true_flag = 0;
        }
    } while (temp_char != 10);
    // Checks if the validity flag turn on and at least left or right number exist around the dot.
    if (true_flag && is_one_side)
        printf("%d.%d\n", left_sum, right_sum);
    // Else, the input was invalid, prints an error message.
    else
        printError();
}

// Functions for Part 4:
/*
    The function prints message to the screen and return 0.
*/
int Exit()
{
    printf("Bye\n");
    return 0;
}
