/*
    LASTNAME1, FIRSTNAME1:  
    SECTION1            :    
    
	LASTNAME2, FIRSTNAME2: 
    SECTION2             :    
    
	
	DATE SUBMITTED      :
	
	CCPROG2 MP Solution for: Challenge #5     
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
	FOR THIS CHALLENGE C5 ONLY:
	
		You may use the atol() standard library function for converting a string to a long integer.
		Do an internet search on your own to find out more about this function.
	
	Example Usage:
	
		char str[5] = "12345";
		long int x;
	
		x = atol(str);      // x gets the value 12345 
		printf("%ld\n", x); // will print the number 12345	
		
	HINT: Use the atol() function to extract the numeric values of year, month and day from 
	 	  a date stored as a string, for example, "2020-03-21".  The numeric year = 2020,
	 	  numeric month = 3, numeric day = 21.	 	  
*/


/*
	You may define helper functions that you need in this file.	
*/
// month(){
//   string dMonth;

//   if(date == 01){
//     strcpy(dMonth,"Jan")
//   }
//   else if(date == 02){
//     strcpy(dMonth,"Feb")
//   }
//   else if(date == 03){
//     strcpy(dMonth,"Mar")
//   }
//   else if(date == 04){
//     strcpy(dMonth,"Apr")
//   }
//   else if(date == 05){
//     strcpy(dMonth,"May")
//   }
//   else if(date == 06){
//     strcpy(dMonth,"Jun")
//   }
//   else if(date == 07){
//     strcpy(dMonth,"Jul")
//   }
//   else if(date == 08){
//     strcpy(dMonth,"Aug")
//   }
//   else if(date == 09){
//     strcpy(dMonth,"Sep")
//   }
//   else if(date == 10){
//     strcpy(dMonth,"Oct")
//   }
//   else if(date == 11){
//     strcpy(dMonth,"Nov")
//   }
//   else if(date ==  12){
//     strcpy(dMonth,"Dec")
//   }
// }
void formatDate(StrDate date, long int * month, long int * day, long int * year)
{
  year = atol(date);
  month = atol(date);
  day = atol(date);
}
void monthlyTotal()
void printReport(char * name,)
{
  printf("%s\n%ld\n%f", name,population,lifeExpectancy);
}
/*
	Describe briefly what this function will do.
*/
void
COVID_Monthly_Statistics(char * param_country, country Data) /* TO DO: fill up the parameter data type. */
{
	/* Declare your own local variables. */
	
  long month, day, year;
	/* Document your solution with inline comments. */
	
	/* You may call the helper function(s) you defined above. */
					
}


/*--- THE END ---*/

