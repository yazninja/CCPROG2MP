/*
    LASTNAME1, FIRSTNAME1: Grasparil, David Nikolai 	SECTION1: S15    
    
	LASTNAME2, FIRSTNAME2: Ligot, Yazle Sean      		SECTION2: S15    

	DATE SUBMITTED      : May 20,2021
	
	Do not forget to ENCODE your name/s, section/s and date on the space indicated above.
		
	CCPROG2 MP Solution for: Challenge #6 
*/


/*
	Do NOT edit/remove the lines of codes containing #ifndef  #endif pair, and #define C6 (1).

*/
#ifndef C6

	#define C6 (1)
   
   	/*
   		TO DO: change the string "88" in Line 27 to your own MP group number enclosed in a pair of double quotes. For single 
		   	   digit group number, encode it with a leading 0.  For example, if your are group number 8, then Line 27
   			   should become #define GROUP_NUMBER "08".
   	*/
   	#define GROUP_NUMBER  "18"


	/* 
		You may use the NUM_COUNTRIES and NUM_CONTINENTS in your solution.
	*/	
	
	// There are 173 countries/locations with corresponding COVID data text file in CHD folder
	#define NUM_COUNTRIES  (173)
		  
	// There are 6 continents considered in this MP, namely: ASIA, AFRICA, EUROPE, NORTH-AMERICA, SOUTH-AMERICA, OCEANIA	
	#define NUM_CONTINENTS  (6)
  
   
	/*
		You may add your own macro definitions right after this comment.
	*/
	#define MAX 500
	#define MAX_STRING 33


	/*
		You are REQUIRED to use the StrDate alias as data type for an entity to be used for storing
		date as a string, ex.  "2021-03-21" (string length of 10).
	*/
	typedef char StrDate[11];  


	/*
		You may add your own typedef for OTHER  string aliases right after this comment.	
	*/
typedef char string[MAX_STRING];


	/*
		Add codes from your C2-NUMBER.h header file right after this comment.  Note that you may still 
		edit/change the copied contents as you deem fit for your solutions to Challenges C7 to C9. 
	*/

	/*
		You may add other structure data type declarations and optionally their corresponding 
		typedef declarations (aliases) right after this comment.		
	*/
struct data
{
	StrDate date;
	int cases;
	int deaths;
};
typedef struct data day;

struct national
{
	string name;
	long int population;
	float lifeExpectancy;
	day daily[MAX];
	int count;
};	
typedef struct national country;

struct regional
{
	string name;
	long int population;
	int totalCases, totalDeaths;
	float percentCases, percentDeaths;
};
typedef struct regional continent;

	/*
		TO DO: add the function prototypes for all functions that you defined in order accomplish to Challenges C7 to C9.
	*/
int Read_COVID_Data(char *param_country, country *ptrData);

void swap(country *cArr1, country *cArr2);
void selectionSort(country cArr[], int nCountry);
void printToFile(country cArr[], int nCountry, char * file_output_name);
int Stats_C8(char *param_output_filename, char *param_input_filename);

#endif

/*--- THE END ---*/



