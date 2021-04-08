/*
    LASTNAME1, FIRSTNAME1: Grasparil, David Nikolai 
    SECTION1            :  S15
    
	LASTNAME2, FIRSTNAME2: Ligot, Yazle Sean
    SECTION2             : S15   
    
	
	DATE SUBMITTED      :  March 28,2021
	
	CCPROG2 MP Solution for: Challenge #1  
        
    
    Do NOT use struct data type yet for this particular challenge.
    
    
	Make sure to have -Wall compiler directive setting on for a strict compiler.
	
	You should run the program's exe file in the command line with input and output (I/O) redirection.    	    
    
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Do NOT include other header files */


/*
    You may declare any typedef that you need below this comment.
*/
typedef char string[256];




/*

	You have to segregate your program's logic into functions.  Non-compliance 
	will result to a 5 point deduction for this Challenge.

	Define your functions below this comment.

    Make sure to include inline documentation in your codes.

*/

/* ReadData - Scans all the needed information from the file provided and stores the size of the list to variable i*/
void ReadData(string date[], int cases[][2], int * population, float * lifeExpectancy, int * i)
{
	while((scanf("%s%d%d%d%f", date[*i], &cases[*i][0], &cases[*i][1], population, lifeExpectancy)) == 5) 
		(*i)++;
}

/* PrintData - Prints the provided data into the required format, calculates for the running total of new_cases & new_deaths */
void PrintData (string date[], int cases[][2], int population, float lifeExpectancy, int n)
{
	int i,totalnew = 0, totaldeaths = 0;
	printf("Popultaton: %d\nLife Expeactancy: %.2f\n\n",population,lifeExpectancy);
	printf("Date\t\tNew Cases\tTotal Cases\tNew Deaths\tTotalDeaths\n");
	for (i=0; i < n; i++)
	{
		totalnew += cases[i][0];
		totaldeaths += cases[i][1];
		printf("%s\t%d\t\t%d\t\t%d\t\t%d\n",date[i], cases[i][0], totalnew, cases[i][1], totaldeaths);
	}
}
int
main()
{
    /* Declare your own local variables. */
    int n=0, population;
    string date[1000];
    int cases[1000][2];
    float lifeExpectancy;
    
    /* Call the functions that you defined. */
    ReadData (date,cases,&population, &lifeExpectancy,&n);
    PrintData (date,cases,population, lifeExpectancy,n);   
	return 0;
}



