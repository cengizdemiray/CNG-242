/* Engin Eray Kabalak- 2526424, Cengiz Demiray – 2526960
We read and accept the submission rules and the extra rules specified in each question. This is
our own work that is done by us only */

#ifndef ASSIGMENT_PLAYER_H
#define ASSIGMENT_PLAYER_H
#include <vector>
#include "iostream"
#include "Element.h"

using namespace std;
class Player {
private:
    int playerId;
    static int playerIdDecider;
    vector<Element> gatheredElements;
    int score;
    int health;
    int num_of_golds;
    int num_of_woods;
public:
    Player();
    int decideGridSize();
    int getPlayerId();
    static int getDeciderID();
    void pushToVector(Element);
    int getPlayerHealth();
    void decrease_health(int);
    void increase_health(int);
    int get_Woods_Num();
    int getPlayerScore();
    void setPlayerScore(int);
    void setWoodNum(int);
    int getGoldNum();
    void setGoldNum(int);
    void printPlayer();
    void setPlayerHealth(int);
};



#endif //ASSIGMENT_PLAYER_H
