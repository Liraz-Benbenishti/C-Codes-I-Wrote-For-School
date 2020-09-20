#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Variable Definition for part A:
    char lower_char;
    // Variable Definition for part B:
    int ascii_code;
    // Variable Definition for part C:
    int digit;
    char digit_char;
    // Variable Definition for part D:
    int left_number, right_number;
    int hundreds_digit, tens_digit;
    int last_digit, left_number_sum;
    int right_number_sum;

    /*
    Part A: Gets a lower case letter
    and prints the lower case number,
    its ASCII code, its upper case
    letter and its ASCII code.
    */
    printf("Enter lower case letter\n");
    scanf("%c", &lower_char);
    char upper_letter = lower_char - 'a' + 'A';
    printf("The ASCII code of %c is "
           "%d\nThe ASCII code of %c is %d\n",
           lower_char, lower_char, upper_letter,
           upper_letter);

    /*
    Part B: Gets a ASCII code (int)
    and prints its character.
    */
    printf("Enter ASCII code of some"
           " character\n");
    scanf("%d", &ascii_code);
    printf("The character with ASCII"
           " code %d is %c\n", ascii_code,
           ascii_code);

    /*
    Part C: Gets a digit (int) and
     prints its ASCII code.
     */
    printf("Enter a digit\n");
    scanf("%d", &digit);
    digit_char = '0' + digit;
    printf("The ASCII code of %c is "
           "%d\n", digit_char,
           digit_char);

    /*
    Part D: Gets a real number, and
    prints: the whole number, the
    fraction, the sum of the whole
    number digits, the sum of the
    fraction digits.
    */
    printf("Enter a real number\n");
    scanf("%d%c%d", &left_number,
          &right_number, &right_number);
    // Left number digits.
    hundreds_digit = left_number / 100;
    tens_digit = (left_number / 10) % 10;
    last_digit = left_number % 10;
    // Left number digits sum.
    left_number_sum = hundreds_digit +
        tens_digit + last_digit;
    // Right number digits sum.
    right_number_sum = (right_number / 1000)
        + (right_number / 100) % 10 +
        (right_number / 10) % 10 +
        right_number % 10;
    printf("%d\n%d\n%d\n%d",
           left_number, right_number,
           left_number_sum, right_number_sum);
    return 0;
}
