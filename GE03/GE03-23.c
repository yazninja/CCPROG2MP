/* 
    ENCODE your Name(s) and Section(s) below.
	    
    lASTNAME1, FIRSTNAME1: Ligot, Yazle Sean S.
	SECTION1: S11
	
	lASTNAME2, FIRSTNAME2: Grasparil, David Nikoli G. 
	SECTION1: S11
	
	
	This is the skeleton file that you need to use as base code for GE03 (Group Graded Exercise)
	on 1D array of strings.
	
	Note that if you compile JUST this program only, you will get an error that says "undefined
	reference to WinMain" (for DEVCPP users).  You have to include this file first in main.c file,
	and then compile main.c to produce the main.exe file.
		
	DO NOT define a main() function in this file.  The main() function definition 
	is provided in the accompanying file main.c.

    MAKE SURE THAT the solution/program you are submitting does not have:
       * a compilation error
	   * a compilation warning
	   * a logical error
	
	If there is a compilation error, the score will be 0 point for the function that contains a syntax error.	   

   	Violation of any of the RESTRICTIONS or non-compliance will result to point deduction. 
*/

/* DO NOT CHANGE THE #include below.  You are NOT allowed to include other files. */
#include <string.h>
#include <stdio.h>

#include "GE03.h"  // READ and UNDERSTAND the contents of this header file.  DO NOT change this line.

 
/*
    TO DO TASK #1: [for 10 points]

	Implement a BINARY SEARCH algorithm to determine if the search key parameter is
	the sorted List[].  If the key is found, return the array index where it was found,
	otherwise return -1.
	
	NOTE: As indicated above you must use BINARY SEARCH.  If your solution is a linear search
	it will be considered an incorrect solution, and will have a score of 0.
	
	Assumption: The List[] is already sorted alphabetically.
	
	Restriction: Do not call printf() and scanf() in this function.
*/ 
int 
Search(Str30 key, Str30 List[], int n)
{
	/* Declare your own local variables.  Implement the body of this function. */
	int low = 0, high = n -1, mid;
	int found = 0;

	while(!found && low <= high)
	{
		mid = (low + high) /2;
		if(strcmp(key, List[mid]) == 0)
			found = 1;
		else if(strcmp(key, List[mid]) < 0)
			high = mid -1;
		else
			low = mid + 1;
	}
	if (found)
		return mid;
	return -1;	// do not forget a return statement; change 0 to an appropriate value 
}


/*
    TO DO TASK #2: [for 10 points]

	Call Search() function to search the List[] if there is an element that matches the search key 
	parameter.  If it is not found, insert the key such that the sorted order of the list 
	is maintained.  Increment the number of elements.  Return the index where the key was inserted.
	
	If the key is found, do NOT insert the key because we don't want any redundancy.  
    Just return -1 to indicate that the key is already in the list, and an insert operation 
	is not necessary.
	
	Assumption: there is an available memory space for inserting a new element.
	
	Restrictions: 
	  a. You are NOT allowed to declare/use a temporary array variable.
	  b. Do not call printf() and scanf() in this function.
*/
int
Insert(Str30 key, Str30 List[], int *pnElem)
{
	/* Declare your own local variables.  Implement the body of this function. */
	int i,j;
	Str30 temp;
	if(Search(key,List,*pnElem) == -1)
	{
		if(*pnElem == 0) //if key is first word
		{
			strcpy(List[0],key);
			(*pnElem)++;
			return 0;
		}
		i = *pnElem;
		while(strcmp(key,List[i-1]) < 0) // key is smaller than List
		{
			strcpy(List[i],List[i-1]);
			i--;
		}
		strcpy(List[i],key);
		(*pnElem)++;
		return i;
	}	
	return -1;	// do not forget a return statement; change 0 to an appropriate value 

	
}

/*
   	TO DO TASK #3: [for 10 points]

	Compute the frequency count, i.e., how many times a letter appears based on the words stored
	in the List[] array.  Use FC[] to store the counter values.
	
	Do NOT use brute force approach.  A penalty of 0 will be meted for non-compliance.
	
	Restrictions: 
	  a. Do not use a brute force approach. 
	  b. Do not use if () or switch-case statements.
	  b. Do not call printf() and scanf() in this function.	
*/
void 
FrequencyCount(int FC[], Str30 List[], int n)
{
	/* Declare your own local variables.  Implement the body of this function. */
	int i,j;

	for(i=0; i < n; i++)
		for(j=0; j < strlen(List[i]); j++)
			FC[List[i][j] - 'A']++;

}


/*
	TO DO TASK #4: [for 10 points]

	Use Search() function to search the List[] if there is an element that matches the search key 
	parameter.  If it is found, delete the element, and adjust the elements to right of the 
	deleted element by moving them one position towards the left, i.e., towards the lower indices. 
	Decrement the count of the number of element.  Return 1 to indicate that the delete operation 
	was successful. 
	
	If the key is not found, return 0 to indicate that the delete operation was not successful.

	Restrictions: 
	  a. You are NOT allowed to declare/use a temporary array variable.
	  b. Do not call printf() and scanf() in this function.	
*/
int 
Delete(Str30 key, Str30 List[], int *pnElem)
{
	/* Declare your own local variables.  Implement the body of this function. */
	int j,i = Search(key,List,*pnElem);
	if (i >= 0)
	{
		for (j = i; j < *pnElem -1; j++)
		{
			strcpy(List[j],List[j+1]);
		}
		strcpy(List[*pnElem],"");
		(*pnElem)--;
		return 1;	
	}

	return 0;	// do not forget a return statement; change 0 to an appropriate value
}


/*******************************************************************************
    WARNING!!!   WARNING!!!   WARNING!!!    
	
	YOU ARE NOT ALLOWED TO DEFINE the main() function in this file.  

    The main() is in the accompanying main.c source file.
    
	VIOLATION OF THIS RESTRICTION WILL RESULT TO A DEDUCTION OF 10 points!		 
********************************************************************************/
