#include <stdio.h>

int checkNumbers(int array[][]) {       // check to see if numbers are valid (1 < x < 9)
    int row, column;
    for (row = 0; row < 2; row++) {
        for (column = 0; column < 2; column++) {
            if(array[row][column] < 1 || array[row][column] > 9)
                return 1;
        }
    }
    return 0;
}

int checkAdditions(int array[][]) {
    int row, column;
    int sum;

    // checking rows
    for (row = 0; row < 2; row++) {
        array[
    }
}

int loShuTest(int array[][]) {
    if(checkNumbers(array[][]) != 0)

    return 0;
}

int main() {
    int array1[3][3] = 
    {
        {4, 9, 2},
        {3, 5, 7}
        {8, 1, 6}
    };    // create 3x3 array

    return 0;
}