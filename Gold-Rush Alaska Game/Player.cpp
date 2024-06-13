/* Engin Eray Kabalak- 2526424, Cengiz Demiray – 2526960
We read and accept the submission rules and the extra rules specified in each question. This is
our own work that is done by us only */


#include "Player.h"
int Player::playerIdDecider=0; // for each player this value will be incremented.


/*
 * This function take size from the player and check if it is greater than 5 or not.
 * It if its greater function return taken value. Otherwise it will take new size.
 */

//Engin Eray kabalak create this function
int Player::decideGridSize() {
    int n;
    cout<<playerId<<". player deciding... \n";
    cout<<"Size can be at least 5x5 and Square Form\n";
    do {
        cout<<"Enter the size of the Grid you want to play:";
        cin>>n;
    } while (n<5);
    health = 2*n;
    cout<<"\n\n";
    return n;
}
//Engin Eray kabalak create this function

 int Player::getPlayerId() {
    return playerId;
}
//Engin Eray kabalak create this function

Player::Player() { // for default constructor
    playerIdDecider++;
    this->playerId=playerIdDecider;//increment player id end set it.
    this->score =0;
    health = 0;
}
//Engin Eray kabalak create this function
int Player::getDeciderID() {
    return playerIdDecider;
}
//Cengiz Demiray  createt this function
void Player::pushToVector(Element elem)
{
    gatheredElements.push_back(elem);
}
//Cengiz Demiray  createt this function

int Player::getPlayerHealth()
{
    return health;
}
//Cengiz Demiray  createt this function

void Player::decrease_health(int amount)
{
    health-=amount;
}
//Cengiz Demiray  createt this function

void Player::increase_health(int amount)
{
    health += amount;
}
int Player::get_Woods_Num()
{
    return num_of_woods;
}
int Player:: getPlayerScore()
{
    return score;
}
void Player::setPlayerScore(int score)
{
    this->score = score;
}
void Player::setWoodNum(int wood_num)
{
    num_of_woods = wood_num;
}
int Player::getGoldNum()
{
    return num_of_golds;
}
void Player::setGoldNum(int goldNum)
{
    num_of_golds = goldNum;
}
//Cengiz Demiray  createt this function

void Player::printPlayer()
{
    cout<<"Player Score: "<<score<<endl;
    cout<<"Health: "<<health<<endl;
    cout<<"Gathered Item: ";
    for(int i =0; i< gatheredElements.size();i++)
    {
        cout<<gatheredElements[i].getRepresentingChar();
    }
    cout<<endl;
}
//Cengiz Demiray  createt this function
void Player::setPlayerHealth(int health)
{
    this->health = health;
}
