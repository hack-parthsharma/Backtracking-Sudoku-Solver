#include <iostream>
#define __empty__ 0
#define __order__ 9
#define debugFlag 0
using namespace std;
double counterFlag4Debug = 0;

void debugupdate()
{
    if (debugFlag == 1)
    {
        cout << counterFlag4Debug << endl;
        counterFlag4Debug++;
    }
}

// Traverses to the next empty LOC in the matrix
bool gotoNextLOC(int MainSudoku[__order__][__order__], int &Row, int &Col)
{
    for (Row = 0; Row < __order__; Row++)
        for (Col = 0; Col < __order__; Col++)
            if (MainSudoku[Row][Col] == __empty__)
                return true;
    return false;
}

// Crosschecks if an element is already filled in the row
bool crossCheckROW(int MainSudoku[__order__][__order__], int Row, int Key)
{
    for (int Col = 0; Col < __order__; Col++)
        if (MainSudoku[Row][Col] == Key)
            return true;
    return false;
}

// Crosschecks if an element is already filled in the column
bool crossCheckCOL(int MainSudoku[__order__][__order__], int Col, int Key)
{
    for (int Row = 0; Row < __order__; Row++)
        if (MainSudoku[Row][Col] == Key)
            return true;
    return false;
}

// Crosschecks if an element is already filled in it's subdomain
bool crossCheckSUBDOMAIN(int MainSudoku[__order__][__order__], int k, int l, int Key)
{
    for (int Row = 0; Row < 3; Row++)
        for (int Col = 0; Col < 3; Col++)
            if (MainSudoku[Row + k][Col + l] == Key)
                return true;
    return false;
}

// returns if a element can be placed in a certain block
bool checkPossibility(int MainSudoku[__order__][__order__], int Row, int Col, int Key)
{
    return !crossCheckROW(MainSudoku, Row, Key) && !crossCheckCOL(MainSudoku, Col, Key) && !crossCheckSUBDOMAIN(MainSudoku, Row - Row % 3, Col - Col % 3, Key) && MainSudoku[Row][Col] == __empty__;
}

// Used to print out the filled out matrix
void print(int MainSudoku[__order__][__order__])
{
    for (int Row = 0; Row < __order__; Row++)
    {
        for (int Col = 0; Col < __order__; Col++)
            cout << MainSudoku[Row][Col] << " ";
        cout << endl;
    }
}
/*
Checks if a element can be filled in a grid
Main Backtracking Algorithm lies here
*/
bool refillSudoku(int MainSudoku[__order__][__order__])
{
    debugupdate();
    int Row, Col;
    // Checks if the next empty location is empty
    if (!gotoNextLOC(MainSudoku, Row, Col))
        return true;

    // Traversing through the array list to fill a grid with an element
    for (int Key = 1; Key < 10; Key++)
    {
        // Check if the element can be placed @present LOC
        if (checkPossibility(MainSudoku, Row, Col, Key) == true)
        {
            // Appended the calue @present location
            MainSudoku[Row][Col] = Key;
            if (refillSudoku(MainSudoku) == true) // recursion starts here
                return true;
            MainSudoku[Row][Col] = __empty__;
        }
    }
    return false;
}

/*
This is the ControlProgram function that controls the flow of the code
The main recurssion is called here.
*/
int ControlProgram(int MainSudoku[__order__][__order__])
{

    cout << "The unsolved refillSudoku is:" << endl;
    print(MainSudoku);

    cout << "The solved refillSudoku is:\n";
    if (refillSudoku(MainSudoku) == true) // Initial Call of Recursive function
        print(MainSudoku);
    else
        cout << "Cannot be Solved(by me)";

    return 0;
}

/*
This is the matrixChooser function
This selects one of the 3 matrices using the user input 
*/
int matrixChooser(int A[__order__][__order__], int B[__order__][__order__], int C[__order__][__order__])
{
    cout << "Choose from matrix A B C" << endl;
    // Self Explainatory
    char SudokuChooser;
    cin >> SudokuChooser;
    int MainSudoku[__order__][__order__];
    // Self Explainatory
    if (SudokuChooser == 'A' || SudokuChooser == 'a')
    {
        for (int Row = 0; Row < __order__; Row++)
        {
            for (int Col = 0; Col < __order__; Col++)
            {
                MainSudoku[Row][Col] = A[Row][Col];
            }
        }
    }
    // Self Explainatory
    else if (SudokuChooser == 'B' || SudokuChooser == 'b')
    {
        for (int Row = 0; Row < __order__; Row++)
        {
            for (int Col = 0; Col < __order__; Col++)
            {
                MainSudoku[Row][Col] = B[Row][Col];
            }
        }
    }
    // Self Explainatory
    else if (SudokuChooser == 'C' || SudokuChooser == 'c')
    {
        for (int Row = 0; Row < __order__; Row++)
        {
            for (int Col = 0; Col < __order__; Col++)
            {
                MainSudoku[Row][Col] = C[Row][Col];
            }
        }
    }
    else
    {
        cout << "There is no such matrix!" << endl;
        return 1;
    }
    ControlProgram(MainSudoku);
    return 0;
}

/*
This is the initialization function that start and loads the variables.
The later functions are called and the program runs like dominoes.
*/
int __init__()
{
    // Input 'A' Matrix
    // Difficulty level - EASY
    int A[__order__][__order__] =
        {{0, 0, 8, 0, 0, 4, 0, 0, 5},
         {0, 0, 0, 7, 0, 0, 8, 0, 0},
         {4, 0, 0, 0, 6, 0, 0, 3, 0},
         {0, 1, 0, 0, 0, 2, 0, 0, 7},
         {0, 0, 6, 0, 0, 0, 9, 0, 0},
         {3, 0, 0, 5, 0, 0, 0, 4, 0},
         {0, 0, 0, 0, 4, 0, 0, 0, 3},
         {0, 0, 7, 0, 0, 9, 0, 0, 0},
         {6, 0, 0, 8, 0, 0, 7, 0, 0}};

    // Input 'B' Matrix
    // Difficulty level - MEDIUM
    int B[__order__][__order__] =
        {{0, 4, 0, 0, 0, 2, 0, 1, 9},
         {0, 0, 0, 3, 5, 1, 0, 8, 6},
         {3, 1, 0, 0, 9, 4, 7, 0, 0},
         {0, 9, 4, 0, 0, 0, 0, 0, 7},
         {0, 0, 0, 0, 0, 0, 0, 0, 0},
         {2, 0, 0, 0, 0, 0, 8, 9, 0},
         {0, 0, 9, 5, 2, 0, 0, 4, 1},
         {4, 2, 0, 1, 6, 9, 0, 0, 0},
         {1, 6, 0, 8, 0, 0, 0, 7, 0}};

    // Input 'C' Matrix
    // Difficulty level - HARD
    int C[__order__][__order__] =
        {{0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 3, 6, 0, 0, 0, 0, 0},
         {0, 7, 0, 0, 9, 0, 2, 0, 0},
         {0, 5, 0, 0, 0, 7, 0, 0, 0},
         {0, 0, 0, 0, 4, 5, 7, 0, 0},
         {0, 0, 0, 1, 0, 0, 0, 3, 0},
         {0, 0, 1, 0, 0, 0, 0, 6, 8},
         {0, 0, 8, 5, 0, 0, 0, 1, 0},
         {0, 9, 0, 0, 0, 0, 4, 0, 0}};
    matrixChooser(A, B, C);
    return 0;
}

int main()
{
    // Call the initial function
    __init__();
}
