/*___________________________________________________________________________________________*/
/** [.h]
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
#ifndef SURCHAGE_H_INCLUDED
#define SURCHAGE_H_INCLUDED

/* _INCLUSION_ */
#include <iostream>
#include "Date.h"


/* _PROTOTYPES_ */
//Comparison
bool operator==(const Date&, const Date&);
bool operator!=(const Date&, const Date&);
bool operator< (const Date&, const Date&);
bool operator> (const Date&, const Date&);

//Arithmetic
Date& operator+(Date&, const int);

#endif // SURCHAGE_H_INCLUDED

/*___________________________________________________________________________________________*/
