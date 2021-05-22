/*
    LASTNAME1, FIRSTNAME1: Grasparil, David Nikolai 	SECTION1: S15    
    
	LASTNAME2, FIRSTNAME2: Ligot, Yazle Sean      		SECTION2: S15    

	DATE SUBMITTED      : May 20,2021
	
	Do not forget to ENCODE your name/s, section/s and date on the space indicated above.
		
	CCPROG2 MP Solution for: Challenge #9 
	
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
	Challenge #9 is not trivial.  
	
	Apply divide-and-conquer technique by breaking the logic of your C9 solution as a collection of functions.
	
	Define your helper functions after this comment.  
	
	Make sure to include comments that indicate what each function is supposed to do.  

	Add sensible inline comments to help the checker understand the logic of your codes.
	
	Don't forget to encode the function prototypes in C6-NUMBER.h header file.
*/
int getContinent (char * country, char * continent, FILE *fp)
{
	string tempCountry, tempContinent;
	while(fscanf(fp,"%s %s", tempContinent, tempCountry) == 2)
		if(strcmp(country,tempCountry) == 0)
		{
			strcpy(continent,tempContinent);
			return 1;
		}
	return 0;

}
Read_Continent_Data(char * continent_name, continent world[], int nContinents, FILE *fp)
{
	country region[NUM_COUNTRIES];
	string tempCountry, tempContinent;
	int i, count=0;
	for(i=0; i < nContinents; i++) // check if continent exists
		if(strcmp(continent_name,world[i].name) == 0)
			return;
	fseek(fp, 0, SEEK_SET); // place fp in beggining of file
	for(i=0; i < NUM_COUNTRIES; i++) // store in region[] if same region
	{
		fscanf(fp,"%s %s", tempContinent, tempCountry);
		if(strcmp(tempContinent,continent_name) == 0)
		{
			Read_COVID_Data(tempCountry,&region);
			count++;
		}		
	}
	for (i=0; i < count; i++)
	{
		strcpy(world[nContinents].name, continent_name);
		world[nContinents].population += region[i].population;
		world[nContinents].
	} 

}	
	
	
	





/*
	TO DO: Implement Stats_C9().  Call the helper functions that you defined above.
      
	  	   Replace this comment with a brief description of what the function will do.
*/
int 
Stats_C9(char *param_output_filename, char *param_input_filename)
{
	/* Declare your own local variables. */
	FILE *fp;
	int i=0;
	string country_name, continent_name;
	country cArray[NUM_COUNTRIES];
	continent world[NUM_CONTINENTS];
	/* Document your solution with sensible inline comments. */
	fp = fopen(param_input_filename, "r"); // read file
	if(fp != NULL) // make sure file has data
	{
		while(fscanf(fp,"%s",country_name) == 1) // get country name
		{
			if(getContinent(country_name,continent_name)) //get continent of country
			{
				Read_Continent_Data(continent_name,&world, i, fp); //get all data from the continent and store to world[] if not already added
			}
				
		}
		//sort world[]
		//print world to file
		fclose(fp);
		return 1;
	}

	printf(stderr,"%s file not found\n", param_input_filename);	  
	return 0;  /* Don't forget the return statement. Replace 888 with the appropriate value. */
}



/*******************************************************************************
    WARNING!!!   WARNING!!!   WARNING!!!    
	
	YOU ARE NOT ALLOWED TO DEFINE the main() function in this file.  
   
	VIOLATION OF THIS RESTRICTION WILL RESULT TO A DEDUCTION OF 10 points!		 
********************************************************************************/

