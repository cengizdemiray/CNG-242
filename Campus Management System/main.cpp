/* Cengiz Demiray – 2526960
I read and accept the submission rules and the extra rules specified in each question. This is my own work that is done by myself only */
#include <iostream>
#include"university.h"
#include "building.h"
#include "room.h"
#include "office.h"
#include "classroom.h"
#include "building.h"
using namespace std;
int main()
{
    University *myUniversity = new University("METU NCC"); //initialization of object
    int choice = 1; // choice is randomly set to 1 for entering the while loop at the begining
    char name[10];
    while(choice!=0)
    {
        cout<<"[1] Add a new building to the university"<<endl;
        cout<<"[2] Add a new room to a selected building"<<endl;
        cout<<"[3] Print the buildings in the university"<<endl;
        cout<<"[4] Print the rooms in each building in the university"<<endl;
        cout<<"[5] Print the rooms in each building in the university based on type"<<endl;
        cout<<"[6] Print the total number of classrooms and offices in the university"<<endl;
        cout<<"[7] Print the available offices in each building in the university"<<endl;
        cout<<"[8] Print the total capacity of all the offices"<<endl;
        cout<<"[9] Print the suitable classrooms in the university based on the given number of students"<<endl;
        cout<<"[0] Exit"<<endl<<endl;
        cout<<"Please enter your choice: "<<endl;
        cin>>choice; // choice is entered by the user, for deciding which operation should performed
        if(choice==1) // if choice is 1, adding building to university is performed
        {

            int size;
            cout<<"Please enter name of the building: "<<endl;
            cin>>name;
            cout<<"Please enter size of building: "<<endl;
            cin>>size;
            myUniversity->addBuilding(name,size);
        }
        else if(choice==2) // if the choice is 2, printing the details of the building is performed
        {
            int build_choice,type,floor_no;
            cout<<"Buildings in METU NCC university: "<<endl;
            myUniversity->printBuildings();
            cout<<"Please enter the number of building to which the room should be added: "<<endl;
            cin>>build_choice;
            while(build_choice>myUniversity->getNumberofBuildings()) // if the build choice is out of range display the error mesage
            {
                cout<<"Invalid selection Try again: "<<endl;
                cin>>build_choice;
            }

            cout<<"Please enter the type of room(1: Classroom/ 2: Office): "<<endl;
            cin>>type;
            cout<<"Please enter the name of the new room: "<<endl;
            cin>>name;
            cout<<"Please enter the floor number of the new room: "<<endl;
            cin>>floor_no;
            myUniversity->getSpecificBuilding(build_choice-1).addRoom(name,floor_no,type);
        }
        else if(choice==3) // if choice equals to 3 printing buildings of university is performed
        {
            cout<<"Buildings in the "<<myUniversity->getUniversityName()<<": "<<endl;
            myUniversity->printBuildings();
        }
        else if(choice ==4) // for printing the details of the room at the buildings of the university
        {
            myUniversity->printRooms();
        }
        else if(choice==5) // if choice is 5, printing class or office based on type is performed
        {
            cout<<"[1] Classroom"<<endl;
            cout<<"[2] Office"<<endl;
            int type;
            cout<<"Please enter the type of room to display: "<<endl;
            cin>>type;
            myUniversity->printRoomsByType(type);

        }
        else if(choice ==6) // if choice is equal to 6, printing total office and capacity at the university is performed
        {
            myUniversity->printRoomStatistics();
        }
        else if(choice==7) // if choice is 7, available office will be displayed to screen
        {
            myUniversity->printAvailableOffice();
        }else if(choice==8) // if choice is 8, total capacity of the offices in each building will be displayed
        {
            myUniversity->printTotalCapacityofOffices();
        }else if(choice==9) //if choice is 9, available classroom for the students will be displayed
        {
            int student;
            cout<<"Please enter the number of student: "<<endl;
            cin>>student;
            myUniversity->printSuitableClassrooms(student);
        }else if(choice ==0) // if choice is 0, while loop does not execute for the next cycle, and print the BYEE message to user
        {
            cout<<"Thank you for using the university campus management system"<<endl;
        }else // if choice is not in the interval of 0-9 , error message will be displayed
        {
            cout<<"Invalid choice! "<<endl;
        }
        cout<<endl;
    }
    return 0;
}
