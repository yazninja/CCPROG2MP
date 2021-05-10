/*
    LASTNAME1, FIRSTNAME1: Grasparil, David Nikolai 
    SECTION1            :  S15
    
	LASTNAME2, FIRSTNAME2: Ligot, Yazle Sean
    SECTION2             : S15   
    
	
	DATE SUBMITTED      :  May 10,2021
	
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
    #include "C2-18.h"

	#define C2DEFINED (1) 
#endif


/*
  Search the structure for data contained in the date provided using binary search method.
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
			found = 1; // found the date matching the parameter
		else if(strcmp(param_date, Data.daily[mid].date) < 0)
			high = mid -1; //decreases the size of the range by decreasing the upper value
		else
			low = mid + 1; //decreases the size of the range by increasing the lower value
	}
	if (found)
		return mid;
	else
		return -1;  // not found	
}


/* Do NOT define other functions in this file. */


/*--- THE END ---*/


