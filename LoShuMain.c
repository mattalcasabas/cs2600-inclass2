#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
time_t t;
static int randomSquare[3][3] = {{0,0,0},{0,0,0},{0,0,0}};     // random square that progam will generate. filled with placeholder values


int randInt(int a, int b) {     // function that generates random number between a and b
    int r;
    r = a + rand() % (b-a+1);
    return r;
}

void addNumberToSquare(int a) {
    for(int row = 0; row < 3; row++) {
        for(int column = 0; column < 3; column++) {
            if(randomSquare[row][column] == 0){
                randomSquare[row][column] = a;
            }
        }
    }
}

int checkMagicSquare(int square[3][3]) {
    int sum = square[0][0] + square[0][1] + square[0][2];   // sum of first row. everything must equal this

    // test 2nd and 3rd rows if they equal first row: if they aren't, return 0
    for(int row = 1; row < 3; row++) {        
        if(square[row][0] + square[row][1] + square[row][2] != sum)
            return 0;
    }

    // testing columns to see if they equal first row: if they don't, return 0
    for(int column = 0; column < 3; column++) {
        if(square[0][column] + square[1][column] + square[2][column] != sum)
            return 0;
    }

    // testing diagonal from left to right to see if they equal first row: if they don't, return 0
    if(square[0][0] + square[1][1] + square[2][2] != sum)
        return 0;

    // testing diagonal from right to left to see if they equal first row: if they don't, return 0
    if(square[0][2] + square[1][1] + square[2][0] != sum)
        return 0;

    return 1;   // magic square found! return 1 to caller

}

void pickNumbers() {
    memset(randomSquare, 0, sizeof(randomSquare)); // clear out randomSquare
    int randNum = 0;
    int usedNumbers[] = {0,0,0,0,0,0,0,0,0}; // this array holds used numbers to ensure no duplicates
    bool foundNum = true;

    for (int i = 0; i < 9; i++) {
        // check for duplicate numbers
        do {
            randNum = randInt(1,9);
            if(usedNumbers[randNum-1] == 0) { 
                usedNumbers[randNum-1] = randNum;
                //printf("Adding %d to usedNumbers\n", randNum);
                foundNum = false;
                break;
            }
        } while(foundNum);
        //printf("exit do-while\n");
        addNumberToSquare(randNum);
        memset(usedNumbers, 0, sizeof(usedNumbers));
    }

}


void printSquare(int square[3][3]) {
    for(int row = 0; row < 3; row++) {
        printf("[");
        for(int column = 0; column < 3; column++) {
            printf(" %d ", square[row][column]);
        }
    printf("]\n");
    }
    printf("\n");
}


int main() {
    srand((unsigned)time(&t));      // seed RNG
    int magicSquare[3][3] = {{4,9,2},{3,5,7},{8,1,6}}; // first test case: valid magic square
    printf("First square\n");
    printSquare(magicSquare);
    int notMagicSquare[3][3] = {{5,7,4},{8,3,9},{0,2,1}}; // second test case: not magic square
    printf("Second square\n");
    printSquare(notMagicSquare);
    int result1 = checkMagicSquare(magicSquare), result2 = checkMagicSquare(notMagicSquare), result3 = 0;

    // test the first two magic squares
    if(result1 == 1)
        printf("First square is magic square!\n");
    else
        printf("First square is not magic square!\n");
    if(result2 == 1)
        printf("Second square is magic square!\n");
    else
        printf("Second square is not magic square!\n");

    // generate random squares and print a valid magic square
    printf("Now generating random squares and testing for valid squares...\n");

    int numOfSquares = 0;
    int foundMagicSquare = 0;
    do {
        //printf("%d ", numOfSquares);
        numOfSquares++;
        pickNumbers();
        //printSquare(randomSquare);
        if(checkMagicSquare(randomSquare) != 0)
            foundMagicSquare++;
    } while(foundMagicSquare != 0);

    printf("Found a magic square after %d tries.\n", numOfSquares);

    printSquare(randomSquare);


}