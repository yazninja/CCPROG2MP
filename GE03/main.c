/*
    This is main.c file.  It contains the main() function for GE03.

	To test your solution: edite Line 39 to include your own GE03-NUMBER.c file.
	Compile this main.c file to produce main.exe.
	
	Run main.exe in the command line with I/O redirection as follows:
   
   		main < INPUT.txt > RESULT-NUMBER.txt.
		   
	where INPUT.TXT is the accompanying sample text file that contains the input data read via scanf().
	
	For simplicity, assume that all input data are words in CAPITAL LETTERS.
	
	For example, if your group number is 8, then you should run your program as:
	
		main-08 < INPUT.txt > RESULT-08.txt.
	   
	Single digit group numbers (1 to 9) must be encoded with a leading zero.
    
    Compare your RESULT-NUMBER.TXT with the contents of the accompanying EXPECTED.TXT.  
	They should be exactly the same -- even the spacing. If they are not the same, then 
	there's a strong probability that there's a logical error in your solution, or you 
	did not follow some specifications.  Debug and retry until you get the correct results.    
*/

/* DO NOT CHANGE THE #include below.  You are NOT allowed to include other files. */
#include <string.h>
#include <stdio.h>

#include "GE03.h"  // READ and UNDERSTAND the contents of this header file.  DO NOT change this line.

/*
    TO DO: change the #include below to the file with your own group number. For example if your 
	group number is 8, it should be changed to #include "GE03-03.c".
	
	Single digit group numbers (1 to 9) must be encoded with a leading zero.   
*/
#include "GE03-NUMBER.c"


/*
	Displays the contents of List[] array.  Do NOT change this function.
*/
void
DisplayList(Str30 List[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%s\n", List[i]);
}


/*
    main() function for testing.  You are not supposed to modify the contents (logic) of this function.
    
    If you need to experiment (and need to edit/introduce new codes), then it is suggested that you
	copy this file, and make the changes on the copy.
*/
int 
main()
{
	int i;
	int result;
	int nSize = 0; // the actual number of words stored in the WordList[]
	
	Str30 word;
	Str30 WordList[MAX]; 
	Str30 to_delete[5] = {"XYZ"};  // list of words to be deleted from WordList[]
	
	int FC[26] = {};  // Frequency Count array - each array element will be used as a counter
                      // FC[0] is the counter for letter 'A', FC[1] is the counter for 'B', ..., 
					  //       and FC[25] is the counter for letter 'Z'
					    	
	// test Insert() operation
	printf("**01-Test-Insert()**\n");
	while (scanf("%s", word) == 1 ) {
		if (nSize <= MAX) {
			result = Insert(word, WordList, &nSize);
			printf("%d %s %d\n", result, word, nSize);
		}
	}	
	printf("\n\n");

 	// print WordList[] contents after insertions
	printf("**02-List-After-Insert**\n");
	DisplayList(WordList, nSize);
	
	printf("\n\n");
	
	printf("**03-Test-FrequencyCount()**\n");
	FrequencyCount(FC, WordList, nSize);
	for (i = 0; i < 26; i++)
		printf("%c %d\n", 'A' + i, FC[i]);
	
	printf("\n\n");
	
	
	printf("**04-Test-Search()**\n");
	for (i = nSize-1; i >= 0; i--) {
		printf("%d %s %d\n", i, WordList[i], Search(WordList[i], WordList, nSize));
	}
	printf("\n\n");


	// test Delete() operation
	printf("**05-Test-Delete()**\n");
	strcpy(to_delete[1], WordList[0]);        // copy 1st word from WordList[]
	strcpy(to_delete[2], WordList[nSize/2]);  // copy word in the middle of WordList[]
	strcpy(to_delete[3], WordList[nSize-1]);  // copy the last word from WordList[]
	strcpy(to_delete[4], WordList[nSize-1]);  // copy the last word one time
	for (i = 0; i < 5; i++) {
		result = Delete(to_delete[i], WordList, &nSize);
		printf("result = %d victim = %s\n", result, to_delete[i]);
	}
	printf("\n\n");
		
	// print WordList[] contents again after deletions
	printf("**06-List-After-Delete**\n");
	DisplayList(WordList, nSize);    	 

	return 0;
}
