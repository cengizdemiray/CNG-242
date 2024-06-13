/* Engin Eray Kabalak- 2526424, Cengiz Demiray – 2526960
We read and accept the submission rules and the extra rules specified in each question. This is
our own work that is done by us only */


#ifndef ASSIGMENT_GRID_H
#define ASSIGMENT_GRID_H


#include "Element.h"
#include <vector>
class Grid {

private:
    int sizeOfGrid;
    Element **gameTable;
    std::vector<int> Index;
public:
    Grid(int sizeOfGrid);
    void showGameTable();
    void deploymentOfElements();
    virtual ~Grid();
    bool checkTableGivenIndexHasAlreadyElement(int row, int column);
    bool isValidThirdCell(int firstRow, int firstCol, int secondRow, int secondCol, int thirdRow, int thirdCol);
    Element getElement(int first, int second);
    std::vector<int> getVector();
    void pushtoIndexVector(int,int,int,int);
    int isFound(int,int);
    int countGold();
    int getnumGold();
};


#endif //ASSIGMENT_GRID_H
