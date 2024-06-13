/* Cengiz Demiray – 2526960
I read and accept the submission rules and the extra rules specified in each question. This is my own work that is done by myself only */
#ifndef ROOM_H
#define ROOM_H
class Room
{
protected: // member vairable of Room
    //variables type are protected for using them in the subclasses.
    char *name;
    int floor_no;
public: // member functions
    Room(); // default constructor
    Room(char [],int); // parametrized constructor
    Room(const Room &); // copy constructor
    ~Room(); // destructor for the room class
    Room& operator =(const Room&); // assigment operator overload
    void setName(char []); // for setting name of the room
    char* getName(); // for getting the name of the room
    void setFloorNo(int); //for setting floor no of room
    int getFloorNo(); // for getting the floor no of room
    virtual int getNumberofPeople();
    virtual int getType();
    virtual int getCapacity();
    virtual void printRoom();
    virtual int getOfficeType();
};
#endif
