#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	
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

