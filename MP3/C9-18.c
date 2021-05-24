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

/* Sorts the continent array alphabetically using selection sort alogithm */
void sortContinent(continent aConti[], int nContinent)
{
	// Variable Declarations
	continent temp;
	int i, j, key;
	// Selection Sort Alphabetically	
	for (i = 0; i < nContinent - 1; i++)
	{
		key = i;
		for (j = i + 1; j < nContinent ; j++)
			if (strcmp(aConti[key].name,aConti[j].name) > 0)  //compares key and continent array
				key = j;      //index of continent is set to key

		// swap elements
		temp = aConti[i];
		aConti[i] = aConti[key];
		aConti[key] = temp;
	}
}

/* Access the CONTINENT-COUNTRY file and converts it in a pair based array */	
void setupContinent(countryToContinent c[]){
    // Variable Definitions
	FILE *fC; // file pointer fC for file Continent
    int i = 0; 
    fC = fopen("CHD/CONTINENT-COUNTRY.txt","r");
	if(fC != NULL) // check if file exists
	{
		// if 2 variables were scanned, move onto the next element
    	while(fscanf(fC,"%s %s", c[i].cont, c[i].countries) == 2)
        	i++;
    	fclose(fC);
		return; 
	}
	// print to stderr if file cannot be found
	fprintf(stderr, "Cannot find CONTINENT-COUNTRY.txt");

}
	

/* Searches for the continent of the country provided using binary search algorithm*/
int
getContinent(char * country, char * continent, countryToContinent list[])
{
    int low = 0, high = NUM_COUNTRIES - 1, mid;
    int found = 0;
    
    while(!found && low <= high)
    {
        mid = (low + high) /2;
        if(strcmp(country, list[mid].countries) == 0)
                found = 1; // found a matching country in the array
        else if(strcmp(country, list[mid].countries) < 0)
            high = mid -1; // country is before the parameter alphabetically
        else
            low = mid + 1; // country is after the parameter alphabetically
    }
    
    if (found)
    {
        strcpy(continent,list[mid].cont); // copy continent name
        return 1; // return 1 - found
    }    
    return 0; // return 0 - not found    
}

/* Copies continent data to world array */
void Read_Continent_Data(char * continent_name, char * country_name, countryToContinent pair[], continent world[], int *nContinents)
{
	// Variable Declarations
	int i,j;
	country nation;
	// Store Country Data in nation variable
	Read_COVID_Data(country_name,&nation);
	// Search world array for a matching continent name and add contents from nation,
	// If no matching continent, make a new continent and add contents from nation
	for(i=0; i <= *nContinents; i++)
	{
		// check if any match first, then add if there is none
		if(strcmp(world[i].name,continent_name) == 0 || i == *nContinents) 
		{
			strcpy(world[i].name,continent_name); // copy name
			world[i].population += nation.population; // copy population
			for(j=0; j < nation.count; j++) // copy daily data
			{
				world[i].totalCases += nation.daily[j].cases;         //computes total cases from each country to world
				world[i].totalDeaths += nation.daily[j].deaths;       //computes total death from each country to world
			}
			world[i].percentCases = (float) world[i].totalCases / world[i].population * 100; // solve percent of Cases accrd. by population
			world[i].percentDeaths = (float) world[i].totalDeaths / world[i].population * 100; // solve percent of Deaths accrd. by population
		}
		// If a new contnent is added, increase nContinents;
		if(i == *nContinents)
			(*nContinents)++;

	}
}	


/* Prints the sorted array to the file_coutput specified */
void printContinents(char * file_output, continent world[], int nContinents)
{
	// Variable Declarations
	FILE *fpw; // file pointer fpW for file to Write
	int i;
	fpw = fopen(file_output, "w");
	// write data per element of world[]
	for(i = 0; i < nContinents; i++)
		fprintf(fpw,"%-20s%10ld\t\t%10d\t%10.6f\t\t%10d\t%10.6f\n", world[i].name, world[i].population, world[i].totalCases, world[i].percentCases, world[i].totalDeaths, world[i].percentDeaths);
	fclose(fpw);
}
/*
	TO DO: Implement Stats_C9().  Call the helper functions that you defined above.
        
	  	   Compute the Statistics of countries sorted by continent.
*/
int 
Stats_C9(char *param_output_filename, char *param_input_filename)
{
	/* Declare your own local variables. */
	FILE *fp; // file fp for the input_filename
	int i=0;
	string country_name, continent_name;
	countryToContinent pair[NUM_COUNTRIES];
	continent world[NUM_CONTINENTS];
  
	/* Document your solution with sensible inline comments. */
	fp = fopen(param_input_filename, "r"); // read file
	if(fp != NULL) // make sure file has data
	{
		while(fscanf(fp,"%s",country_name) == 1) // get country name
		{
			setupContinent(pair);
			if(getContinent(country_name,continent_name,pair)) //get continent of country
				Read_Continent_Data(continent_name,country_name,pair,world, &i); //get all data from the continent and store to world[] if not already added	
		}
		sortContinent(world, i); //sort world[] alphabetically
		printContinents(param_output_filename, world, i);//print world to file
		fclose(fp);
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

