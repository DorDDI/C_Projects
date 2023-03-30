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

void unifyDatabase(FILE* first_file, FILE* second_file)
//unify the series between two files
{
	FILE* series_file;									//pointer for the series text file
	int res1;											//result for the first file
	int res2;											//result for the second file
	series_file = fopen("series.txt", "w");
	char name1[20];										//name of the serie in the first file 
	int seria_code1;									//code of the serie in the first file 
	int seria_seasons1;									//season numbers of the serie in the first file 
	char active1;										//if the serie is active in the first file 
	char name2[20];										//name of the serie in the second file 
	int seria_code2;									//code of the serie in the second file 
	int seria_seasons2;									//season numbers of the serie in the second file 
	char active2;										//if the serie is active in the second file 

	res1 = fscanf(first_file, "%[^,]%*c", name1);		//input the name until ',' and ignore him
	res1 = fscanf(first_file, "%d%*c", &seria_code1);	//input the code until ',' and ignore him
	res1 = fscanf(first_file, "%d%*c", &seria_seasons1);//input the season number until ',' and ignore him
	res1 = fscanf(first_file, "%c%*c", &active1);		//input the active until '\n' and ignore him

	res2 = fscanf(second_file, "%[^,]%*c", name2);		//input the name until ',' and ignore him
	res2 = fscanf(second_file, "%d%*c", &seria_code2);	//input the code until ',' and ignore him
	res2 = fscanf(second_file, " %d%*c", &seria_seasons2);	//input the season number until ',' and ignore him
	res2 = fscanf(second_file, "%c%*c", &active2);		//input the active until '\n' and ignore him

	while (res1 != EOF && res2 != EOF)					//run until we arrive to the end of one of the files 
	{
		if (seria_code1 < seria_code2)					//check which serie code come before in the files
		{	
			if (active1 == 'Y')							//if the serie active, save it to the new txt file
				fprintf(series_file, "%s,%d,%d\n", name1, seria_code1, seria_seasons1);
			res1 = fscanf(first_file, "%[^,]%*c", name1);
			res1 = fscanf(first_file, "%d%*c", &seria_code1);
			res1 = fscanf(first_file, " %d%*c", &seria_seasons1);
			res1 = fscanf(first_file, "%c%*c", &active1);
		}
		else
		{
			if (seria_code1 > seria_code2)					//same as before only for the second file
			{
				if (active2 == 'Y')
					fprintf(series_file, "%s,%d,%d\n", name2, seria_code2, seria_seasons2);
				res2 = fscanf(second_file, "%[^,]%*c", name2);
				res2 = fscanf(second_file, "%d%*c", &seria_code2);
				res2 = fscanf(second_file, " %d%*c", &seria_seasons2);
				res2 = fscanf(second_file, "%c%*c", &active2);
			}
			else                                          //if we have the same serie in both files
			{
				if (active1 == 'Y' && active2 == 'Y')	  //if the serie is active in both files
				{
					if (seria_seasons1 > seria_seasons2)  //we will check where there is more seasons and save it to the txt file
						fprintf(series_file, "%s,%d,%d\n", name1, seria_code1, seria_seasons1);
					else
						fprintf(series_file, "%s,%d,%d\n", name2, seria_code2, seria_seasons2);
				}
				else                                      //if only the serie is active in one file and save it to the txt file
				{
					if (active1 == 'Y')
						fprintf(series_file, "%s,%d,%d\n", name1, seria_code1, seria_seasons1);
					if (active2 == 'Y')
						fprintf(series_file, "%s,%d,%d\n", name2, seria_code2, seria_seasons2);
				}
				res1 = fscanf(first_file, "%[^,]%*c", name1);
				res1 = fscanf(first_file, "%d%*c", &seria_code1);
				res1 = fscanf(first_file, " %d%*c", &seria_seasons1);
				res1 = fscanf(first_file, "%c%*c", &active1);

res2 = fscanf(second_file, "%[^,]%*c", name2);
res2 = fscanf(second_file, "%d%*c", &seria_code2);
res2 = fscanf(second_file, " %d%*c", &seria_seasons2);
res2 = fscanf(second_file, "%c%*c", &active2);

			}
		}
	}
																//we arrived to end of one of the files
	if (res2 == EOF && res1 != EOF)								//check if the second file end and run on the first file
	{
		while (res1 != EOF)										
		{
			if (active1 == 'Y')
				fprintf(series_file, "%s,%d,%d\n", name1, seria_code1, seria_seasons1);
			res1 = fscanf(first_file, "%[^,]%*c", name1);
			res1 = fscanf(first_file, "%d%*c", &seria_code1);
			res1 = fscanf(first_file, " %d%*c", &seria_seasons1);
			res1 = fscanf(first_file, "%c%*c", &active1);
		}
	}
	if (res1 == EOF && res2 != EOF)								//check if the first file end and run on the second file	
	{
		while (res2 != EOF)
		{
			if (active2 == 'Y')
				fprintf(series_file, "%s,%d,%d\n", name2, seria_code2, seria_seasons2);
			res2 = fscanf(second_file, "%[^,]%*c", name2);
			res2 = fscanf(second_file, "%d%*c", &seria_code2);
			res2 = fscanf(second_file, " %d%*c", &seria_seasons2);
			res2 = fscanf(second_file, "%c%*c", &active2);
		}
	}
	fclose(series_file);
}

serie** getUnifyDatabaseDetails(int* counter)
//build and save the details of the series text file to the memory
{
	int i;
	FILE* series_file;									//pointer for the series file
	series_file = fopen("series.txt", "r");

	int count_series = 0;								//check how many series there is
	int res = fscanf(series_file, "%*[^\n]%*c");		
	while (res != EOF)									//run in all the series file
	{
		count_series++;									//add to the series counter
		res = fscanf(series_file, "%*[^\n]%*c");
	}
	serie** series_list;
	series_list = (serie**)malloc(count_series * sizeof(serie*));		//create a dinamic arry of pointers to serie struct in len of the number of series
	if (series_list == NULL)
		exit(0);
	rewind(series_file);								//return to the top line in the file
	res = 0;
	*counter = count_series;							//save the number if series in the main
	for (i = 0; i < count_series; i++)					//run on all the series
	{
		char name[20] = { 0 };							
		int seria_code;
		int seria_seasons;
		res = fscanf(series_file, "%[^,]%*c", name);
		res = fscanf(series_file, "%d%*c", &seria_code);
		res = fscanf(series_file, " %d%*c", &seria_seasons);

		series_list[i] = (serie*)malloc(sizeof(serie));		//create a pointer to serie arry that we will be able to save it after the function is over
		if (series_list[i] == NULL)
			exit(0);
		series_list[i]->numSeasons = seria_seasons;			//save the data from the file to the struct: serie number of seasons
		series_list[i]->rank = 0;							//serie rank will start with 0
		series_list[i]->serieCode = seria_code;				//the serie code
		strcpy(series_list[i]->serieName, name);			//the serie name
		series_list[i]->watchingDetails = (int*)calloc(seria_seasons ,sizeof(int));	//create a dinamic int list of the watching list in len of the seasons number
	}

	FILE* watching_create;
	watching_create = fopen("watching.txt", "w");			//create the watching txt file - open and close it
	fclose(watching_create);
	return series_list;
}

void printSeriesList(serie** watch_series, int index)
//print the datails of every serie
{
	int k;
	printf("%03d-%s\n", watch_series[index]->serieCode, watch_series[index]->serieName);  //print the serie code for a specific serie
	for (k = 0; k < watch_series[index]->numSeasons; k++)
	{
		printf("Season %d:%d\n", k + 1, (watch_series[index]->watchingDetails)[k]);		  //print the serie whatchin list for a specific serie
	}
}

