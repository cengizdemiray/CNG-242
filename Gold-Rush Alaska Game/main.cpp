/*
 * We wrote our names top of the function. Who wrote that function.
 * In addition, Engin Eray Kabalak 2526424 create classes with constructors and variables.
 * Cengiz Demiray 2526960 complete main.cpp,
 *
 * We communicated each other,
 *
 * Engin Eray Kabalak create the classes and variables for that class.
 * Also ınitialized the grid. Take inputs from user and create game table with randomised.
 *
 *Cengiz demiray, played the game to the users, handle main function, add necessary variables to class.
 *Write new functions for classess.
 *
 */



#include <iostream>
#include "iostream"
#include "Player.h"
#include "cmath"
#include "Grid.h"
#include "Bear.h"
#include <stdlib.h>
#include<time.h>
void menu();
using namespace std;

int main() {
    srand(time(NULL));
    Player p1,p2; // create two player for game.
    cout<<"WELCOME TO THE GOLD RUSH ALASKA GAME\n"<<endl;
    int n1=p1.decideGridSize();
    int n2=p2.decideGridSize();
    int first_coordinate_p1,first_coordinate_p2,second_coordinate_p1,second_coordinate_p2;
    int sizeOfGrid = floor((n1+n2)/2.0); //its not clearly mentioned in the assigment so ı decided grid size like this.
    int turn = 20 + rand()%(sizeOfGrid*sizeOfGrid)-20;
    cout<<turn<<endl;
    Grid grid(sizeOfGrid);
    grid.showGameTable();
    grid.deploymentOfElements();
    for(int i =0; i<turn; i++)
    {
        if(p1.getPlayerHealth()!=0)
        {
            cout<<"Enter the first_coordinate for player 1: "<<endl;
            cin>>first_coordinate_p1;
            cout<<"Enter the second_coordinate for player 1: "<<endl;
            cin>>second_coordinate_p1;
            while(grid.isFound(first_coordinate_p1,second_coordinate_p1))
            {
                cout<<"Enter the first_coordinate for player 1: "<<endl;
                cin>>first_coordinate_p1;
                cout<<"Enter the second_coordinate for player 1: "<<endl;
                cin>>second_coordinate_p1;
            }
            Element elem = grid.getElement(first_coordinate_p1,second_coordinate_p1);
            p1.pushToVector(elem);
            char ch = elem.getRepresentingChar();
            if(ch == 'B')
            {
                char selection;
                cout<<"Select even or odd: "<<endl;
                cin>>selection;
                int rand_num = rand();
                if((selection=='E' && rand_num%2!=0) || (selection=='O' && rand_num%2==0))
                {
                    int decrease_amount = floor(sizeOfGrid/2);
                    p1.decrease_health(decrease_amount);
                }
            }else if(ch == 'W')
            {
                char selection;
                cout<<"Select even or odd: "<<endl;
                cin>>selection;
                int rand_num = rand();
                if((selection=='E' && rand_num%2!=0) || (selection=='O' && rand_num%2==0))
                {
                    int decrease_amount = floor(sizeOfGrid/4);
                    p1.decrease_health(decrease_amount);
                }
            }else if(ch == 'F')
            {
                int increase_amount = floor(sizeOfGrid/6);
                p1.increase_health(increase_amount);
            }else if(ch == 'I'){
               int increase_amount = floor(sizeOfGrid/8);
                p1.increase_health(increase_amount);
                p1.setWoodNum(p1.get_Woods_Num()+1);
                if(p1.get_Woods_Num()%2==0)
                {
                    int increase_amount = floor(sizeOfGrid/8);
                    p1.increase_health(increase_amount);
                }
            }else if(ch == 'G')
            {
                int newscore = p1.getPlayerScore()+100;
                p1.setPlayerScore(newscore);
                p1.setGoldNum(p1.getGoldNum()+1);
                if(p1.getGoldNum()%3==0)
                {
                    int increase_amount = floor(sizeOfGrid/4);
                    p1.increase_health(increase_amount);
                }
            }else if(ch == 'S')
            {
                int increase_amount = floor(sizeOfGrid/4);
                p1.increase_health(increase_amount);
            }if(p1.getGoldNum()+ p2.getGoldNum() == grid.countGold())
            {
                cout<<"All of the Gold is gathered."<<endl;
                break;
            }if(p1.getPlayerHealth()<0){
                p1.setPlayerHealth(0);
            }
            if(p1.getPlayerHealth()==0 && p2.getPlayerHealth()==0)
            {
                cout<<"Both of the players die."<<endl;
                break;
            }
        }
        if(p2.getPlayerHealth()>0)
        {
            cout<<"Enter the first_coordinate for player 2: "<<endl;
            cin>>first_coordinate_p2;
            cout<<"Enter the second_coordinate for player 2: "<<endl;
            cin>>second_coordinate_p2;
            while(grid.isFound(first_coordinate_p2,second_coordinate_p2))
            {
                cout<<"Enter the first_coordinate for player 2: "<<endl;
                cin>>first_coordinate_p2;
                cout<<"Enter the second_coordinate for player 2: "<<endl;
                cin>>second_coordinate_p2;
            }
            Element elem = grid.getElement(first_coordinate_p2,second_coordinate_p2);
            p2.pushToVector(elem);
            char ch = elem.getRepresentingChar();
            if(ch == 'B')
            {
                char selection;
                cout<<"Select even or odd: "<<endl;
                cin>>selection;
                int rand_num = rand();
                if((selection=='E' && rand_num%2!=0) || (selection=='O' && rand_num%2==0))
                {
                    int decrease_amount = floor(sizeOfGrid/2);
                    p2.decrease_health(decrease_amount);
                }
            }else if(ch == 'W')
            {
                char selection;
                cout<<"Select even or odd: "<<endl;
                cin>>selection;
                int rand_num = rand();
                if((selection=='E' && rand_num%2!=0) || (selection=='O' && rand_num%2==0))
                {
                    int decrease_amount = floor(sizeOfGrid/4);
                    p2.decrease_health(decrease_amount);
                }
            }else if(ch == 'F')
            {
                int increase_amount = floor(sizeOfGrid/6);
                p2.increase_health(increase_amount);
            }else if(ch == 'I'){
               int increase_amount = floor(sizeOfGrid/8);
                p2.increase_health(increase_amount);
                p2.setWoodNum(p1.get_Woods_Num()+1);
                if(p2.get_Woods_Num()%2==0)
                {
                    int increase_amount = floor(sizeOfGrid/8);
                    p2.increase_health(increase_amount);
                }
            }else if(ch == 'G')
            {
                int newscore = p2.getPlayerScore()+100;
                p2.setPlayerScore(newscore);
                p2.setGoldNum(p1.getGoldNum()+1);
                if(p2.getGoldNum()%3==0)
                {
                    int increase_amount = floor(sizeOfGrid/4);
                    p2.increase_health(increase_amount);
                }
            }else if(ch == 'S')
            {
                int increase_amount = floor(sizeOfGrid/4);
                p2.increase_health(increase_amount);
            }
            if(p1.getGoldNum()+ p2.getGoldNum() == grid.countGold())
            {
                cout<<"All of the Gold is gathered."<<endl;
                break;
            }if(p2.getPlayerHealth()<0)
            {
                p2.setPlayerHealth(0);
            }
            if(p1.getPlayerHealth()==0 && p2.getPlayerHealth()==0)
            {
                cout<<"Both of the players die."<<endl;
                break;
            }
        }
        grid.pushtoIndexVector(first_coordinate_p1,second_coordinate_p1,first_coordinate_p2,second_coordinate_p2);
        grid.showGameTable();
        cout<<endl;
    }
    if(p1.getGoldNum()+ p2.getGoldNum() == grid.countGold() )
    {
        if(p1.getPlayerScore()>p2.getPlayerScore())
        {
            std::cout << "---------Winner------- "<<endl;
            p1.printPlayer();
            std::cout << "---------Loser--------"<<endl;
            p2.printPlayer();
        }else if(p2.getPlayerScore()>p1.getPlayerScore())
        {
            std::cout << "---------Winner------- "<<endl;
            p2.printPlayer();
            std::cout << "---------Loser--------"<<endl;
            p1.printPlayer();
        }else{
            cout<<"There is no winner or loser, draw"<<endl;
            std::cout << "-------Players---------";
            p1.printPlayer();
            p2.printPlayer();
        }
    }else if(p1.getPlayerHealth()<=0 && p2.getPlayerHealth()<=0)
    {
        cout<<"Both of the players die."<<endl;
        if(p1.getPlayerScore()>p2.getPlayerScore())
        {
            std::cout << "---------Winner------- "<<endl;
            p1.printPlayer();
            std::cout << "---------Loser--------"<<endl;
            p2.printPlayer();
        }else if(p2.getPlayerScore()>p1.getPlayerScore())
        {
            std::cout << "---------Winner------- "<<endl;
            p2.printPlayer();
            std::cout << "---------Loser--------"<<endl;
            p1.printPlayer();
        }else
        {
            cout<<"There is no winner or loser, draw"<<endl;
            std::cout << "-------Players---------";
            p1.printPlayer();
            p2.printPlayer();
        }
    }else if(p2.getPlayerScore()>p1.getPlayerScore())
    {
        std::cout << "---------Winner------- "<<endl;
        p2.printPlayer();
        std::cout << "---------Loser--------"<<endl;
        p1.printPlayer();
    }else if(p1.getPlayerScore()>p2.getPlayerScore())
    {
        std::cout << "---------Winner------- "<<endl;
        p1.printPlayer();
        std::cout << "---------Loser--------"<<endl;
        p2.printPlayer();
    }else
    {
        cout<<"There is no winner or loser, draw"<<endl;
        std::cout << "-------Players---------";
        p1.printPlayer();
        p2.printPlayer();
    }
    return 0;
}


