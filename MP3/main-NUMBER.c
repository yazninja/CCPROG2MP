/*
    LASTNAME1, FIRSTNAME1:  					  	SECTION1:      
    
	LASTNAME2, FIRSTNAME2:     						SECTION2:    

	DATE SUBMITTED      :
	
	Do not forget to ENCODE your name/s, section/s and date on the space indicated above.
		
    This file contains the main() function for the MP Part 3.  
	
	DO the following to test your solution: 
	
	1. Edit Lines 34 to 37 below to include your own source files.
	2. Compile this main-NUMBER.c file to produce main-NUMBER.exe.  Make sure to use -Wall compiler directive!
	3. Run main-NUMBER.exe WITHOUT I/O redirection.
	4. Using Notepad (or other text editors), open and compare your C8 and C9 output files with:
	       a. C8-EXPECTED1.TXT
	       b. C9-EXPECTED1.TXT		
	   They should be the same EXCEPT for the spacing.  If the encoded values are not the same, then there's 
	   a strong probability that there's a logical error in your solution, or you did not follow some specifications.  
	5. Debug and retry until you get the correct results.    
	6. Test C8 and C9 solutions exhaustively using your own test data named COUNTRIES-NUMBER.TXT.
*/

/* DO NOT CHANGE THE #include below.  You are NOT allowed to include other standard header files. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    TO DO: change the four #include below to your own file/solution. You are not allowed to include other files.
*/	
#include "C6-NUMBER.h"
#include "C7-NUMBER.c"
#include "C8-NUMBER.c"
#include "C9-NUMBER.c"


/*
    This is the main() function for testing your solution.  
	
	Fill-up the missing parts in Lines 62, and Lines 76 to 79.
	
	You are not supposed to modify the logic of this function.
    
    If you need to experiment, i.e. you'd like to edit/introduce new codes, then it is suggested that you
	copy this file, and make changes on your copy.
*/
int
main()
{
	/* Do NOT change the following variable declarations and variable definition. */
    int i;
	int result;	
	char param_country[35];
	char input_filename[50];
	char output_filename[50];
	char C7_test_data[5][35] = { "ARGENTINA", "JAPAN", "PHILIPPINES", "ZIMBABWE", "XYZ" };

	/* TO DO: supply the data type of variable Data.  Use the alias you declared in C6-NUMBER.h. */
	_______ Data;    
	

/*------------------------------------------------------------------
   	Test solution for Challenge #7.  
	
	You are allowed to edit ONLY those lines with missing 
	codes in the body of the if () statement.
-------------------------------------------------------------------*/
	printf("**TEST-C7**\n");
	for (i = 0; i < 5; i++) {
		strcpy(param_country, C7_test_data[i]);
		result = Read_COVID_Data(param_country,  &Data);
		if (result) {
			printf("%s  ", Data.__________);  /* TO DO: print country name. */
			printf("%ld ", Data.__________);  /* TO DO: print population. */ 
			printf("%.2f ", Data._________);  /* TO DO: print life_expectancy */
			printf("%s %d %d\n", Data.______, Data.______, Data.______); /* TO DO: print the last row of data, i.e, date, new_cases and new_deaths. */
		}
	}
	printf("\n\n");	
	
	
/*------------------------------------------------------------------
   	Test solution for Challenge #8.  
	
	DO NOT CHANGE THE FOLLOWING LINES OF CODES!
-------------------------------------------------------------------*/
	printf("**TEST-C8**\n");	
	
	// Test Case #1 using COUNTRIES.TXT file
	strcat(strcat(strcpy(output_filename, "C8-"), GROUP_NUMBER), "-OUTPUT1.TXT");   // NOTE: GROUP_NUMBER is a macro in C6-NUMBER.h file
	printf("output_filename = %s\n", output_filename);
	
	result = Stats_C8(output_filename, "COUNTRIES.TXT");
	printf("result = %d\n", result);
	
	// Test Case #2 using student's country text file
	strcat(strcat(strcpy(input_filename, "COUNTRIES-"), GROUP_NUMBER), ".TXT");
	strcat(strcat(strcpy(output_filename, "C8-"), GROUP_NUMBER), "-OUTPUT2.TXT");
	
	printf("input_filename = %s\n", input_filename);
	printf("output_filename = %s\n", output_filename);
		
	result = Stats_C8(output_filename, input_filename);
	printf("result = %d\n", result);	
	
	// Test Case #3 using a non-existent input file 
	result = Stats_C8("DUMMY.TXT", "WALA-ITO.TXT");
	printf("result = %d\n", result);
	printf("\n\n");


/*------------------------------------------------------------------
   	Test solution for Challenge #9.  
	
	DO NOT CHANGE THE FOLLOWING LINES OF CODES!
-------------------------------------------------------------------*/
	printf("**TEST-C9**\n");	
	// Test Case #1 using COUNTRIES.TXT file
	strcat(strcat(strcpy(output_filename, "C9-"), GROUP_NUMBER), "-OUTPUT1.TXT");
	printf("output_filename = %s\n", output_filename);
	
	result = Stats_C9(output_filename, "COUNTRIES.TXT");
	printf("result = %d\n", result);
	
	// Test Case #2 using student's country text file
	strcat(strcat(strcpy(input_filename, "COUNTRIES-"), GROUP_NUMBER), ".TXT");
	strcat(strcat(strcpy(output_filename, "C9-"), GROUP_NUMBER), "-OUTPUT2.TXT");
	
	printf("input_filename = %s\n", input_filename);
	printf("output_filename = %s\n", output_filename);
	result = Stats_C9(output_filename, "COUNTRIES.TXT");
	printf("result = %d\n", result);
	
	// Test Case #3 using a non-existent input file 
	result = Stats_C9("DUMMY.TXT", "WALA-ITO.TXT");
	printf("result = %d\n", result);
	
	
	return 0;
}


