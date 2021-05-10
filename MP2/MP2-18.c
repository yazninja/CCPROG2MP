/*
    LASTNAME1, FIRSTNAME1: Grasparil, David Nikolai 
    SECTION1            :  S15
    
	LASTNAME2, FIRSTNAME2: Ligot, Yazle Sean
    SECTION2             : S15   
    
	
	DATE SUBMITTED      :  April 8,2021
	
	CCPROG2 MP2 main function module for testing Challenge C2, C3, C4 and C5.
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
	TO DO: replace NUMBER in the #include below with your own group number.  
*/  
#include "C3-18.c"
#include "C4-18.c"
#include "C5-18.c"


/*
	Helper function for testing solution to C4.
*/
void 
Test_Search(StrDate date, country Data)  /* TO DO: fill up the parameter data type. */
{
	int index;
	
	index = COVID_Search(date, Data);
	if (index >= 0) // data found
		printf("%s %d %d\n", date, Data.daily[index].cases, Data.daily[index].deaths ); /* TO DO: print the new_cases and new_deaths values on this date. */
	else
		printf("%s NOT FOUND!\n", date);	
}



int
main()
{
	char param_country[50] = "PHILIPPINES";	// TO DO: Test first your solution using PHILIPPINES.TXT as input data.
	                                        //        Once you're sure it works, test your solution using data for other countries.
	                                        //        Replace this string definition with another country name.
	                                        
    country Data;  /* TO DO: fill-up the data type of Data -- it should be the typedef alias in Step 5 of Challenge #2. */
	//int index;
	
	/* you may add your own local variable */
	
	// test C3 solution
	Input_COVID_Data(param_country,  &Data);
	
	printf("**TEST-C3**\n");
	printf("%s\n", Data.name);  /* TO DO: print country. */
	printf("%ld\n", Data.population);  /* TO DO: print population. */ 
	printf("%.2f\n", Data.lifeExpectancy);  /* TO DO: print life_expectancy */
	printf("%s %d %d\n", Data.daily[Data.count-1].date, Data.daily[Data.count-1].cases, Data.daily[Data.count-1].deaths); /* TO DO: print last row of COVID-19 data (date, new_cases and new_deaths). */
	printf("\n\n");
	
		
	// test C4 solution
	printf("**TEST-C4**\n");
	Test_Search("2019-01-01", Data);  // no data on this date
	Test_Search("2020-10-10", Data);
	Test_Search("2021-03-21", Data);
	Test_Search("2021-04-01", Data);  // no data on this date
	printf("\n\n");
	
	// test C5 solution
	printf("**TEST-C5**\n");
	COVID_Monthly_Statistics(param_country, Data);
		
	return 0;
}

