/*
    LASTNAME1, FIRSTNAME1: Grasparil, David Nikolai 
    SECTION1            :  S15
    
	LASTNAME2, FIRSTNAME2: Ligot, Yazle Sean
    SECTION2             : S15   
    
	
	DATE SUBMITTED      :  May 10,2021
	
	CCPROG2 MP Solution for: Challenge #3     
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#ifndef C2DEFINED
	/*
		TO DO: replace NUMBER in the #include below with your own group number.  Do NOT edit the other lines between
		#ifndef to #endif
	*/
    #include "C2-18.h"

	#define C2DEFINED (1) 
#endif


/*
	Describe briefly what this function will do.
  Copy the country name to the country structure then fill the  day structure with inforamtion. While all are successful, the program moves to the next day.
*/
void
Input_COVID_Data( char * param_country, country * ptrData )  /* TO DO: fill up the parameter data type. */
{
	/* Declare your own local variables. */
	int i = 0;
	/* Document your solution with inline comments. */
	strcpy(ptrData->name, param_country); // copy country name
	while (scanf("%s %d %d %ld %f ", ptrData->daily[i].date, &ptrData->daily[i].cases, &ptrData->daily[i].deaths,&ptrData->population, &ptrData->lifeExpectancy) == 5) // copy data from country file
		i++; // increase day count
	ptrData->count = i; // set total days recorded to country count
}


/* Do NOT define other functions in this file. */


/*--- THE END ---*/

