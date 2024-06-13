/* Cengiz Demiray – 2526960
I read and accept the submission rules and the extra rules specified in each question. This is my own work that is done by myself only */
#include<iostream>
#include "office.h"
using namespace std;
Office::Office() // implementation of default constructor
{
    office_type = None;
    office_name = new char[100];
    strcpy(office_name,"None");
    num_people = 0;
    capacity =0;
}
Office::Office(char name [], int floor_no, office_t type_office, int people):Room(name,floor_no)
{ // parametrized constructor that calls the parametrized constructor of the Room class
    this->office_type = type_office;
    num_people = people;
    office_name = new char[100];
    switch(type_office)
    {
        case 0:
            strcpy(office_name,"None");
            capacity =0;
            break;
        case 1:
            strcpy(office_name,"Coordinator Office");
            capacity = 1;
            break;
        case 2:
            strcpy(office_name,"Standart Office");
            capacity = 1;
            break;
        case 3:
            strcpy(office_name,"Shared Office For 2 People");
            capacity = 2;
            break;
        case 4:
            strcpy(office_name,"Shared Office For 3 People");
            capacity = 3;
            break;
        case 5:
            strcpy(office_name,"Shared Office For 10 People");
            capacity = 10;
            break;
    }
}
Office::Office(const Office& office) // implementation of copy constructor
{
    name = new char[100];
    name = office.name;
    floor_no = office.floor_no;
    office_type = office.office_type;
    num_people = office.num_people;
    capacity = office.capacity;
    office_name = new char[100];
    strcpy(office_name,office.office_name);
}
Office& Office::operator=(const Office& office) //implementation of assigment operator overload
{
    if(this==&office)
        return *this;
    delete [] name;
    delete [] office_name;
    name = new char[100];
    name = office.name;
    floor_no = office.floor_no;
    office_type = office.office_type;
    num_people = office.num_people;
    capacity = office.capacity;
    office_name = new char [50];
    strcpy(office_name,office.office_name);
    return *this;
}
Office::~Office() // implementation of destructor
{
    delete [] name;
    delete[] office_name;
}

void Office::setOfficeType(office_t type)
{
    office_type = type;
}
void Office::setNumberofPeople(int number)
{
    num_people = number;
}
void Office::setOfficeName()
{
    switch(office_type)
    {
    case 0:
        strcpy(office_name,"None");
        break;
    case 1:
        strcpy(office_name,"Coordinator Office");
        break;
    case 2:
        strcpy(office_name,"Standart Office");
        break;
    case 3:
        strcpy(office_name,"Shared Office For 2 People");
        break;
    case 4:
        strcpy(office_name,"Shared Office For 3 People");
        break;
    case 5:
        strcpy(office_name,"Shared Office For 10 People");
        break;
    }
}
void Office::setCapacity()
{
    switch(office_type)
    {
    case 0:
        capacity=0;
        break;
    case 1:
        capacity=1;
        break;
    case 2:
        capacity=1;
        break;
    case 3:
        capacity=2;
        break;
    case 4:
        capacity=3;
        break;
    case 5:
        capacity=10;
        break;
    }
}
int Office::getOfficeType()
{
    return office_type;
}

int Office::getType()
{
    return 2;
}
int Office::getNumberofPeople()
{
    return num_people;
}
int Office::getCapacity()
{
    return capacity;
}
char* Office::getOfficeName()
{
    return office_name;
}
void  Office::printRoom()
{
    cout<<"Room name: "<<name<<endl;
    cout<<"Floor no: "<<floor_no<<endl;
    cout<<"People in the office: "<<num_people<<endl;
    cout<<"Capacity of the office: "<<capacity<<endl;
    cout<<"Office Type: "<<office_name<<endl;
    int result = isFull();
    if(result)
    {
        cout<<"Office is full!"<<endl;
    }else
    {
        cout<<"Office is not full!"<<endl;
    }
}
int Office::isFull()
{
    if(num_people == capacity)
        return 1;
    return 0;
}









