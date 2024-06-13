/* Cengiz Demiray – 2526960
I read and accept the submission rules and the extra rules specified in each question. This is my own work that is done by myself only */
#include<iostream>
#include "university.h"
using namespace std;
University::University() // implementation of default constructor
{
    university_name = new char [100];
    strcpy(university_name,"Undefined");
    numberofBuildings =0;
}
University::University(char name []) //implementation of parametrized constructor
{
    university_name = new char [100];
    strcpy(university_name,name);
    numberofBuildings=0;
}
void University::setUniversityName(char name [])
{ // for setting the name of the university
    strcpy(university_name,name);
}
char* University::getUniversityName()
{ // for getting the university name
    return university_name;
}
int University::getNumberofBuildings()
{ // for getting the number of buildings of university
    return numberofBuildings;
}
void University::addBuilding(char name [], int size)
{ // for adding the building to the university
    builds[numberofBuildings] = new Building(name,size);
    numberofBuildings++;
}
void University::printBuildings()
{ // for printing the details of the builds at the university
    for(int i=0;i<numberofBuildings;i++)
    {
        cout<<"["<<i+1<<"] ";
        builds[i]->printBuilding();
        cout<<endl;
    }
}
Building& University::getSpecificBuilding(int i)
{ // for getting specific building of university based on the function parameter
    return *builds[i];
}
void University::printRooms()
{ // for printing rooms of the building at the university
    for (int i=0;i<numberofBuildings;i++)
    {
        builds[i]->printRooms();
        cout<<endl;
    }
}
void University::printRoomsByType(int type)
{ // for printing the rooms of the office at the university
    for (int i=0;i<numberofBuildings;i++)
    {
        cout<<"Rooms in the building "<<builds[i]->getBuildingName()<<endl<<"according to given type:"<<endl;
        builds[i]->printRoomsbyType(type);
        cout<<endl;
    }
}
void University::printRoomStatistics()
{ // for printing how many class and office exist in the university
    int classroom_count=0,office_count=0;
    for(int i=0; i<numberofBuildings;i++)
    {
        classroom_count+=builds[i]->getNumberofClassroom();
        office_count += builds[i]->getNumberofOffice();
    }
    cout<<"Number of Classroom: "<<classroom_count<<endl;
    cout<<"Number of Office: "<<office_count<<endl;
}
void University::printAvailableOffice()
{
    for(int i=0;i<numberofBuildings;i++)
    {
        cout<<"Avialable offices in the "<<builds[i]->getBuildingName()<<" : "<<endl<<endl;
        builds[i]->printAvailableOffice();
        cout<<endl;
    }
}
void University::printTotalCapacityofOffices()
{
    int total_capacity;
    for(int i=0;i<numberofBuildings;i++)
    {
        total_capacity = builds[i]->getTotalCapacity();
        cout<<"The total office capacity in "<<builds[i]->getBuildingName()<<": "<<total_capacity<<endl<<endl;
    }

}
void University::printSuitableClassrooms(int number)
{
    for(int i=0;i<numberofBuildings;i++)
    {
        cout<<"Available classrooms based on the given number in the "<<builds[i]->getBuildingName()<<" building: "<<endl;
        builds[i]->printSuitableClassrooms(number);
        cout<<endl;
    }
}
University::University(const University& university)
{ //implementation of assigment operator overload
    university_name = new char [100];
    strcpy(university_name,university.university_name);
    numberofBuildings = university.numberofBuildings;
    for(int i=0; i<numberofBuildings;i++)
    {
        builds[i] = new Building(university.builds[i]->getBuildingName(),university.builds[i]->getSize());
    }
}
University& University::operator=(const University& university)
{ //implementation of assigment operator overload
    if(this==&university)
    {
        return *this;
    }
    delete [] university_name;
    for(int i=0;i<numberofBuildings;i++)
    {
        delete builds[i];
    }
    university_name = new char [100];
    strcpy(university_name,university.university_name);
    numberofBuildings = university.numberofBuildings;
    for(int i=0; i<numberofBuildings;i++)
    {
        builds[i] = new Building(university.builds[i]->getBuildingName(),university.builds[i]->getSize());
    }
    return *this;
}
University::~University()
{ // implementation of destructor, string called as university name, and buildings array are deleted
    delete [] university_name;
    for(int i=0; i<numberofBuildings;i++)
    {
        delete builds[i];
    }
}


