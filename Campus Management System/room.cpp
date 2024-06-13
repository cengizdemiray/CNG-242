/* Cengiz Demiray – 2526960
I read and accept the submission rules and the extra rules specified in each question. This is my own work that is done by myself only */
#include <iostream>
#include<cstring>
#include "room.h"
using namespace std;
Room::Room() // default constructor
{
    name = new char [100];
    strcpy(name,"Not Provided");
    floor_no = -1;
}
Room::Room(char name [], int floor_no) //parametrized constructor
{
    this->name = new char[100];
    strcpy(this->name,name);
    this->floor_no = floor_no;
}
Room::Room(const Room& room) //copy constructor
{
    name = new char[100];
    strcpy(name,room.name);
    floor_no = room.floor_no;

}
Room::~Room() // destructor
{
    delete [] name;
}
void Room::setName(char name []) //member function that sets name
{
    strcpy(this->name,name);
}
char* Room::getName() // for getting name
{
    return name;
}
void Room::setFloorNo(int floor_no) // for setting the floor no
{
    this->floor_no = floor_no;

}

int Room::getFloorNo() // for getting the floor no
{
    return floor_no;
}
int Room::getType() // actually this is specialized at the office and classroom because room does not have type, only classroom and office have type.
{
    return -1;
}
int Room::getCapacity() // for getting capacity, this is specialized in the office.cpp
{
    return -1;
}
int Room::getNumberofPeople() // for getting how many number of people exist in the class. This is specialized at the classroom.cpp
{
    return -1;
}

void Room::printRoom() // printing information of room
{
    cout<<"Room name:"<<name<<endl;
    cout<<"Floor no:"<<floor_no<<endl;
}
Room& Room::operator=(const Room& room) // assigment operator overload
{
    if(this== &room)
    {
        return *this;
    }
    delete[] name;
    name = new char [100];
    strcpy(name,room.name);
    floor_no= room.floor_no;
    return *this;
}
int Room::getOfficeType() // this is specialized in the office.cpp
{
    return -1;
}




