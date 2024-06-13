/* Cengiz Demiray – 2526960
I read and accept the submission rules and the extra rules specified in each question. This is my own work that is done by myself only */
#ifndef BUILDING_H
#define BUILDING_H
#include"room.h"
#include"office.h"
#include"classroom.h"
class Building
{
private: //member variable of building class
    char *build_name;
    int size;
    Room *rooms[100];
    int number_of_rooms;
public:
    Building(); // default constructor
    Building(char [],int); // parametrized constructor
    Building(const Building&); // copy constructor
    Building& operator=(const Building&); // assigment operator overload
    void addRoom(char [],int,int); // for adding room to building
    void printBuilding(); // for printing details of the build
    void printRooms(); // for printing rooms of specific building
    void printRoomsbyType(int); // printing rooms in the building based on type
    // from line 23 to 32, setter and getter functions for the member variables
    void setBuildingName(char []);
    void setSize(int);
    void setNumberofRooms(int);
    char* getBuildingName();
    int getSize();
    int getNumberofRooms();
    int getNumberofClassroom();
    int getTotalCapacity();
    int getNumberofOffice();
    void printAvailableOffice(); // for printing available office
    void printSuitableClassrooms(int); // for printing suitable classroom

    ~Building(); // destructor function, building class has heap variable
};









#endif