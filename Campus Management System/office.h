/* Cengiz Demiray – 2526960
I read and accept the submission rules and the extra rules specified in each question. This is my own work that is done by myself only */
#ifndef OFFICE_H
#define OFFICE_H
#include "room.h"
enum office_t {None=0,CoordinatorOffice, StandartOffice, SharedOfficeFor2People, SharedOfficeFor3People, SharedOfficeFor10People};
//Office class is a subclass of room, therefore it can access the member variable of room class
class Office :public Room
{
private: //member variables of the Office class
    office_t office_type;
    int num_people;
    char *office_name;
    int capacity;
public: //member functions
    Office(); //default constructor
    Office(char [], int, office_t,int); //parametrized constructor
    Office(const Office&); // copy constructor
    ~Office(); // destructor, office has heap variable, if there is not, this function is not necessary
    Office& operator=(const Office& ); //assigment operator overload
    // from 19 to 28, setter and getter functions of the member variables
    void setOfficeType(office_t);
    void setNumberofPeople(int);
    void setCapacity();
    void setOfficeName();
    int getOfficeType() override;
    int getType() override;
    int getNumberofPeople() override;
    int getCapacity() override;
    char* getOfficeName();
    void printRoom () override; // room class has same function, but when object is the instance of office, do not care the function that is in the room class, implement this function
    int isFull(); // for checking whether office is full or not

};





#endif
