/* Engin Eray Kabalak- 2526424, Cengiz Demiray – 2526960
We read and accept the submission rules and the extra rules specified in each question. This is
our own work that is done by us only */


#include "Grid.h"
#include <iostream>
#include <ctime>
#include <cmath>
#include "Bear.h"
#include "Wood.h"
#include "Food.h"
#include "MedicalSupplies.h"
#include "Wolf.h"
#include "Gold.h"

using namespace std;
//Engin Eray Kabalak Create this function.
Grid::Grid(int sizeOfGrid) {
    // Seed the random number generator once in the constructor
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    this->sizeOfGrid = sizeOfGrid;
    // create nxn Grid.
    gameTable = new Element*[sizeOfGrid];
    for (int i = 0; i < sizeOfGrid; i++) {
        gameTable[i] = new Element[sizeOfGrid];
    }
    for (int i = 0; i < sizeOfGrid; i++) {
        for (int j = 0; j < sizeOfGrid; j++) {
            gameTable[i][j] = Element();
        }
    }

}
//Engin Eray Kabalak Create this function.

void Grid::showGameTable() {
    for (int i = 0; i < sizeOfGrid; i++) {
        for (int j = 0; j < sizeOfGrid; j++) {
            if(isFound(i,j))
            {
                std::cout << gameTable[i][j].getRepresentingChar()<<"    ";
            }else
            {
                std::cout << '?'<<"    ";
            }

        }
        std::cout << "\n";
    }
    std::cout << "\n\n";
}
//Engin Eray Kabalak Create this function.

Grid::~Grid() {
    // Deallocate memory for each row
    for (int i = 0; i < sizeOfGrid; i++) {
        delete[] gameTable[i];
    }
    // Deallocate memory for gameTable
    delete[] gameTable;
}
//Engin Eray Kabalak Create this function.

void Grid::deploymentOfElements() {
    int numberOfEachSourceExceptBear = 2 * (floor(pow(sizeOfGrid, 2) / 25));
    int numberOfBear = numberOfEachSourceExceptBear / 2;

    bool exit, exit2, exit3;
    int firstCellRow, firstCellColumn, secondCellRow, secondCellColumn, thirdCellRow, thirdCellColumn;

    //Bears placed into grid
    for (int i = 0; i < numberOfBear; i++) {
        Bear bear(floor(sizeOfGrid / 2));
        do {
            firstCellRow = rand() % sizeOfGrid; // Decide Bear firstCell
            firstCellColumn = rand() % sizeOfGrid;
            exit = checkTableGivenIndexHasAlreadyElement(firstCellRow, firstCellColumn);
        } while (exit);
        gameTable[firstCellRow][firstCellColumn] = bear;
        do {
            exit2 = false;
            secondCellRow = rand() % 3 + (firstCellRow - 1);
            secondCellColumn = rand() % 3 + (firstCellColumn - 1);

            if(firstCellRow==0 && firstCellColumn==1)  //chechk position 0,1
            {
                if(secondCellRow==1 && secondCellColumn==0)
                {
                    exit2= true;
                }
            }
            if(firstCellRow==1 && firstCellColumn==0)  //chechk position 1,0
            {
                if(secondCellRow==0 && secondCellColumn==1)
                {
                    exit2= true;
                }
            }
            if (firstCellRow==(sizeOfGrid-2) &&firstCellColumn==0)  //chechk left bottom corner
            {
                if(secondCellRow==(sizeOfGrid-1)&& (secondCellColumn==1))
                    exit2= true;
            }
            if (firstCellRow==(sizeOfGrid-1) &&firstCellColumn==1) //chechk left bottom corner
            {
                if(secondCellRow==(sizeOfGrid-2)&& (secondCellColumn==0))
                    exit2= true;
            }
           if((firstCellRow==0) && (firstCellColumn==sizeOfGrid-2))
            {
                if(secondCellRow==1 && secondCellColumn==(sizeOfGrid-1))
                    exit2= true;
            }
            if((firstCellRow==1) && (firstCellColumn==sizeOfGrid-1))
            {
                if(secondCellRow==0 && secondCellColumn==(sizeOfGrid-2))
                    exit2= true;
            }
            if(firstCellRow==sizeOfGrid-1 && firstCellColumn==sizeOfGrid-2)
            {
                if(secondCellRow==sizeOfGrid-2 && secondCellColumn==sizeOfGrid-1)
                    exit2= true;
            }
            if(firstCellRow==sizeOfGrid-2 && firstCellColumn==sizeOfGrid-1)
            {
                if(secondCellRow==sizeOfGrid-1 && secondCellColumn==sizeOfGrid-2)
                    exit2= true;
            }
            if (secondCellRow < 0 || secondCellColumn < 0 || secondCellRow >= sizeOfGrid || secondCellColumn >= sizeOfGrid) {
                exit2 = true;
            }
            else if (checkTableGivenIndexHasAlreadyElement(secondCellRow, secondCellColumn)) {
                exit2 = true;
            }
        } while (exit2);
        gameTable[secondCellRow][secondCellColumn] = bear;
        do {
            exit3 = false;
            if(firstCellColumn>=secondCellColumn)
            {
                thirdCellColumn = rand() % ((firstCellColumn+1) - (secondCellColumn-1) + 1) + secondCellColumn-1;
            }
            else if(secondCellColumn>firstCellColumn)
            {
                thirdCellColumn = rand() % ((secondCellColumn+1) - (firstCellColumn-1) + 1) + firstCellColumn-1;
            }
            if(firstCellRow>=secondCellRow)
            {
                thirdCellRow = rand() % ((firstCellRow+1) - (secondCellRow-1) + 1) + secondCellRow-1;
            }
            else if(secondCellRow>firstCellRow)
            {
                thirdCellRow = rand() % ((secondCellRow+1) - (firstCellRow-1) + 1) + firstCellRow-1;
            }

            if (thirdCellRow < 0 || thirdCellColumn < 0 || thirdCellRow >= sizeOfGrid || thirdCellColumn >= sizeOfGrid) {

                exit3= true;
            }
            else if (checkTableGivenIndexHasAlreadyElement(thirdCellRow, thirdCellColumn)) {
                exit3 = true;
            }
            else{
                exit3= false;

            if(secondCellColumn==firstCellColumn)
            {
                if(thirdCellColumn!=firstCellColumn)
                    exit3= true;
                else
                {
                    if((abs(thirdCellRow - secondCellRow) + abs(thirdCellRow - firstCellRow)) !=3)
                    {
                        exit3= true;
                    }
                }
            }
            else if(secondCellRow==firstCellRow)
            {
                if(thirdCellRow!=firstCellRow)
                    exit3= true;
                else
                {
                    if((abs(thirdCellColumn - secondCellColumn) + abs(thirdCellColumn - firstCellColumn)) !=3)
                    {
                        exit3= true;
                    }
                }
            }
            else if (((abs(thirdCellRow - secondCellRow) + abs(thirdCellRow - firstCellRow)) ==3) && (abs(thirdCellColumn - secondCellColumn) + abs(thirdCellColumn - firstCellColumn) == 3)) {
                exit3= true;
                if (firstCellRow>secondCellRow && firstCellColumn>secondCellColumn)
                {
                    if(thirdCellRow==firstCellRow+1)
                    {
                        if(thirdCellColumn==firstCellColumn+1)
                        {
                            exit3= false;
                        }
                    }
                    else if(thirdCellRow==secondCellRow-1)
                    {
                        if(thirdCellColumn==secondCellColumn-1)
                        {
                            exit3= false;
                        }
                    }
                }
                else if (firstCellRow>secondCellRow && firstCellColumn<secondCellColumn)
                {

                    if(thirdCellRow==firstCellRow+1)
                    {
                        if(thirdCellColumn==firstCellColumn-1)
                        {
                            exit3= false;
                        }
                    }
                    else if(thirdCellRow==secondCellRow-1)
                    {
                        if(thirdCellColumn==secondCellColumn+1)
                        {
                            exit3= false;

                        }
                    }
                }
                else if (secondCellRow>firstCellRow && secondCellColumn>firstCellColumn)
                {
                    if(thirdCellRow==secondCellRow+1)
                    {
                        if(thirdCellColumn==secondCellColumn+1)
                        {
                            exit3= false;
                        }
                    }
                    else if(thirdCellRow==firstCellRow-1)
                    {
                        if(thirdCellColumn==firstCellColumn-1)
                        {
                            exit3= false;

                        }
                    }
                }
                else if (secondCellRow>firstCellRow && secondCellColumn<firstCellColumn)
                {
                    if(thirdCellRow==secondCellRow+1)
                    {
                        if(thirdCellColumn==secondCellColumn-1)
                        {
                            exit3= false;

                        }
                    }
                    else if(thirdCellRow==firstCellRow-1)
                    {
                        if(thirdCellColumn==firstCellColumn+1)
                        {
                            exit3= false;
                        }
                    }
                }

            }
            else
            {
                exit3= true;
            }
            }
        } while (exit3);
        gameTable[thirdCellRow][thirdCellColumn] = bear;
    }

    //Woods placed into grid
    for (int i = 0; i < numberOfEachSourceExceptBear; ++i) {
        Wood wood(floor(sizeOfGrid / 8));
        do {
            firstCellRow = rand() % sizeOfGrid; // Decide Wood firstCell
            firstCellColumn = rand() % sizeOfGrid;
            exit = checkTableGivenIndexHasAlreadyElement(firstCellRow, firstCellColumn);
        } while (exit);
        gameTable[firstCellRow][firstCellColumn] = wood;
        do {
            exit2 = false;
            secondCellRow = rand() % 3 + (firstCellRow - 1);
            secondCellColumn = rand() % 3 + (firstCellColumn - 1);

            if (secondCellRow < 0 || secondCellColumn < 0 || secondCellRow >= sizeOfGrid || secondCellColumn >= sizeOfGrid) {
                exit2 = true;
            }
            else if (checkTableGivenIndexHasAlreadyElement(secondCellRow, secondCellColumn)) {
                exit2 = true;
            }
        } while (exit2);
        gameTable[secondCellRow][secondCellColumn] = wood;
    }

    //Foods placed into grid.
    for (int i = 0; i < numberOfEachSourceExceptBear; ++i) {
        Food food(floor(sizeOfGrid / 6));
        do {
            firstCellRow = rand() % sizeOfGrid; // Decide Wood firstCell
            firstCellColumn = rand() % sizeOfGrid;
            exit = checkTableGivenIndexHasAlreadyElement(firstCellRow, firstCellColumn);
        } while (exit);
        gameTable[firstCellRow][firstCellColumn] = food;

    }

    //MedicalSuppliesPlaced into grid.
    for (int i = 0; i < numberOfEachSourceExceptBear; ++i) {
        MedicalSupplies med(floor(sizeOfGrid / 4));
        do {
            firstCellRow = rand() % sizeOfGrid; // Decide Wood firstCell
            firstCellColumn = rand() % sizeOfGrid;
            exit = checkTableGivenIndexHasAlreadyElement(firstCellRow, firstCellColumn);
        } while (exit);
        gameTable[firstCellRow][firstCellColumn] = med;

    }

    //Wolfs placed into grid
    for (int i = 0; i < numberOfEachSourceExceptBear; ++i) {
        Wolf wolf(floor(sizeOfGrid / 4));
        do {
            firstCellRow = rand() % sizeOfGrid; // Decide Wood firstCell
            firstCellColumn = rand() % sizeOfGrid;
            exit = checkTableGivenIndexHasAlreadyElement(firstCellRow, firstCellColumn);
        } while (exit);
        gameTable[firstCellRow][firstCellColumn] = wolf;

    }

    //Golds placed into grid.
    for (int i = 0; i < numberOfEachSourceExceptBear; ++i) {
        Gold gold;
        do {
            firstCellRow = rand() % sizeOfGrid; // Decide Wood firstCell
            firstCellColumn = rand() % sizeOfGrid;
            exit = checkTableGivenIndexHasAlreadyElement(firstCellRow, firstCellColumn);
        } while (exit);
        gameTable[firstCellRow][firstCellColumn] = gold;

    }

}
//Engin Eray Kabalak Create this function.

bool Grid::checkTableGivenIndexHasAlreadyElement(int row, int column) {
    return gameTable[row][column].getRepresentingChar() != '?';
}

//Cengiz Demiray Create this function
Element Grid::getElement(int first, int second)
{
    return gameTable[first][second];
}
//Cengiz Demiray Create this function

std::vector<int> Grid::getVector()
{
    return Index;
}
//Cengiz Demiray Create this function

void Grid::pushtoIndexVector(int first , int second, int third, int fourth)
{
    Index.push_back(first);
    Index.push_back(second);
    Index.push_back(third);
    Index.push_back(fourth);

}
//Cengiz Demiray Create this function

int Grid::isFound(int i,int j)
{
    for(int k =0; k<Index.capacity() && Index.capacity()!=0; k+=2)
    {
        if(i == Index[k] && j==Index[k+1])
        {
            return 1;
        }
    }
    return 0;
}
//Cengiz Demiray Create this function

int Grid::countGold()
{
    int numGold=0;
    for(int i=0;i<sizeOfGrid;i++)
    {
        for(int j=0; j<sizeOfGrid;j++)
        {
            if(gameTable[i][j].getRepresentingChar()=='G')
            {
                numGold++;
            }
        }
    }
}

