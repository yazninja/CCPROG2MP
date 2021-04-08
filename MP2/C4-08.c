/*
    LASTNAME1, FIRSTNAME1:  
    SECTION1            :    
    
	LASTNAME2, FIRSTNAME2: 
    SECTION2             :    
    
	
	DATE SUBMITTED      :
	
	CCPROG2 MP Solution for: Challenge #4     
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
int
COVID_Search( StrDate param_date, country Data) /* TO DO: fill up the parameter data type. */
{
	/* Declare your own local variables. */
	int low = 0, high = Data.count -1, mid;
	int found = 0;
	/* Document your solution with inline comments. */
	while(!found && low <= high)
	{
		mid = (low + high) /2;
		if(strcmp(param_date, Data.daily[mid].date) == 0)
			found = 1;
		else if(strcmp(param_date, Data.daily[mid].date) < 0)
			high = mid -1;
		else
			low = mid + 1;
	}
	if (found)
		return mid;
	else
		return -1;  // not found	
}


/* Do NOT define other functions in this file. */


/*--- THE END ---*/


