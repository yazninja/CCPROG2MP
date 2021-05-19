/*
    LASTNAME1, FIRSTNAME1: Grasparil, David Nikolai 	SECTION1: S15    
    
	LASTNAME2, FIRSTNAME2: Ligot, Yazle Sean      		SECTION2: S15    

	DATE SUBMITTED      : May 19.2021
	
	Do not forget to ENCODE your name/s, section/s and date on the space indicated above.
		
	CCPROG2 MP Solution for: Challenge #7 
	
	Note that if you compile JUST this file only, you will get an error that says "undefined
	reference to WinMain" (for DEVCPP users).  	  
	
	You'll have to include this file first in main-NUMBER.c via #include, and then it is the 
	main-NUMBER.c that you you should compile to produce main-NUMBER.exe file.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    TO DO: change the #include below to your own file/solution. You are not allowed to include other files.
*/
#include "C6-18.h"


/*****************************************************************************************************
    WARNING!!!   WARNING!!!   WARNING!!!    
	
	YOU ARE NOT ALLOWED TO DEFINE the other functions aside from Read_COVID_Data() in this file.
	
	VIOLATION OF THIS RESTRICTION WILL RESULT TO A DEDUCTION OF 10 points!		 
*****************************************************************************************************/



/*
	TO DO: Implement Read_COVID_Data().
	
	       Reads text file.
*/
int
Read_COVID_Data(char *param_country, country *ptrData)  /* TO DO: fill up the parameter data type. */
{
	/* Declare your own local variables. */	
	FILE *fp;
  	int i=0;
	string filename = "CHD/";
	/* Document your solution with sensible inline comments. */
	
	strcat(filename,param_country);
	strcat(filename,".txt");
	fp = fopen(filename, "r");
	if(fp != NULL)
	{
		strcpy(ptrData->name,param_country);
		printf("%s\n",ptrData->name);
		while(fscanf(fp,"%s %d %d %ld %f",ptrData->daily[i].date, &ptrData->daily[i].cases, &ptrData->daily[i].deaths,&ptrData->population, &ptrData->lifeExpectancy) == 5)
			i++;
		ptrData->count = i;
		fclose(fp);
		return 1;
	}
	fprintf(stderr,"No data for %s\n", param_country);
   return 0;  /* Don't forget the return statement. Replace 888 with the appropriate value. */   
}






/*******************************************************************************
    WARNING!!!   WARNING!!!   WARNING!!!    
	
	YOU ARE NOT ALLOWED TO DEFINE the main() function in this file.  
   
	VIOLATION OF THIS RESTRICTION WILL RESULT TO A DEDUCTION OF 10 points!		 
********************************************************************************/


