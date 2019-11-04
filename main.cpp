/**
*
* _ NAME           : DATE MANAGEMENT.
*
* _AUTHOR          : MARRAKCHI Ghassen.
*
* _VERSION         : BETA.
*
* _TOPIC           : Date Management interface.
*
* _PARADIGM        : OO.
*
* _DEFINED CLASSES : Date.
*
**/
#include <iostream>
#include <fstream>
#include "Date.h"
#include "SURCHAGE.h"

/* _NAMESPACE_ */
using namespace std;

/* _MAIN FUNCTION_ */
int main()
{
    cout << "---------------" << endl;
    cout << "DATE MANAGEMENT" << endl;
    cout << "---------------" << endl << endl;

    /* _WELCOMING & EXPLANATION_ */
    Date::mainInfo();

    /* _USER INTERACTION_ */
    int choice1(1);

    while(choice1 != 0){
        Date::menu();
        cout << "Your Choice : _ ";
        cin >> choice1;
        cin.ignore();
        cout << endl;

        switch(choice1){
        case 1 :
            {
                /* _COMPARING TWO DATES_ */
                Date d1, d2;
                cout << "Date1 :" << endl;
                Date::inDate(d1);
                cout << "Date2 :" << endl;
                Date::inDate(d2);
                cout << "Date 1 :" << d1 << endl;
                cout << "Date 2 :" << d2 << endl << endl;

                if(d1 > d2)
                    cout << "Date1 comes after Date2!" << endl;
                else if (d1 < d2)
                    cout << "Date1 comes before Date2!" << endl;
                else
                    cout << "It's the same moment in life!" << endl;
            }
            break;
        case 2 :
            {
                /* _ADDING DAYS TO DATE_ */
                Date d;
                int days(0);
                cout << "Date :" << endl;
                Date::inDate(d);

                cout << "How much days you want to add ? _";
                cin >> days;
                cin.ignore();

                d+=days;

                cout << "The targeted moment in life is : " << d << endl;
            }
            break;
        case 3 :
            {
                /* _DATE DATABASE_ */
                int choice2(1);

                while(choice2 != 3){
                    Date::menuDatabase();
                    ifstream fileReading("Date_Database.txt");
                    Date::printDatabase(fileReading);

                    cout << "Your Choice : _ ";
                    cin >> choice2;
                    cin.ignore();
                    cout << endl;

                    switch(choice2){
                    case 1 :
                        {
                            /* _ADD DATE_ */
                            ofstream fileWriting("Date_Database.txt");
                            if(!fileWriting){
                                cout << "Error File!" << endl;
                            }

                            Date d;
                            cout << "Date :" << endl;
                            Date::inDate(d);

                            fileWriting << d << endl;

                            fileWriting.close();
                        }
                        break;
                    case 2 : { /* _MAIN MENU_ */ }
                        break;
                    case 0 :
                        {
                            /* _QUITTING_ */
                            choice2=2;
                            choice1=0;
                            cout << endl << "---------------" << endl;
                            cout << "THANKS FOR YOUR VISIT!" << endl;
                            cout << "---------------";
                            exit(EXIT_SUCCESS);
                        }
                        break;
                    default :
                        {
                            /* _TYPING ERROR_ */
                            cout << "***" << endl;
                            cout << "Please verify your entry !" << endl;
                            cout << "***" << endl;
                        }
                        break;
                    }
                }
            }
            break;
        case 0 :
            {
                /* _QUITTING_ */
                cout << endl << "---------------" << endl;
                cout << "THANKS FOR YOUR VISIT!" << endl;
                cout << "---------------";
                exit(EXIT_SUCCESS);
            }
            break;
        default :
            {
                /* _TYPING ERROR_ */
                cout << "***" << endl;
                cout << "Please verify your entry !" << endl;
                cout << "***" << endl;
            }
            break;
        }
    }

    /* _QUITTING_ */
    exit(EXIT_SUCCESS);
}
