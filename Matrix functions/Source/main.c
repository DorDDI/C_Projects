#include <stdio.h> 
#include "func.h"
#define M 10


int main() {
	int Mat1[M][M], Mat2[M][M], Mat3[M][M], auxMat[M][M];
	char opt[30];
	int mat1Trace, mat2Trace, maxDiag1, maxDiag2, offset1 = 0, offset2 = 0;
	char Selcet = '0';

	show_menu();

	while (1)
	{

		printf("insert a menu clause number: ");
		scanf_s("%c",&Selcet);

		switch (Selcet) {
		case '0':
			break;

		case '1':
			do {
				printf("Insert an offset value between 0-100 to Mat 1: ");
				scanf_s("%d", &offset1);
				printf("Insert an offset value between 0-100 to Mat 2: ");
				scanf_s("%d", &offset2);
				if (offset2 >= 0 && offset2 <= 100 && offset1 >= 0 && offset1 <= 100) break;

			} while (1);
			FillMatrix(Mat1, offset1);
			FillMatrix(Mat2, offset2);
			break;

		case '2':
			sum_mattrix(Mat1, Mat2, Mat3);
			show_matrix(Mat3);
			break;

		case '3':
			maxDiag1 = DiagonalsMax(Mat1);
			maxDiag2 = DiagonalsMax(Mat2);
			if (maxDiag1 > maxDiag2)
				printf("The maximal diagonal element between Mat1 and Mat2 = %d\n", maxDiag1);
			else
				printf("The maximal diagonal element between Mat1 and Mat2 = %d\n", maxDiag2);
			break;
		case '4':
			mat1Trace = ComputeTrace(Mat1);
			mat2Trace = ComputeTrace(Mat2);
			if (mat1Trace >= mat2Trace)
			{
				printf("The max Trace value between Mat1 and Mat2 = %d \n", mat1Trace);
			}
			else
			{
				printf("The max Trace value between Mat1 and Mat2 = %d \n", mat2Trace);
			}
			break;

		case '5':
			switch_diagonal(Mat1, Mat2);
			break;

		case '6':

			while (1) 
			{
				printf("Insert the wanted matrix [Mat1 or Mat2]\n");
				gets(opt);

				if (!strcmp(opt, "Mat1"))
				{
					Transpose(Mat1, auxMat);
					show_matrix(auxMat);
					break;
				}
				if (!strcmp(opt, "Mat2"))
				{
					Transpose(Mat2, auxMat);
					show_matrix(auxMat);
					break;
				}

			}
			break;

		case '7':
			while (1)
			{
				printf("Insert the wanted matrix [Mat1 or Mat2]\n");
				gets(opt);

				if (!strcmp(opt, "Mat1"))
				{
					show_matrix(Mat1);
					break;
				}
				if (!strcmp(opt, "Mat2"))
				{
					show_matrix(Mat2);
					break;
				}

			}
			break;

		case '8':
			show_menu();
			break;

		case '9':
			return 0;


		}
	}
}
