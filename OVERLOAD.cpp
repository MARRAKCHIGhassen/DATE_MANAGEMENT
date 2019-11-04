/*___________________________________________________________________________________________*/
/** [.cpp]
*
* _AUTHOR    : MARRAKCHI Ghassen
*
* _VERSION   : BETA.
*
* _MODULE    : Overloading Operators.
*
* _OPERATORS : ==/ !=/ </ >/ +.
*
**/
/* _INCLUSION_ */
#include "SURCHAGE.h"
#include "Date.h"


/* _NAMESPACE_ */
using namespace std;


/* _DEFINITIONS_ */
//Comparison
bool operator==(const Date& d1, const Date& d2){
    return ((d1.getSeconde() == d2.getSeconde()) && (d1.getMinute() == d2.getMinute()) && (d1.getHour() == d2.getHour()) &&
            (d1.getDay() == d2.getDay()) && (d1.getMonth() == d2.getMonth()) && (d1.getYear() == d2.getYear())) ? true : false;
}
bool operator!=(const Date& d1, const Date& d2) { return !(d1 == d2); }

bool operator<(const Date& d1, const Date& d2){ return !(d1 > d2); }
bool operator>(const Date& d1, const Date& d2){
    if(d1 != d2){
        if(d1.getYear() < d2.getYear())        return false;
        else if(d1.getMonth() < d2.getMonth()) return false;
        else if(d1.getDay() < d2.getDay())     return false;

        if(d1.getHour() < d2.getHour())            return false;
        else if(d1.getMinute() < d2.getMinute())   return false;
        else if(d1.getSeconde() < d2.getSeconde()) return false;
    }
    return false;
}

//Arithmetic
Date& operator+(Date& d, const int day) { return d+=day; }

/*___________________________________________________________________________________________*/
