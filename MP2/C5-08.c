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
void Print_EnglishMonth(long int month)
{
	switch (month)
	{
	case 1:		printf("Jan");		break;
	case 2:		printf("Feb");		break;
	case 3:		printf("Mar");		break;
	case 4:		printf("Apr");		break;
	case 5:		printf("May");		break;
	case 6:		printf("Jun");		break;
	case 7:		printf("Jul");		break;
	case 8:		printf("Aug");		break;
	case 9:		printf("Sep");		break;
	case 10:	printf("Oct");		break;
	case 11:	printf("Nov");		break;
	case 12:	printf("Dec");		break;
	}
}
void Print_MonthSummary(long int m, long int fd, long int ld, long int y, int c, int d)
{
	Print_EnglishMonth(m);
	printf("%3ld to %ld, %ld\t%10d%10d\n",fd,ld,y,c,d);
}

/*
	Describe briefly what this function will do.
*/
void
COVID_Monthly_Statistics(char * param_country, country Data) /* TO DO: fill up the parameter data type. */
{
	/* Declare your own local variables. */
	int i=0;
	long int month,day,year,tempmonth, firstday;
	int tCases, tDeaths;
	/* Document your solution with inline comments. */
	
	/* You may call the helper function(s) you defined above. */
	printf("%s\n%ld\n%.2f\n\n",Data.name,Data.population,Data.lifeExpectancy);
	while(i < Data.count)
	{
		tCases = 0;
		tDeaths = 0;
		year = atol(Data.daily[i].date);
		month = atol(Data.daily[i].date + 5);
		day = atol(Data.daily[i].date + 8);
		firstday = day;
		tempmonth = month;
		while(month == tempmonth)
		{
			tCases += Data.daily[i].cases;
			tDeaths += Data.daily[i].deaths;
			day = atol(Data.daily[i].date + 8);
			i++;
			month = atol(Data.daily[i].date + 5);
		}
		Print_MonthSummary(tempmonth,firstday,day,year,tCases,tDeaths);
	}
					
}


/*--- THE END ---*/

