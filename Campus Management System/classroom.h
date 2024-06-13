/* Cengiz Demiray – 2526960
I read and accept the submission rules and the extra rules specified in each question. This is my own work that is done by myself only */
#ifndef CLASSROOM_H
#define CLASSROOM_H
#include "room.h"
//classroom is a subclass of the Room class
class Classroom :public Room
{
private: //member variable of the classroom
    int capacity;

public:
    Classroom(); // default constructor
    Classroom(char name [],int,int); // parametrized constructor
    Classroom(const Classroom&); // copy constructor
    Classroom& operator=(const Classroom&); // assigment operator overload
    ~Classroom(); // destructor
    void setCapacity(int); // for setting capacity of the class
    int getType() override; //  override, that means same function exist in the class (Room), but do not interested with that function, when object is an instance of class object, take care with this one.
    int getCapacity() override;  // for getting capacity
    int checkSuitability(int); // for checking wheter class have empty places
    void printRoom () override; // for printing Class, again do not care printRoom in the Room.cpp
};







#endif