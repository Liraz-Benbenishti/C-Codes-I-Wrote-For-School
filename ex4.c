/* Liraz Benbenishti 308019256 01 */
#include <stdio.h>
#include <string.h>

// Constants Definition
#define TRUE 1
#define FALSE 0
#define MAX_ARRAY_SIZE 50
#define MATRIX_COLUMNS 10
#define MATRIX_ROWS 20
#define SQU_MAT_ROWS 50
#define SQU_MAT_COLS 30
#define END_OF_STRING '\0'
#define MIN_POSSIBLE_X 3
#define OPTION_ONE 1
#define OPTION_TWO 2
#define OPTION_THREE 3
#define OPTION_FOUR 4
#define OPTION_FIVE 5
#define ONE 1
#define PREV_CELL -1
#define NEXT_CELL 1
#define NEXT_POSSIBLE_X 2
#define MULTIPLE_BY_TWO 2
#define MAX_STRING_SIZE 180
#define MAX_REPLACE_STR_SIZE 10
#define UPPER_A_KEY 'A'
#define UPPER_Z_KEY 'Z'
#define LOWER_A_KEY 'a'

// Functions Declaration
void printError();
// Functions for part 1:
void similarArrays();
int checkNoRepetition(int[], int);
int appearancesAtArray(int[], int, int);
int allArrayAppear(int[], int[], int, int);
// Functions for part 2:
void nameSorting();
int namesInput(char[][MATRIX_COLUMNS], int);
void listSort(char[][MATRIX_COLUMNS], int);
void bubbleSort(char[][MATRIX_COLUMNS], int);
void lowercaseMatrix(char[][MATRIX_COLUMNS], int);
void printNames(char[][MATRIX_COLUMNS], int);
// Functions for part 3:
void squareMatrix();
void inputSquareMatrix(int[][SQU_MAT_COLS], int, int);
void findMaximumX(int[][SQU_MAT_COLS], int, int);
int isSubMatrixX(int[][SQU_MAT_COLS], int, int, int);
// Functions for part 4:
void replaceSortString();
void replaceStrings(char[], char[], char[]);
void charBubbleSort(char[], int);
void stringSort(char[]);
// Functions for part 5:
int Exit();

int main()
{
    // Variable Definition for menu.
    int choice, menu_flag = TRUE;

    // Do-while loop to loop until the user exits.
    do
    {
        // The user input a number.
        printf("Choose an option\n");
        scanf("%d", &choice); // Gets a positive number as input.

        // Switch-case for menu.
        switch (choice)
        {
            case OPTION_ONE:
                // Part 1: Similar arrays++.
                similarArrays();
                break;
            case OPTION_TWO:
                // Part 2: Names sorting.
                nameSorting();
                break;
            case OPTION_THREE:
                // Part 3: Square matrix.
                squareMatrix();
                break;
            case OPTION_FOUR:
                // Part 4: String switch and sort.
                replaceSortString();
                break;
            case OPTION_FIVE:
                // Part 5: Exit.
                menu_flag = Exit();
                break;
            default:
                printError();
        }
    } while (menu_flag);
    return 0;
}

/*
    Input:          none.
    Output:         none.
    Functionality:  prints an error message to the screen.
*/
void printError()
{
    printf("Input error\n");
    return;
}

// Functions for part 1:
/*
    Input:          none.
    Output:         none.
    Functionality:  The function checks if the first array the user inserted
                    is Similar++ to the second array.
*/
void similarArrays()
{
    int arrayA[MAX_ARRAY_SIZE], arrayB[MAX_ARRAY_SIZE]; // Variable definition for the arrays.
    int arrayAsize, arrayBsize; // Variable definition for the arrays size.
    int flag = TRUE;
    int i;

    printf("Please enter array 1 size\n"); // Asks the user to input the size of the first array.
    scanf("%d", &arrayAsize);

    printf("Please enter array 1\n"); // Asks the user to input the first array.

    for (i = 0; i < arrayAsize; i++) // For loop to get the values for the first array.
        scanf("%d", &arrayA[i]);

    printf("Please enter array 2 size\n"); // Asks the user for the second array size.
    scanf("%d", &arrayBsize);

    printf("Please enter array 2\n"); // Asks the user for the values of the second array.

    for (i = 0; i < arrayBsize; i++) // For loop to get the values for the second array.
        scanf("%d", &arrayB[i]);

    if (!checkNoRepetition(arrayA, arrayAsize)) // Checks if there is repetition of numbers in the first array.
        // If so, the array is not similar++. flag will change to FALSE.
        flag = FALSE;
    // Else, checks if there is a number in the first array that doesn't appear in the second.
    else if (!allArrayAppear(arrayA, arrayB, arrayAsize, arrayBsize))
        // If so, the array is not similar++. flag will change to FALSE.
        flag = FALSE;
    // Else, checks if there is a number in the second array that doesn't appear in the first.
    else if (!allArrayAppear(arrayB, arrayA, arrayBsize, arrayAsize))
        // If so, the array is not similar++. flag will change to FALSE.
        flag = FALSE;

    // Checks if the flag equal TRUE, if so the arrays are similar++.
    if (flag)
        // If so, the arrays must be similar++ and a message will output to the screen.
        printf("Similar++\n");
    // Else, The arrays are not similar++ and a message will output to the screen.
    else
        printf("Not Similar++\n");
}

/*
    Input:          The address of an array of integers (int[]), integer that indicates th size of the array (int).
    Output:         integer that indicates if there are numbers in the array that repeats..
    Functionality:  The function checks if there are repetition of numbers in the array.
*/
int checkNoRepetition(int check_array[], int array_size)
{
    int i;

    // For loop to loop through the array and check if there are numbers that repeat in the array.
    for (i = 0; i < array_size; i++)
        // Checks if a specific number in the array appears more than 1 times (repeats itself).
        if (AppearancesAtArray(check_array, array_size, check_array[i]) > ONE)
            // If so, a number in the array repeat itself, there are repetitions in the array and the function will return FALSE.
            return FALSE;
    // If the function didn't returned by now there aren't any numbers in the array that repeat themselves. the function will return TRUE.
    return TRUE;
}

/*
    Input:          The address of array of integers (int[]), integer that indicates th size of the array (int),
                    integer that indicates which number to check (int).
    Output:         integer that indicates how many times the number to check appears in the array.
    Functionality:  The function how much times the number to check appear in the array and return the number to the calling function.
*/
int AppearancesAtArray(int numbers_array[], int array_size, int search_num)
{
    int i, number_of_appearances = 0;

    // For loop to loop through the array cells.
    for (i = 0; i < array_size; i++)
        // Checks if the array cell value equals to the checked number.
        if (numbers_array[i] == search_num)
            // If so, the checked number appear in the array and the appearances counter will increase by 1.
            number_of_appearances++;

    // Returns the number of appearances to the user.
    return number_of_appearances;
}

/*
    Input:          The function get the address of an array of integers (int[]), a second address of an array of integers (int[]),
                    the size of the first array (int), the size of the second array (int).
    Output:         integer that indicates if all the numbers in the first array appears in the second (int).
    Functionality:  The function checks if all the numbers in the first array appears in the second array
                    and return an appropriate integer to the calling function
*/
int allArrayAppear(int arrayA[], int arrayB[], int arrayA_size, int arrayB_size)
{
    int i, j;

    // For loop to loop through the number in the first array.
    for (i = 0; i < arrayA_size; i++)
        // For loop to loop through the numbers in the second array.
        for (j = 0; j < arrayB_size; j++)
            // Checks if specific number in the first array doesn't appears in the second array.
            if (!AppearancesAtArray(arrayB, arrayB_size, arrayA[i]))
                // If so, not all the numbers in the first array appear in the second array. the function will return FALSE.
               return FALSE;

    // If the function didn't returned by now, all the numbers in the first array appears in the second array.
    return TRUE;
}

// Functions for part 2:
/*
    Input:          none.
    Output:         none.
    Functionality:  The function asks the user for list of names, it sort the names, and print the names aphabetically.
*/
void nameSorting()
{
    char names[MATRIX_ROWS][MATRIX_COLUMNS]; // Define a matrix of chars in the size of 20x10.
    int inserted_rows;

    printf("Please enter names\n"); // Asks the user for list of names.

    inserted_rows = namesInput(names, MATRIX_ROWS); // Gets an array of names.

    lowercaseMatrix(names, inserted_rows); // Lowercase the matrix chars.

    listSort(names, inserted_rows - ONE); // Sorts the list oof name in bubblesort method.

    printNames(names, inserted_rows - ONE); // Prints the alphabetically sorted list of names.
}

/*
    Input:          address of matrix of chars (char[][]), integer that indicates the number of rows in the matrix (int).
    Output:         return an integer that how much rows inserted to the matrix (int).
    Functionality:  the function asks the user for list of names until the user inputed "done".
                    the function returns how much rows the user inserted to the function.
*/
int namesInput(char names[][MATRIX_COLUMNS], int rows)
{
    int current_row = 0;

    // Do-while loop to get multiple numbers of names.
    do
    {

        scanf("%s", names[current_row]); // Asks the user for string of name. and insert the name to the matrix.

		// Increase the index of the letter to check.
        current_row++;

    } while (strcmp(names[current_row + PREV_CELL], "done")); // Will loop until encounter the string "done".

	// Returns the number of rows inserted to the matrix.
    return current_row;
}

/*
    Input:          address of matrix of chars (char[][]), integer that indicates the number of rows in the matrix (int).
    Output:         none.
    Functionality:  the function lowercase the chars in the matrix.
*/
void lowercaseMatrix(char names[][MATRIX_COLUMNS], int rows)
{
    int i, j;

	// For loop to loop through the rows of the matrix.
    for (i = 0; i < rows; i++)
    {
        j = 0; // Set column index to 0.

        // While loop to loop through the name chars and lowercase them.
        while (names[i][j] != END_OF_STRING)
        {
			// Checks if the char is between 'A' and 'Z' - an uppercase letter.
            if (names[i][j] >= UPPER_A_KEY && names[i][j] <= UPPER_Z_KEY)
				// If so, change the letter and make it lowercase.
                names[i][j]+=(LOWER_A_KEY - UPPER_A_KEY);
            j++;
        }
    }
}

/*
    Input:          address of matrix of chars (char[][]), integer that indicates the number of rows in the matrix (int).
    Output:         none.
    Functionality:  the function sort the matrix in bubble sort method.
*/
void listSort(char names[][MATRIX_COLUMNS], int rows)
{
    int i = 0;

	// For loop to loop through the rows of the matrix.
    for (i = rows - ONE; i > 0; i--)
		// sort the matrix in bubble sort method.
        bubbleSort(names, i);
}

/*
    Input:          address of matrix of chars (char[][]), integer that indicates the number of rows in the matrix (int).
    Output:         none.
    Functionality:  Part of the bubble sort functions (with listSort()) every call will make the last
                    aplhabetically string to be at the last row.
*/
void bubbleSort(char names[][MATRIX_COLUMNS], int rows)
{
    char temp[MATRIX_COLUMNS];
    int i;

    // For loop to loop through the matrix rows.
    for (i = 0; i < rows; i++)
        // Checks if the cell suppose to be after the next cell aplhabetically.
        if (strcmp(names[i], names[i + NEXT_CELL]) > 0)
        {
            // Inserts the checked cell value to the temp string variable.
            strcpy(temp, names[i]);
            // Inserts the next cell value to the checked cell. (flipping positions between cells.
            strcpy(names[i], names[i + NEXT_CELL]);
            // Inserts the checked cell value that was stored in the temp variable to the next cell.
            strcpy(names[i + NEXT_CELL], temp);
        }
}

/*
    Input:          address of matrix of chars (char[][]), integer that indicates the number of rows in the matrix (int).
    Output:         none.
    Functionality:  Prints the rows of the matrix.
*/
void printNames(char names[][MATRIX_COLUMNS], int rows)
{
    int i;

    // For loop to loop through the matrix rows.
    for (i = 0; i < rows; i++)
        printf("%s\n", names[i]); // Prints the string of the row.
}

// Functions for part 3:
/*
    Input:          none.
    Output:         none.
    Functionality:  The function asks the user for number of matrix rows and columns,
                    calls matrix input function and calls find maximum x function.
*/
void squareMatrix()
{
    int square_matrix[SQU_MAT_ROWS][SQU_MAT_COLS];
    int matrix_rows, matrix_columns;

    printf("Please enter lines number\n"); // Asks the user for the number of lines in the matrix.
    scanf("%d", &matrix_rows); // Gets number of matrix rows from the user.

    printf("Please enter columns number\n"); // Asks the user for the number of columns in the matrix.
    scanf("%d", &matrix_columns); // Gets number of matrix columns from the user.

    inputSquareMatrix(square_matrix, matrix_rows, matrix_columns); // Calls the function to get input for the matrix.

    findMaximumX(square_matrix, matrix_rows, matrix_columns); // calls the function to print the maximum x coordinates and size.
}

/*
    Input:          gets an address of matrix of integers {int[][]), integer that indicates number of rows of the matrix (int) and
                    integer that indicates number of columns in the matrix (int).
    Output:         none.
    Functionality:  The function loop through the matrix and prints the coordinates and size of the biggest x in the matrix.
*/
void findMaximumX(int square_matrix[][SQU_MAT_COLS], int mat_rows, int mat_cols)
{
    int cell_max; // Holds the maximum possible x size from the checked cell.
    int big_x_row, big_x_col, big_x_size = 0; // Holds the data of the max x matrix.
    int i, j, h, search_x_size = MIN_POSSIBLE_X;

    i = 0;

    // While loop to loop through the rows of the matrix with possible x sub-matrix.
    while (i <= mat_rows - search_x_size)
    {
        j = 0;

        // While loop to loop through the columns of the matrix with possible x sub matrix.
        while (j <= mat_cols - search_x_size)
        {
            // Checks if more rows left than columns to the end of the matrix.
            if (mat_rows - i > mat_cols - j)
                // If so, there is less columns, and we will remember the maximum size of possible sub square x matrix possible.
                cell_max = mat_cols - j;
            // Else, there is more columns left then rows.
            else
                // If so, there is less rows, and we will remember the maximum size of possible sub square x matrix possible.
                cell_max = mat_rows - i;

            // For loop to loop through the possible sizes of the x matrix.
            for (h = search_x_size; h <= cell_max; h+=NEXT_POSSIBLE_X)
                // Checks if there is a x matrix starting from this cell in a specific size and checks if it bigger from the biggest one found.
                if(isSubMatrixX(square_matrix, i, j, h) && h > big_x_size)
                {
                    // If so, changes the values of the last biggext x found to the new one found.
                    big_x_size = h; // Stores the size of the biggest one found.
                    big_x_row = i; // Stores the row of the starting cell fo the x matrix.
                    big_x_col = j; // Stores the column of the startign cell of the x matrix.
                    search_x_size+=NEXT_POSSIBLE_X; // Increase the next biggest x to search by 2.
                }
            j++;
        }
        i++;
    }

    // Checks if we found a x matrix.
    if (big_x_size)
        // If so, prints the coordinates and size of the x matrix.
        printf("[%d,%d]\n%d\n", big_x_row, big_x_col, big_x_size);
    else
        // Else, prints an appropriate message.
        printf("No X matrix\n");
}

/*
    Input:          gets an address of matrix of integers {int[][]), integer that indicates number of rows of the matrix (int) and
                    integer that indicates number of columns in the matrix (int).
    Output:         none.
    Functionality:  The function gets from the user the values of the matrix cells and inserts them to the matrix.
*/
void inputSquareMatrix(int square_matrix[][SQU_MAT_COLS], int matrix_rows, int matrix_columns)
{
    int i, j;

    printf("Please enter a matrix\n"); // Asks the user to insert the matrix.

    // For loop to get the rows of the matrix.
    for (i = 0; i < matrix_rows; i++)
        // For loop to get the columns of the matrix.
        for (j = 0; j < matrix_columns; j++)
            scanf("%d", &square_matrix[i][j]); // gets and insert the number the user typed to the matrix.
}

/*
    Input:          gets an address of matrix of integers {int[][]), integer that indicates the row index of a matrix cell (int),
                    an integer that indicates the column index of a matrix cell (int), and a integer indicates the size of a x matrix to search (int).
    Output:         returns a number indicates if there is a x matrix in the specific size in the cell or not (int).
    Functionality:  the function checks if there is a x sub matrix in the specifix size and cell return TRUE if there is and FALSE if isn't.
*/
int isSubMatrixX(int square_matrix[][SQU_MAT_COLS], int cell_row_index, int cell_column_index, int x_size)
{
    int i, j;
    int sum_of_sub_matrix = 0;

    // For loop to loop through the rows of the sub matrix being checked (in order to checks that the diagonal cells doesn't equal 0).
    for (i = 0; i < x_size; i++)
        // Checks if the cell being checked equals zero (in the main diagonal of the sub matrix).
        if (!(square_matrix[cell_row_index + i][cell_column_index + i]))
            // If so, there isn't a x matrix in that size in that cell, the function returns FALSE.
            return FALSE;
        // Else, checks if the cell being checked equals zero (in the secondary diagonal of the sub matrix).
        else if (!(square_matrix[cell_row_index + i][cell_column_index + x_size - i + PREV_CELL]))
            // If so, there isn't a x matrix in that size in that cell, the function returns FALSE.
            return FALSE;

    // For loop to loop through the rows of the sub matrix.
    for (i = cell_row_index; i < cell_row_index + x_size; i++)
        // For loop to loop through the columns of the sub matrix.
        for (j = cell_column_index; j < cell_column_index + x_size; j++)
            // Calculates the sum of the matrix cells.
            sum_of_sub_matrix+=square_matrix[i][j];

    // Checks if the sum of the matrix cells doesn't equal the sum that suppose to be in a x sub matrix.
    if (sum_of_sub_matrix != MULTIPLE_BY_TWO * x_size - ONE)
        // If so, that isn't a sub matrix and the function will return FALSE.
        return FALSE;

    // If the function didn't returned by now, it's must be a x sub matrix, and the function will return TRUE.
    return TRUE;
}

// Functions for part 4:
/*
    Input:          none.
    Output:         none.
    Functionality:  the function asks the user for a string, a string to be replaced and the string to replace that string, and prints the
                    string after replacing. after that the function will sort the new string chars and print the string after sorting.
*/
void replaceSortString()
{
    char first_string[MAX_STRING_SIZE]; // An array of chars to hold the string the user typed.
    char str_to_replace[MAX_REPLACE_STR_SIZE]; // An array of chars to hold the string that suppose to be replaced.
    char replacing_str[MAX_REPLACE_STR_SIZE]; // An array of chars to hold the string that suppose to replace the string to be replaced.

    printf("Please enter a string\n"); // Asks the user to enter a string.
    scanf("%s", &first_string); // Gets a string from the user.

    printf("Please enter string to replace\n"); // Asks the user to enter a string to replace from the original.
    scanf("%s", &str_to_replace); // Gets a string to replace from the user.

    printf("Please enter replacing string\n"); // Asks the user to enter a string that suppose to replace the replaced string.
    scanf("%s", &replacing_str); // Gets a replacing string from the user.

    replaceStrings(first_string, str_to_replace, replacing_str); // Replace the string that suppose to be replaced in the string by the replacing string.

    puts(first_string); // Prints the string after the replacement.

    stringSort(first_string); // Sorts the string the user typed, after the replacement.

    puts(first_string); // Prints the string after sorting.
}

/*
    Input:          Gets (the address of) a string to check (char[]), a string that suppose to be replaced (char[]) and a string that suppose to replace it (char[]).
    Output:         none.
    Functionality:  The function finds the string to be replaced in the string to be checked, and replace it with the string that suppose to replace it..
*/
void replaceStrings(char first_string[], char str_to_replace[], char replacing_str[])
{
    int i = 0, h;
    int is_true;
    int sec_strlen = strlen(str_to_replace); // Holds the size of the second string.
    int third_strlen = strlen(replacing_str); // Holds the size of the third string.

    // Do-while loop to loop through the string to be checked.
    do
    {
        is_true = TRUE;
        h = 0;

        // While loop to loop through the string to be replaced in the current string to be checked index.
        while (h < sec_strlen && is_true)
        {
            // Checks if checked string char doesn't equal the replaced string char.
            if (!(first_string[i+h] == str_to_replace[h]))
                // If so, the string to be replaced doesn'Tt appear from this checked string index.
                is_true = FALSE;

            h++; // Increase to replaced string index to check the next char.
        }

        // if the true flag is still to there is a string to be replace in the currect index.
        if (is_true)
        {
            // Checks if the replacing string is longer from the string to be replace.
            if (sec_strlen < third_strlen)
            {
                // For loop to loop through the checked string. move the string chars the necessary amount of cells.
                for (h = strlen(first_string) + third_strlen - sec_strlen; h >= i; h--)
                    // Move the cell of the checked string the necessary amount of cells to the right.
                    first_string[h] = first_string[h - third_strlen + sec_strlen];

                // For-loop to loop through the checked string and put the new string instead the string to be replaced.
                for (h = i; h < i + third_strlen; h++)
                    first_string[h] = replacing_str[h - i]; // Replacing the old string with the new one.

                // Jump with the checked string index the right amount of chars in order the continue searching for strings to replace.
                i+=third_strlen;
            }
            // Else, the string to be replace is longer or equals the replacing string.
            else
            {
                // For loop to loop through the checked string. move the string chars the necessary amount of cells.
                for (h = i + sec_strlen; h <= strlen(first_string); h++)
                    // Move the cell of the checked string the necessary amount of cells to the left.
                    first_string[h + third_strlen - sec_strlen] = first_string[h];

                // For-loop to loop through the checked string and put the new string instead the string to be replaced.
                for (h = i; h < i + third_strlen; h++)
                    first_string[h] = replacing_str[h - i]; // Replacing the old string with the new one.

                // Jump with the checked string index the right amount of chars in order the continue searching for strings to replace.
                i+=third_strlen;
            }
        }
        // Else, it didn't found from that cell the string to be replaced.
        else
            i++; // Increasing the index in order to search in the next cell of the checked string.

    } while (first_string[i] != END_OF_STRING); // Loop until reaches the end of the checked string.

}

/*
    Input:          Gets the address of an array of chars (char[]).
    Output:         none.
    Functionality:  The function uses bubble sort sorting method to sort the inputed string.
*/
void stringSort(char first_string[])
{
    int i = 0;

    // For loop to use in order to call to bubble sort sorting function.
    for (i = strlen(first_string) - ONE; i > 0; i--)
        // Calls to a bubble sort sorting function on the string.
        charBubbleSort(first_string, i);
}

/*
    Input:          Gets the address of an array of chars (char[]) and an integer indicates the string length (int).
    Output:         none.
    Functionality:  The function uses bubble sort sorting method. after this call the "largest" alphabetically char will be at the end of the array,
                    which being detemined by argument: string_length.
*/
void charBubbleSort(char string_to_sort[], int string_length)
{
    int i;
    char temp;

    // For loop to loop through the characters of the string.
    for (i = 0; i < string_length; i++)
        // Checks if the current cell that beeign checked "larger" alphabetically from the next one.
        if (string_to_sort[i] > string_to_sort[i + NEXT_CELL])
        {
            // If so, we suppose to flip between the cells.
            temp = string_to_sort[i]; // Inserts the current string to a temp string.
            string_to_sort[i] = string_to_sort[i + NEXT_CELL]; // Inserts the next cell string to the current one.
            string_to_sort[i + NEXT_CELL] = temp; // Inserts the currect cell value to the next one, (meaning: fliping between values of the cells).
        }
}

// Functions for Part 5:
/*
    Input:          none.
    Output:         integer - returns 0 to the main function to indicate loop should end (int).
    Functionality:  The function prints message to the screen and return 0.

*/
int Exit()
{
    printf("Bye\n");
    return 0;
}
