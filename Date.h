/* ___________________________________________________________________________________________ */
/** [.h]
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
#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

/* _INCLUSION_ */
#include <iostream>
#include <fstream>


/* _CLASS DEFINITION_ */
class Date{
    /* _FRIENDS_ */
    //Flux
    friend std::ostream& operator<<(std::ostream&, const Date&);


    /* _ATTRIBUTES_ */
    private :
        int m_Year;
        int m_Month;
        int m_Day;
        int m_Hour;
        int m_Minute;
        int m_Seconde;


    /* _PUBLIC METHODS_ */
    public :
        // _Constructor
        Date(int =1, int =1, int =2000);

        // _Getters
        int getYear()    const;
        int getMonth()   const;
        int getDay()     const;
        int getHour()    const;
        int getMinute()  const;
        int getSeconde() const;

        // _Setters
        Date& setYear   (const int);
        Date& setMonth  (const int);
        Date& setDay    (const int);
        Date& setHour   (const int);
        Date& setMinute (const int);
        Date& setSeconde(const int);

        // _Operators
        Date& operator= (const Date&);
        Date& operator+=(const int);

        // _Formatting Methods
        static Date& format(Date&);

        // _Verifying Methods
        static bool dateVerif(const Date&);

        // _Utilities
        void printLineDate() const;
        static void mainInfo();
        static void menu();
        static void menuDatabase();
        static Date& inDate(Date&);
        static void printDatabase(std::ifstream&);


    /* _PRIVATE METHODS_ */
    private :
        // _Verifying Methods
        static bool leapYearVerif(const int);
        static bool isFeb(const int);
        static bool isThirty(const int);

        // _Utilities
        static int daysOff(const int, const int);

};

#endif // DATE_H_INCLUDED

/* ___________________________________________________________________________________________ */
