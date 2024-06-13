/* Cengiz Demiray – 2526960
I read and accept the submission rules and the extra rules specified in each question. This is my own work that is done by myself only */
#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include "building.h"

class University
{
private: // member variable of the University class
    char *university_name;
    Building *builds[20];
    int numberofBuildings;
public: //member functions
    University(); //default constructor
    University(char []); // parametrized constructor
    //15-17 setter and getter functions of the member variable
    void setUniversityName(char []);
    char* getUniversityName();
    int getNumberofBuildings();
    void addBuilding(char [],int); // for adding building to university
    void printBuildings(); // for printing the details of the buildings in the university
    Building& getSpecificBuilding(int); // for getting specific  building in the university
    void printRooms(); // for printing the rooms in the university
    void printRoomsByType(int); // for printing the rooms in the university based on the type that is given as a function parameter
    void printRoomStatistics(); // for printing how many class and office exist in the university
    void printAvailableOffice(); // for printing available office means that number of people in the office is less than the capacity of the office
    void printTotalCapacityofOffices(); // for printing capacity of the offices in each building
    void printSuitableClassrooms(int); // for printing suitable classrooms that means number of student in the class is less than the capacity of the classroom.
    University(const University&); // copy constructor
    University& operator=(const University&); //assigment operator overload
    ~University(); //destructor of university class
};










#endif
