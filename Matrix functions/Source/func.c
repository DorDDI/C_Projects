#include "func.h"
#include <stdio.h> 


//---------------------------------------------------------------
//                  show menu
//---------------------------------------------------------------
void show_menu()
{
	printf("----------Menu--------------- \n");
	printf("----------------------------- \n");
	printf("1) Create 10x10 matrices Mat1,Mat2 using the next expression: \n");
	printf("   for i,j = {0-9}: Mat[i][j] = (offset + i * 10 + j) % 100 \n");
	printf("2) Compute and show the matrix Mat1+Mat2 \n");
	printf("3) Compute and show the maximal diagonal element between Mat1 and Mat2 \n");
	printf("4) Compute and show the maximal Trace between matrices Mat1 and Mat2 \n");
	printf("5) copy Mat1 right diagonals to Mat2 left diagonals \n");
	printf("6) Comute and show the transposed of a given Matrix \n");
	printf("7) Show a given matrix \n");
	printf("8) Show menu \n");
	printf("9) exit \n");
}
//---------------------------------------------------------------
//                  Trace Computation
//---------------------------------------------------------------
int ComputeTrace(int Mat[M][M]) {
	int Trace = 0;
	for (int i = 0; i < M; i++)
	{
		Trace += Mat[i][i];
	}
	return Trace;
}
//---------------------------------------------------------------
//                  DiagonalsMax Computation
//---------------------------------------------------------------
int DiagonalsMax(int Mat[M][M]) {
	int Max = 0;
	for (int i = 0; i < M; i++) {
		if (Max < Mat[i][i])
		{
			Max = Mat[i][i];
		}
		if (Max < Mat[i][M - 1 - i])
		{
			Max = Mat[i][M - 1 - i];
		}
	}
	return Max;
}
//---------------------------------------------------------------
//                  Matrix Transpose 
//---------------------------------------------------------------
void Transpose(int Mat_1[M][M], int Mat_2[M][M]) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			Mat_2[i][j] = Mat_1[j][i];
		}
	}
}
//---------------------------------------------------------------
//                  Fill Matrix
//---------------------------------------------------------------
void FillMatrix(int Mat[M][M], int offset) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			Mat[i][j] = (offset + i * M + j) % 100;
		}
	}
}
//---------------------------------------------------------------
//                  show matrix
//---------------------------------------------------------------
void show_matrix(int Mat[M][M]) {
	printf("[\n");
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d, ", Mat[i][j]);
		}
		printf("\n");
	}
	printf("]\n");
}
//---------------------------------------------------------------
//                  Sum Matrix
//---------------------------------------------------------------
void sum_mattrix(int Mat_1[M][M], int Mat_2[M][M], int Mat_3[M][M]) {
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			Mat_3[i][j] = Mat_1[i][j] + Mat_2[i][j];
		}
	}
}
//---------------------------------------------------------------
//     copy the right diagonal of mat1 to left diagonal of mat2
//---------------------------------------------------------------
void switch_diagonal(int Mat_1[M][M], int Mat_2[M][M]) {
	for (int i = 0; i < M; i++) {
		Mat_2[i][M - 1 - i] = Mat_1[i][i];
	}
	for (int i = 0; i < M; i++) {
		Mat_2[i][i] = Mat_1[i][M - 1 - i];
	}
}