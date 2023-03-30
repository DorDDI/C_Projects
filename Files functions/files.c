#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// prototypes:

typedef struct serie {									//struct for every serie, contain its name, serie code, number of seasons, rank and array of watching
	char serieName[20];									//serie name
	int serieCode;										//serie code
	int numSeasons;										//serie number of seasons
	int rank;											//serie ramk - number of views
	int* watchingDetails;								//dinamic array that contain the number of views for every season of the serie
}serie;

int main()
{

	return 0;
}

void showMenu()
//print the start menu 
{
	printf("**********Main Menu **************\n");
	printf("1. Unify Database.\n");
	printf("2. Get Unify Database Details.\n");
	printf("3. Print The Series List Sorted By Code.\n");
	printf("4. Get Watching Details.\n");
	printf("5. Show All Watching Details.\n");
	printf("6. Print Series Sorted By Rank.\n");
	printf("7. Make Series File Sorted By Rank.\n");
	printf("8. Exit.\n");

}
