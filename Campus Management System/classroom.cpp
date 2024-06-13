/* Cengiz Demiray – 2526960
I read and accept the submission rules and the extra rules specified in each question. This is my own work that is done by myself only */
#include<iostream>
#include"classroom.h"
using namespace std;
Classroom::Classroom() //default constructor
{
    capacity = -1;
}
Classroom::Classroom(char name[], int floor_no, int capacity) : Room(name,floor_no)
//parametrized constructor, that calls the parametrized constructor of Room class.
{
    this->capacity = capacity;
}
void Classroom::setCapacity(int capacity) // for setting capacity of class
{
    this->capacity = capacity;
}

int Classroom::getType() // type of the class is 1
{
    return 1;
}

int Classroom::getCapacity() //for getting capacity of the class
{
    return capacity;
}
Classroom::Classroom(const Classroom& classroom) // copy constructor
{
    name = new char[100];
    strcpy(name,classroom.name);
    floor_no = classroom.floor_no;
    this->capacity = classroom.capacity;
}
Classroom& Classroom::operator=(const Classroom& classroom) //assigment operator overload
{
    if(this==&classroom)
        return *this;
    delete [] name;
    name = new char [100];
    strcpy(name,classroom.name);
    floor_no = classroom.floor_no;
    capacity = classroom.capacity;
    return *this;
}
Classroom::~Classroom() // destructor for Classroom objects, if there is not any heap variable, this function is not needed.
{
    delete [] name;
}

int Classroom::checkSuitability(int num_students)
{ // for checking whether classroom has empty place based on the number of students that is given as a parameter to the function.
    if(num_students>=capacity)
        return 0; // there is not any empty spot
    return 1;
}
 void Classroom::printRoom () // for printing Classroom objects information
{
    cout<<"Room name: "<<name<<endl;
    cout<<"Floor No: "<<floor_no<<endl;
    cout<<"Capacity of the class: "<<capacity<<endl;
}


