/*
    LASTNAME1, FIRSTNAME1: 
    SECTION1            :    
    
	LASTNAME2, FIRSTNAME2: 
    SECTION2             :    
    
	
	DATE SUBMITTED      :
	
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
typedef char string3[4];
typedef char string1000[1000];
typedef string aString[58];

/*

	You have to segregate your program's logic into functions.  Non-compliance 
	will result to a 5 point deduction for this Challenge.

	Define your functions below this comment.

    Make sure to include inline documentation in your codes.

*/
void tokenize(aString aWords,string1000 buff)
{
	int i, j = 0,nElem = 0;
	for (i = 0; i <= strlen(buff); i++)
	{
		if (buff[i] != ',' && buff[i] != '\n')
	   {
          aWords[nElem][j] = buff[i];
		  j++;
		  
	   }
	   else
	   { 
        	aWords[nElem][j] = '\0';
		    j = 0;
		    nElem++;
	   }	
	}
}
int ReadFile(string fileName, string countryName, string3 CSC, string date[], int cases[][2], int * population, double * lifeExpectancy)
{
	FILE *fp;
	string1000 buff;
	aString aWords;
	char cDump;
	int i=0;
	if ((fp = fopen(fileName,"r")) != NULL)
	{
		fseek(fp,1162,SEEK_CUR);
		while(fscanf(fp,"%c",&cDump) ==1)
    	{
    		fseek(fp,-2,SEEK_CUR);
			fgets(buff,1000,fp);
			
			tokenize(aWords,buff);
			if(strcmp(CSC,aWords[0]) == 0)
			{
			strcpy(countryName,aWords[2]);
			strcpy(date[i],aWords[3]);
			cases[i][0] = atoi(aWords[5]);
			cases[i][1] = atoi(aWords[8]);
			*population = atoi(aWords[44]);
			*lifeExpectancy = atof(aWords[57]);
			i++;
			}
			
		}
		fclose(fp);
	}
	else
	{
		printf("File NOT FOUND!");
	}
	printf("Rows: %d\n",i);
  	return i;
}
void validateCSC(string cName)
{
	int i;
	for (i=0; i < strlen(cName); i++)
	{
		if (cName[i] >= 'a' && cName[i] <= 'z')
			cName[i] -= 32;
		else if(cName[i] == ' ')
		{
			cName[i] = '-';
		}
	}
	strcat(cName,".txt");
}
void PrintData (string cName, string date[], int cases[][2], int population, double lifeExpectancy, int n)
{
	FILE *fp;
	fp = fopen(cName,"w");
	int i;
	for (i=0; i < n; i++)
	{
		fprintf(fp,"%s\t%d\t%d\t%d\t\t%lf\n",date[i], cases[i][0], cases[i][1], population, lifeExpectancy);
	}
	fclose(fp);
}
int
main()
{
    /* Declare your own local variables. */
    string fileName, cName;
    string3 userCSC;
    int n,population;
    string date[1000];
    int cases[1000][2];
    double lifeExpectancy;
    
    
    /* Call the functions that you defined. */
    printf("Enter Master (.csv) File: ");
    fgets(fileName, 256, stdin);
	fileName[strlen(fileName)-1] = '\0';
	
	printf("Enter Country Code: ");
	scanf("%s",userCSC);
	
	n = ReadFile(fileName,cName,userCSC,date,cases,&population, &lifeExpectancy);
	validateCSC(cName);
	printf("Output: %s",cName);
    PrintData (cName,date,cases,population, lifeExpectancy,n);
       
	return 0;
}



