/*
    ASTNAME1, FIRSTNAME1: Grasparil, David Nikolai 		SECTION1: S15    
    
	LASTNAME2, FIRSTNAME2: Ligot, Yazle Sean      		SECTION2: S15    

	DATE SUBMITTED      : May 19.2021
	
	Do not forget to ENCODE your name/s, section/s and date on the space indicated above.
		
	CCPROG2 MP Solution for: Challenge #8 
	
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



/*
	Challenge #8 is not trivial.  
	
	Apply divide-and-conquer technique by breaking the logic of your C8 solution as a collection of functions.
	
	Define your helper functions after this comment.

	Make sure to include comments that indicate what each function is supposed to do.  

	Add sensible inline comments to help the checker understand the logic of your codes.
	
	Don't forget to encode the function prototypes in C6-NUMBER.h header file.
*/


void 
selectionSort(country cArr[], int nCountry)
{
	int i, j, key; 
  string kName; 
  country temp;
	
	for (i = 0; i < nCountry - 1; i++)
	{
		strcpy(kName, cArr[i].name);

		for (j = i + 1; j < nCountry ; j++)
    	{
			strcpy(kName, cArr[i].name);

			if (strcmp(kName,cArr[j].name) < 0)
				key = j;
		}
		temp = cArr[key];
		cArr[key] = cArr[i];
		cArr[i] = temp;
	}
}

void 
printToFile(country cArr[], int nCountry, char * file_output_name)
{
	FILE *fpw;
	int i,j,tCases,tDeaths;
	float fCases, fDeaths;
	fpw = fopen(file_output_name, "w");
	for(i = 0; i < nCountry; i++)
	{
		for(j = 0; j < cArr[i].count; j++)
		{
			tCases += cArr[i].daily[j].cases;        //Computes total cases
			tDeaths += cArr[i].daily[j].deaths;      //Computes total deaths
		}
		fCases = (tCases / cArr[i].population) * 100;
		fDeaths = (tDeaths / cArr[i].population) * 100;
		fprintf(fpw,"%-35s%10ld\t%10d\t%10.6f%10d%10.6f\n", cArr[i].name, cArr[i].population,tCases,fCases,tDeaths,fDeaths);
	}
	fclose(fpw);
}

/*
The function should write SIX columns of values listed below into an output text file named param_output_filename. The 
output data should be in alphabetical order by country name. 
1. country name
2. population
3. total number of cases
4. percentage of the number of cases with respect to the population
5. total number of deaths
6. percentage of the number of deaths with respect to the population
The percentage values should be printed as a floating point with six digits after the decimal point. You are free to decide on how 
much space you would like to put in between columns.

*/


/*
	TO DO: Implement Stats_C8().  Call the helper functions that you defined above.
      
	  	   Replace this comment with a brief description of what the function will do.
*/
int 
Stats_C8(char *param_output_filename, char *param_input_filename)
{
	/* Declare your own local variables. */
	FILE *fpr;
  	int i=0;
	string country_name;
	country cArray[NUM_COUNTRIES];
	/* Document your solution with sensible inline comments. */
	fpr = fopen(param_input_filename, "r");
	if(fpr != NULL)
	{
		while(fscanf(fpr,"%s",country_name) == 1)
		{
			if(Read_COVID_Data(country_name,&cArray[i]) == 1) /*read Covid data*/
				i++;
		}
			
		printf("NUM: %d\n", i);
		selectionSort(cArray,i); /*call sort algorithm*/
		printToFile(cArray,i,param_output_filename);
    	
		fclose(fpr);
		return 1;
	}
	fprintf(stderr,"%s file not found\n", param_input_filename);	  
	return 0;  /* Don't forget the return statement. Replace 888 with the appropriate value. */   
}



/*******************************************************************************
    WARNING!!!   WARNING!!!   WARNING!!!    
	
	YOU ARE NOT ALLOWED TO DEFINE the main() function in this file.  
   
	VIOLATION OF THIS RESTRICTION WILL RESULT TO A DEDUCTION OF 10 points!		 
********************************************************************************/

