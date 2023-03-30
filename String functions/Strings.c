#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// prototypes:

void printMenu();											//print the start menu 
int checkString(char[]);									//input a string check if the string is insert properly and return it
int asciiSum(char[]);										//return the sum of the ascii number of the list of words
double asciiAvg(char[]);									//return the average of the ascii number of the list of words
int getSize(int, int);										//return a number between the two send numbers
void printWords(char[][20], int);							//print the words in the word list with ascii sum, ascii average and the word itself
void insertStrings(char[][20], int);						//input numbers of strings according to the send number 
void sortStringsLexicographic(char[][20], int);				//sort the send list by lexicographic order
void sortStringsByLength(char[][20], int);					//sort the send list by length order
void sortStringsByAsciiAvg(char[][20], int);				//sort the send list by ascii average order
void sortStringsByAsciiSum(char[][20], int);				//sort the send list by ascii sum order
void sortString(char[]);									//sort the chars of one string by lexicographic order 
void sortEachString(char[][20], int);						//sort the chars of each string in the word list by lexicographic order 
void sortAllAsOne(char[][20], int);							//combine all the strings in a list, sort the combined string by lexicographic order and split it like the origin list
void stringReturn(char[], int);								//calclate the number of space needed for the ascii sum print


int main()
{
	int insert_flag = 0;								//flag that check if there was an input to the words
	int errors = 0;
	int words_number = 0;
	char words_list[10][20] = { 0 };
	while (1)											//loop for the main menu
	{
		printMenu();									//print the menu
		int operator;
		operator = getSize(0, 99);		
		if (!(operator >=0 && operator<=8))				//check if the operator number is in the rigth range
		{												//if not:
			if (errors == 4)							//if we reach 5 errors, exit the terminal
			{
				printf("5 errors, bye bye.");
				exit(0);
			}
			errors++;
			printf("You made %d errors from 5, try again,\n", errors);  //print the number of errors and try again
		}
		else                                             //the operator is in the rigth range:
		{
			switch (operator)							//operate the selectef task
			{
			case 0:										//task 0: exit the terminal
				printf("You chose to end the program, bye!!!");
				exit(0);

			case 1:										//task 1: input the number of the words and then input the words to the word list
				printf("Enter new word count,\n");
				words_number = getSize(2, 10);
				insertStrings(words_list, words_number);
				insert_flag = 1;						//change the flag
				break;

			case 2:										//print the insert words
				if (insert_flag)
				{
					printf("The words are:\n");
					printf("==============\n");
					printWords(words_list, words_number);
				}
				else
					printf("There are no words, cannot operate.\n");
				break;

			case 3:										//run the lexicographic sort
				if (insert_flag)
					sortStringsLexicographic(words_list, words_number);
				else
					printf("There are no words, cannot operate.\n");
				break;

			case 4:										//run the length sort
				if (insert_flag)
					sortStringsByLength(words_list, words_number);
				else
					printf("There are no words, cannot operate.\n");
				break;

			case 5:										//run the ascii sum sort
				if (insert_flag)
					sortStringsByAsciiSum(words_list, words_number);
				else
					printf("There are no words, cannot operate.\n");
				break;

			case 6:										//run the ascii average sort
				if (insert_flag)
					sortStringsByAsciiAvg(words_list, words_number);
				else
					printf("There are no words, cannot operate.\n");
				break;

			case 7:										//run the string sort
				if (insert_flag)
					sortEachString(words_list, words_number);
				else
					printf("There are no words, cannot operate.\n");
				break;

			case 8:										//run the combined string sort
				if (insert_flag)
					sortAllAsOne(words_list, words_number);
				else
					printf("There are no words, cannot operate.\n");
				break;
			}
			
		}

	}
	return 0;
}

void printMenu()
//print the start menu 
{
	printf("The menu:\n");
	printf("=========\n");
	printf("0. Exit\n");
	printf("1. Insert words\n");
	printf("2. Print words\n");
	printf("3. Sort words lexicographic\n");
	printf("4. Sort words by length\n");
	printf("5. Sort words by ascii sum\n");
	printf("6. Sort words by ascii average\n");
	printf("7. Sort each word by ascii\n");
	printf("8. Sort all words as one\n");
}

int checkString(char str1[])
//input a string check if the string is insert properly and return it
{
	char str_new[200] = {0};
	gets(str_new);					//input the string
	int i;
	int flag = 1;
	if (strlen(str_new) > 19 || strlen(str_new) < 1)    //check if the string is insert properly 
		return 0;
	for (i = 0; i < strlen(str_new); i++)		//properly by length	
	{
		if (!((str_new[i] >= 'a' && str_new[i] <= 'z') || (str_new[i] >= 'A' && str_new[i] <= 'Z')))  //properly by chars
			return 0;
	}
	strcpy(str1 , str_new); //if insert properly, copy the input string to the send string
	return 1;

}

void printWords(char list_words[][20], int words_num) 
//print the words in the word list with ascii sum, ascii average and the word itself
{
	int i;
	for (i = 0; i < words_num; i++)
	{
		char sum_word[5];										//sum of space in the ascii sum print 
		stringReturn(sum_word, asciiSum(list_words[i]));		
		char avg_word[2];										//sum of space in the ascii avg print 
		if (asciiAvg(list_words[i]) >= 100)						//check if the avg number is 3 digits
		{	
			avg_word[0] = '\0';
		}
		else                                                    //if the avg number is 2 digits
		{
			avg_word[0] = ' ';
			avg_word[1] = '\0';
		}
			
		if (i < 9)
			printf("0%d:(ascii sum%s%d, ascii avg %s%.2f)%s\n", i + 1, sum_word, asciiSum(list_words[i]), avg_word, asciiAvg(list_words[i]), list_words[i]); //print the string from 0 to 9 if needed
		else
			printf("%d:(ascii sum%s%d, ascii avg %s%.2f)%s\n", i + 1, sum_word, asciiSum(list_words[i]), avg_word, asciiAvg(list_words[i]), list_words[i]); //print the 10th string if needed
	}
}

int asciiSum(char str1[])
//return the sum of the ascii number of the list of words
{
	int i = 0;
	int sum = 0;
	while (*str1 != '\0')				//run until we get to the end of the string
	{
		sum += (int)*str1;				//add the ascii value to sum
		str1++;							//increase the string pointer
	}
	return sum;							//return the ascii sum
}

double asciiAvg(char str1[])
//return the average of the ascii number of the list of words
{
	double sum = asciiSum(str1);			//get the ascii sum from the last function
	return sum / (strlen(str1));			//retun the ascii average by divide by the string length
}

int getSize(int min, int max)
//return a number between the two send numbers
{
	int i;
	int number;
	char input[201] = { 0 };
	do                              //do an input check 
	{
		number = 0;
		int flag = 1;
		printf("Please enter a number between %d and %d:", min, max);
		gets(input);
		int start_index = 0;
		while (input[start_index] == ' ')
		{
			start_index++;
		}

		int end_index = (int)strlen(input)-1;

		while (input[end_index] == ' ')
		{
			end_index--;
		}

		for (i = start_index; i <= end_index; i++)
		{
			if (!((input[i] >= '0' && input[i] <= '9')))				//check if the input is a number
			{
				number = max + 1;										//if not, number get an unproper value
				flag = 0;
				break;
			}
		}
		if (flag)   //if the input is a number
		{
			for (i = start_index; i<= end_index; i++)					// converse the string to integer
				number = number * 10 + input[i] - '0';
		}									
	} while (number > max || number < min);
	return number;														//return the input number
}

void insertStrings(char list_words[][20], int N)
//input numbers of strings according to the send number
{
	int i = 0;
	int flag = 1;
	while (i < N)			//run on all the words
	{
		if (flag)
			printf("Please enter word #%d:\n", i + 1);			//print at the beginning of the input
		else
			printf("Wrong input, try again:\n");				// print if the input is incorrect
		if (checkString(list_words[i]) == 1)					//check if the input is incorrect
		{
			i++;
			flag = 1;
		}
		else
			flag = 0;
	}
}

void sortStringsLexicographic(char list_words[][20], int words_num)
//sort the send list by lexicographic order
{
	int i, j;
	char temp [20];
	for (i = 0; i < words_num; i++)				//run on all the words
	{
		for (j = 0; j < words_num-i-1; j++)		//run without the last word
		{
			if (strcmp(list_words[j], list_words[j + 1]) > 0)		//compare if the j word is bigger than the j+1 word (by ascii value of each char - lexicographic)
			{
				strcpy(temp, list_words[j]);						//swap between the j word and the j+1 word
				strcpy(list_words[j], list_words[j+1]);
				strcpy(list_words[j+1], temp);
			}
		}
	}
}

void sortStringsByLength(char list_words[][20], int words_num)
//sort the send list by length order
{
	int i, j;
	char temp[20];
	for (i = 0; i < words_num; i++)				//run on all the words
	{
		for (j = 0; j < words_num - i - 1; j++)		//run without the last word
		{
			if (strlen(list_words[j])> strlen(list_words[j+1]))			//check if the j word is longer than the j+1 word
			{
				strcpy(temp, list_words[j]);							//swap between the j word and the j+1 word
				strcpy(list_words[j], list_words[j + 1]);
				strcpy(list_words[j + 1], temp);
			}
		}
	}
}

void sortStringsByAsciiAvg(char list_words[][20], int words_num)
//sort the send list by ascii average order
{
	int i, j;
	char temp[20];
	for (i = 0; i < words_num; i++)				//run on all the words	
	{
		for (j = 0; j < words_num - i - 1; j++)			//run without the last word
		{
			if (asciiAvg(list_words[j])> asciiAvg(list_words[j + 1]))			//check if the ascii average of the j word is bigger than the j+1 word
			{
				strcpy(temp, list_words[j]);									//swap between the j word and the j+1 word
				strcpy(list_words[j], list_words[j + 1]);
				strcpy(list_words[j + 1], temp);
			}
		}
	}
}

void sortStringsByAsciiSum(char list_words[][20], int words_num)
//sort the send list by ascii sum order
{
	int i, j;
	char temp[20];
	for (i = 0; i < words_num; i++)			//run on all the words
	{
		for (j = 0; j < words_num - i - 1; j++)			//run without the last word
		{
			if (asciiSum(list_words[j]) > asciiSum(list_words[j + 1]))  //check if the ascii sum of the j word is bigger than the j+1 word
			{
				strcpy(temp, list_words[j]);							//swap between the j word and the j+1 word
				strcpy(list_words[j], list_words[j + 1]);
				strcpy(list_words[j + 1], temp);
			}
		}
	}
}

void sortString(char word[])
//sort the chars of one string by lexicographic order
{
	int i, j;
	char temp;
	for (i = 0; i < strlen(word); i++)			//run on all the chars in the string
	{
		for (j = 0; j < strlen(word) - i - 1; j++)     //run on all the chars in the string without the last char
		{
			if (word[j] > word[j + 1])					//swap between the j cahr and the j+1 char
			{
				temp = word[j];
				word[j] = word[j + 1];
				word[j + 1] = temp;
			}
		}
	}
}

void sortEachString(char list_words[][20], int words_num)
//sort the chars of each string in the word list by lexicographic order 
{
	int i;
	for (i = 0; i < words_num; i++)  //run on all the words in the word list and sort each string by lexicographic order
	{
		sortString(list_words[i]);
	}
}

void sortAllAsOne(char list_words[][20], int words_num)
//combine all the strings in a list, sort the combined string by lexicographic order and split it like the origin list
{
	int i;
	char temp[201] = "";
	for (i = 0; i < words_num; i++)         //run on all the words
	{
		strcat(temp, list_words[i]);		//combine all the word to one string
	}

	sortString(temp);						//sort the combined string
	char* p2 = temp;						//pointer to the compined string
	for (i = 0; i < words_num; i++)
	{
		char* p1 = list_words[i];			//pointer to the original word list
		while (*p1)
		{
			*p1 = *p2;						//return the values of the combined string to the original word list 
			p1++;
			p2++;
		}

	}
}

void stringReturn(char str1[] ,int number)
//calclate the number of space needed for the ascii sum print
{
	int i;
	int counter = 0;						//number of space
	while (number)							//while number != 0
	{
		counter = counter + 1;
		number = number / 10;				//remove the rigth digit
	}
	for (i = 0; i < 5-counter; i++)			//add 5 - number of digit to add the number of spaces
	{
		str1[i] = ' ';
	}
	str1[i] = '\0';
}