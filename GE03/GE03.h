/*
   GE03 header file.  Do NOT modify this file.
*/

/* CONCENTRATE only on Lines 11 to 19, you need not be concerned with the other lines. */

#ifndef GE03

#define GE03 (1)

	// maximum number of words in the array is MAX 
	#define MAX 5000

	typedef char Str30[21];

	int Search(Str30 key, Str30 List[], int n);
	int Insert(Str30 key, Str30 List[], int *pnElem);
	void FrequencyCount(int FC[], Str30 List[], int n);
	int Delete(Str30 key, Str30 List[], int *pnElem);

#endif


