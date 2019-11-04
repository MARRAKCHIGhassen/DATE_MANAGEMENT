/*___________________________________________________________________________________________*/
/** [.cpp]
*
* _AUTHOR        : MARRAKCHI Ghassen
*
* _VERSION       : BETA.
*
* _DEFINED CLASS : Date.
*
* _ATTRIBUTES    : Year/Month/Day/Hour/Minute/Second.
*
* _METHODS       :
**
** __FRIENDS : Operator<<.
**
** __PUBLIC  : 1 Constructor/ 6 Getters/ 6 Setters/ 2 Unary Operators/ 1 Formatting (1 Static)/
**             1 Verifying (1 Static)/ 6 Utilities (5 Static).
**
** __PRIVATE : 3 Verifying (3 Static)/ 1 Utility (1 Static).
*
**/
/* _INCLUSION_ */
#include <iostream>
#include <string>
#include "Date.h"


/* _NAMESPACE_ */
using namespace std;


/* _FRIEND_ */
//Flux
ostream& operator<<(ostream& flux, const Date& d) {
    flux << d.m_Day << "/" << d.m_Month << "/" << d.m_Year << " | " << d.m_Hour << ":" << d.m_Minute << ":" << d.m_Seconde;
    return flux;
}


/* _PUBLIC METHODS_ */
// _Constructor
Date::Date(int day, int month, int year) : m_Year(year), m_Month(month), m_Day(day), m_Hour(0), m_Minute(0), m_Seconde(0) {}

// _Getters
int Date::getYear()    const{ return m_Year;    }
int Date::getMonth()   const{ return m_Month;   }
int Date::getDay()     const{ return m_Day;     }
int Date::getHour()    const{ return m_Hour;    }
int Date::getMinute()  const{ return m_Minute;  }
int Date::getSeconde() const{ return m_Seconde; }

// _Setters
Date& Date::setYear(const int year)       { m_Year = year;       return *this; }
Date& Date::setMonth(const int month)     { m_Month = month;     return *this; }
Date& Date::setDay(const int day)         { m_Day = day;         return *this; }
Date& Date::setHour(const int hour)       { m_Hour = hour;       return *this; }
Date& Date::setMinute(const int minute)   { m_Minute = minute;   return *this; }
Date& Date::setSeconde(const int seconde) { m_Seconde = seconde; return *this; }

// _Operators
Date& Date::operator=(const Date &d){
    m_Year    = d.getYear();
    m_Month   = d.getMonth();
    m_Day     = d.getDay();
    m_Hour    = d.getHour();
    m_Minute  = d.getMinute();
    m_Seconde = d.getSeconde();

    return *this;
}
Date& Date::operator+=(const int day) { m_Day+=day; Date::format(*this); return *this; }

// _Formatting Methods
Date& Date::format(Date &d){
    while(!Date::dateVerif(d)){
        int modulo(Date::daysOff(d.getMonth(), d.getYear()));

        if(d.getDay() > modulo){
            d.setDay(d.getDay() - modulo);
            d.setMonth(d.getMonth() + 1);

            if(d.getMonth() > 12){
                d.setYear(d.getYear() + 1);
                d.setMonth(1);
            }
        }
    }
    return d;
}

// _Verifying Methods
bool Date::dateVerif(const Date& d){
    if(d.getMonth() > 12)                                                             return false;
    else if(d.getDay() > 31)                                                          return false;
    else if (Date::isThirty(d.getMonth()) && (d.getDay() > 30))                              return false;
    else if ((Date::isFeb(d.getMonth()) && Date::leapYearVerif(d.getYear())) && (d.getDay() > 29))  return false;
    else if ((Date::isFeb(d.getMonth()) && !Date::leapYearVerif(d.getYear())) && (d.getDay() > 28)) return false;
    else return true;
}

// _Utilities
void Date::printLineDate() const { cout << m_Day << "/" << m_Month << "/" << m_Year << " | " << m_Hour << ":" << m_Minute << ":" << m_Seconde << endl; }
void Date::mainInfo(){
    cout << "This program is an interface to use \"Date\" Structure." << endl;
}
void Date::menu(){
    cout << "1_ Comparing two Dates." << endl;
    cout << "2_ Add days to a Date."  << endl;
    cout << "3_ Date database."       << endl;
    cout << "0_ Quit."                << endl;
}
void Date::menuDatabase(){
    cout << "1_ Add a Date."    << endl;
    cout << "2_ Main Menu."     << endl;
    cout << "0_ Quit."          << endl;
}
Date& Date::inDate(Date& d){
    int entry(0);

    do{
        cout << "_TIME" << endl;
        do{ cout << "Enter Hour : _ "; cin >> entry; cin.ignore();}while((entry >= 24) && (entry < 0));
        d.setHour(entry);
        do{ cout << "Enter Minute : _ "; cin >> entry; cin.ignore();}while((entry >= 60) && (entry < 0));
        d.setMinute(entry);
        do{ cout << "Enter Second : _ "; cin >> entry; cin.ignore();}while((entry >= 60) && (entry < 0));
        d.setSeconde(entry);

        cout << "_DATE" << endl;
        do{ cout << "Enter Day : _ "; cin >> entry; cin.ignore();}while((entry > 31) && (entry < 0));
        d.setDay(entry);
        do{ cout << "Enter Month : _ "; cin >> entry; cin.ignore();}while((entry > 12) && (entry < 0));
        d.setMonth(entry);
        cout << "Enter Year : _ ";
        cin >> entry;
        cin.ignore();
        d.setYear(entry);
    }while(!Date::dateVerif(d));

    return d;
}
void Date::printDatabase(ifstream& file){
    if(file){
        file.seekg(0, ios::beg);

        string line;
        while(getline(file, line)){
            cout << line << endl;
        }
    }
    else{ cout << "No Database available!" << endl; }
}

/* _PRIVATE METHODS_ */
// _Verifying Methods
bool Date::leapYearVerif(const int year) { return ((((year % 4) == 0) && ((year % 100) != 0)) || ((year % 400) == 0)) ? true : false; }
bool Date::isFeb(const int month)        { return (month == 2) ? true : false; }
bool Date::isThirty(const int month)     { return ((month == 4) || (month == 6) || (month == 9) || (month == 11)) ? true : false; }

// _Utilities
int Date::daysOff(const int month, const int year){
    if(leapYearVerif(year) && isFeb(month)) return 29;
    else if(isFeb(month))                   return 28;
    else if(isThirty(month))                return 30;
    else return 31;
}

/*___________________________________________________________________________________________*/
