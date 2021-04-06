/*
    LASTNAME1, FIRSTNAME1:  
    SECTION1            :    
    
	LASTNAME2, FIRSTNAME2: 
    SECTION2             :    
    
	
	DATE SUBMITTED      :
	
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
    #include "C2-08.h"

	#define C2DEFINED (1) 
#endif


/*
	Describe briefly what this function will do.
*/
void
Input_COVID_Data( char * param_country, country * ptrData )  /* TO DO: fill up the parameter data type. */
{
	/* Declare your own local variables. */
	int i = 0;
	/* Document your solution with inline comments. */
	strcpy(ptrData->name, param_country);
	while (scanf("%s %d %d %ld %f", ptrData->daily[i].date, &ptrData->daily[i].cases, &ptrData->daily[i].deaths,&ptrData->population, &ptrData->lifeExpectancy) == 5)
		i++;
	ptrData->count = i;
}


/* Do NOT define other functions in this file. */


/*--- THE END ---*/

