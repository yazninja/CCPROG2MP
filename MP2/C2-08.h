/*
    LASTNAME1, FIRSTNAME1: Grasparil, David Nikolai 
    SECTION1            :  S15
    
	LASTNAME2, FIRSTNAME2: Ligot, Yazle Sean
    SECTION2             : S15   
    
	DATE SUBMITTED      :  April 8,2021
	
	CCPROG2 MP Solution for: Challenge #2         
*/

/*
	You are REQUIRED to use the StrDate alias as data type for an entity to be used for storing
	date as a string, ex.  "2021-03-21" (string length of 10).
*/
typedef char StrDate[11];  
typedef char string[33];

/*
	You may add your own typedef for another string alias right after this comment.	
*/



/*
	Step 1. Define a macro name for an integer value to be used as the 
			maximum 1D array size of COVID-19 historical data.  
*/
#define MAX 500

/*
	Step 2. Declare a structure data type (made up of 3 members) that can be used to represent ONE row of daily data,
	     	i.e., date, new_cases, new_deaths.
*/
struct dataType
{
	StrDate date;
	int cases;
	int deaths;
};

/*
	Step 3. Declare a typedef alias for the structure data type in the previous step.
*/
typedef struct dataType daily;


/*
	Step 4. Declare a 2nd structure data type (made up of 5 members) that can be used 
			to represent data/statistics for one country.  
*/
struct countryType
{
	string name;
	long int population;
	float lifeExpectancy;
	daily daily[MAX];
	int count;
};



/*
	Step 5. Declare a typedef alias for the structure data type in the previous step.
*/

typedef struct countryType country;

/*--- THE END ---*/



