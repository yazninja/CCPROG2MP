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

void swapCon(continent *aCon1, continent *aCon2)
{
	continent temp;
			
	temp = *aCon1;
	*aCon1 = *aCon2;
	*aCon2 = temp;
}

void 
sortContinent(continent aConti[], int nContinent)
{
	int i, j, key; 
	
	for (i = 0; i < nContinent - 1; i++)
	{
		key = i;
		printf("%d. continent: %s\n", i, aConti[i].name);
		for (j = i + 1; j < nContinent ; j++)
			if (strcmp(aConti[key].name,aConti[j].name) > 0)
				key = j;

		swapCon(&aConti[i], &aConti[key]);
	}
}



void Read_Continent_Data(char * continent_name, continent world[], int *nContinents, FILE *fp)
{
	country region[NUM_COUNTRIES];
	string tempCountry, tempContinent;
	int i, j, count=0;
	FILE *fC;
	fC = fopen("CHD/CONTINENT-COUNTRY.txt","r");

	// for(i=0; i < *nContinents; i++) // check if continent exists
	// 	if(strcmp(continent_name,world[i].name) == 0)
	// 	{
	// 		printf("DUPLICATE\n");
	// 		return;
	// 	}
		
	for(i=0; i < NUM_COUNTRIES; i++) // store in region[] if same region
	{
		fscanf(fC,"%s %s", tempContinent, tempCountry);
		if(strcmp(tempContinent,continent_name) == 0)
		{
			// printf("%s\n",tempCountry);
			Read_COVID_Data(tempCountry,&region[i]);
			count++;
		}		
	}
	// printf("COUNT: %d", count);
	world[*nContinents].totalCases = 0;
	world[*nContinents].totalDeaths = 0;
	world[*nContinents].population = 0;
	strcpy(world[*nContinents].name, continent_name); // name
	for (i=0; i < count + 1; i++)
	{
		
		world[*nContinents].population += region[i].population; // population
		for(j=0; j < region[i].count; j++)
		{
			//printf("%s\t%d :: %d\n",region[i].name,j, world[*nContinents].totalCases);
			world[*nContinents].totalCases += region[i].daily[j].cases; // cases
			world[*nContinents].totalDeaths += region[i].daily[j].deaths; //deaths
		}
		world[*nContinents].percentCases = (float) world[*nContinents].totalCases / world[*nContinents].population * 100; // percentCases
		world[*nContinents].percentDeaths = (float) world[*nContinents].totalDeaths / world[*nContinents].population * 100; // percentDeaths
	}
	(*nContinents)++; 
}	
	
void setupContinent(sign c[]){
    FILE *fC;
    int i = 0;
    fC = fopen("CHD/CONTINENT-COUNTRY.txt","r");
    while(fscanf(fC,"%s %s", c[i].cont, c[i].countries) == 2){
        i++;
    }
    fclose(fC);
}

int
getContinent(char * country, char * continent, sign list[])
{
    int low = 0, high = NUM_COUNTRIES - 1, mid;
    int found = 0;
    
    while(!found && low <= high)
    {
        mid = (low + high) /2;
        if(strcmp(country, list[mid].countries) == 0)
                found = 1;
        else if(strcmp(country, list[mid].countries) < 0)
            high = mid -1;
        else
            low = mid + 1;
    }
    
    if (found)
    {
        strcpy(continent,list[mid].cont);
        return 1;
    }    
    return 0;     
}

void printContinents(char * file_output, continent world[], int nContinents)
{
	FILE *fpw;
	int i;
	fpw = fopen(file_output, "w");
	for(i = 0; i < nContinents; i++)
		fprintf(fpw,"%-20s%10ld\t\t%10d\t%10.6f\t\t%10d\t%10.6f\n", world[i].name, world[i].population, world[i].totalCases, world[i].percentCases, world[i].totalDeaths, world[i].percentDeaths);
	fclose(fpw);
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
	sign pair[NUM_COUNTRIES];
	continent world[NUM_CONTINENTS];
	/* Document your solution with sensible inline comments. */
	fp = fopen(param_input_filename, "r"); // read file
	if(fp != NULL) // make sure file has data
	{
		while(fscanf(fp,"%s",country_name) == 1) // get country name
		{
			setupContinent(pair);
			if(getContinent(country_name,continent_name,pair)) //get continent of country
				Read_Continent_Data(continent_name,world, &i, fp); //get all data from the continent and store to world[] if not already added	
		}
			
		sortContinent(world, i); //sort world[]
		printf("\nbefore: %d\n", i);
		
		printContinents(param_output_filename, world, i);//print world to file
		printf("\nafter\n");
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

