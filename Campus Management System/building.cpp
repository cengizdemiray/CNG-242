/* Cengiz Demiray – 2526960
I read and accept the submission rules and the extra rules specified in each question. This is my own work that is done by myself only */
#include<iostream>
#include "building.h"
using namespace std;
Building::Building()
{
    build_name = new char [100];
    strcpy(build_name,"Not Provided");
    size = -1;
    number_of_rooms =0;
}
Building::Building(char name [], int size)
{
    build_name = new char [100];
    strcpy(build_name,name);
    this->size = size;
    number_of_rooms =0;
}
void Building::addRoom(char name [], int floor_no, int type)
{
    if(type==1)
    {
        int capacity;
        cout<<"Enter the size of the class: "<<endl;
        cin>>capacity;
        rooms[number_of_rooms] = new Classroom(name,floor_no,capacity);
        number_of_rooms++;
    }if(type==2){
        int people,input;
        int capacity[] = {0,1,1,2,3,10};
        cout<<"[1] Coordinator Office"<<endl;
        cout<<"[2] Standard Office"<<endl;
        cout<<"[3] Shared Office for 2 people"<<endl;
        cout<<"[4] Shared Office for 3 people"<<endl;
        cout<<"[5] Shared Office for 10 people"<<endl;
        cout<<"Please enter the office type: "<<endl;
        cin >> input;
        office_t office_type = office_t(input);
        cout<<"Please enter how many people exist in the office: "<<endl;
        cin>>people;
        while(people>capacity[input])
        {
            cout<<"Invalid number of people! Enter again: "<<endl;
            cin>>people;
        }
        rooms[number_of_rooms] = new Office(name,floor_no,office_type,people);
        number_of_rooms++;
    }

}
void Building::printRooms()
{
    cout<<"The rooms in the "<<build_name<<endl;
    for(int i=0;i<number_of_rooms;i++)
    {
        cout<<endl;
        rooms[i]->printRoom();
        cout<<endl;
    }
}
void Building::setBuildingName(char name[])
{
    strcpy(build_name,name);
}
void Building::setSize(int size)
{
    this->size = size;
}

void Building::setNumberofRooms(int value)
{
    number_of_rooms = value;
}
char* Building::getBuildingName()
{
    return build_name;
}
int Building::getSize()
{
    return size;
}
int Building::getNumberofRooms()
{
    return number_of_rooms;
}
void Building::printBuilding()
{

    cout<<"The build name is: "<<build_name<<endl;
    cout<<"The size of the "<<build_name<<": "<<size<<endl;
    cout<<"Number of rooms in the "<<build_name<<": "<<number_of_rooms<<endl;
    cout<<endl;
}
void Building::printRoomsbyType(int type)
{
    for(int i=0; i<number_of_rooms;i++)
    {
        cout<<endl;
        if(rooms[i]->getType()==type)
            rooms[i]->printRoom();
        cout<<endl;
    }
}
int Building::getNumberofClassroom()
{
    int counter =0;
    for(int i=0;i<number_of_rooms;i++)
    {
        if(rooms[i]->getType()==1)
            counter++;
    }
    return counter;
}
int Building::getTotalCapacity()
{
    int totalcapacity=0;
    for(int i=0;i<number_of_rooms;i++)
    {
        if(rooms[i]->getType()==2)
        {
            totalcapacity+= rooms[i]->getCapacity();
        }
    }
    return totalcapacity;
}
int Building::getNumberofOffice()
{
    int counter =0;
    for(int i=0;i<number_of_rooms;i++)
    {
        if(rooms[i]->getType()==2)
        {
            counter++;
        }
    }
    return counter;
}
void Building::printAvailableOffice()
{
    for(int i=0;i<number_of_rooms;i++)
    {
        if(rooms[i]->getType()==2 && rooms[i]->getNumberofPeople()<rooms[i]->getCapacity())
        {
            rooms[i]->printRoom();
            cout<<endl;
        }
    }
}
void Building::printSuitableClassrooms(int student)
{
    for(int i=0;i<number_of_rooms;i++)
    {
        if(rooms[i]->getType()==1 && student<rooms[i]->getCapacity())
            rooms[i]->printRoom();
        cout<<endl;
    }
}
Building::~Building()
{
    delete [] build_name;
    for(int i=0; i<number_of_rooms;i++)
    {
        delete rooms[i];
    }
}
Building::Building(const Building& build) //copy constructor
{
    build_name = new char[100];
    strcpy(build_name,build.build_name);
    size = build.size;
    number_of_rooms = build.number_of_rooms;
    for(int i=0; i<number_of_rooms;i++)
    {
        if(build.rooms[i]->getType()==1)
        {
            rooms[i] = new Classroom(build.rooms[i]->getName(),build.rooms[i]->getFloorNo(),build.rooms[i]->getCapacity());
        }else if(build.rooms[i]->getType()==2)
        {
            rooms[i] = new Office (build.rooms[i]->getName(), build.rooms[i]->getFloorNo(), office_t(build.rooms[i]->getOfficeType()), build.rooms[i]->getNumberofPeople());
        }
    }
}
Building& Building::operator=(const Building& build)
{
    if(this==&build)
        return *this;
    delete [] build_name;
    for(int i=0;i<number_of_rooms;i++)
    {
        delete rooms[i];
    }
    build_name = new char[100];
    size = build.size;
    number_of_rooms=build.number_of_rooms;
    for(int i=0; i<number_of_rooms;i++)
    {
        if(build.rooms[i]->getType()==1)
        {
            rooms[i] = new Classroom();
            *rooms[i]=*build.rooms[i];
        }else if(build.rooms[i]->getType()==2)
        {
            rooms[i] = new Office();
            *rooms[i] = *build.rooms[i];
        }
    }
    return *this;
}



