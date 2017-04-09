/*
 * =====================================================================================
 *
 *       Filename:  burros_hw9_task1.c
 *       	Usage:  ./burros_hw9_task1.c
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/05/2017 01:14:09 AM
 *       Compiler:  gcc -Wall -Werror
 *         Author:  Sterling, Sherry 
 * =====================================================================================
 */
#include <stdio.h>		/* For Standard I/O */
#include <stdlib.h>
#include <string.h>

#define LEN 12
/* Function Prototypes */
void Usage(char** info);
void ReadFile(char *fName, float num[]);
FILE *OpenCheckFile(char *fName);
void WriteFile(FILE *sFile, float num[]);

/* Main Program */
int main (int argc, char *argv[])
{
	float num[LEN];
	char inFile[LEN], outFile[LEN];
	FILE *ResultFile;

	if (argc != 3 || (strcmp(argv[1],"--help") == 0)) 
	{
		Usage(argv);
	}
	else
	{
		strcpy(inFile, argv[1]);
		strcpy(outFile, argv[2]);
		ReadFile(inFile, num);
		ResultFile = OpenCheckFile(outFile);
		WriteFile(ResultFile , num);
	}

	return 0;
}


/* Function Defenitions */

void Usage(char** info)
{
	// Determine if help was called for
	if (*(info+1) && (strcmp(*(info+1), "--help") == 0))
	{
		printf("Help information\n");
	}
	else
	{
		printf("Usage %s <dataFile> <outFileName>\n", *info);
		exit(1);
	}

	return;
}
void ReadFile(char *fName, float num[])
{
	char inName[LEN];
	strcpy(inName, fName);
	int count = 0;
	FILE *readnums;
	readnums = fopen(inName, "r");
		while(fscanf(readnums, "%f", &num[count]) != EOF)
		{
			count++;
		}
	fclose(readnums);

	return;
}
FILE *OpenCheckFile(char *fName)
{
	char res;
	FILE *OutFile;
	char outname[LEN];
	strcpy(outname, fName);
	OutFile = fopen(outname, "w");
	if(OutFile != NULL)
	{
		printf("The file exists. Do you want to overwrite it?\n");
		printf("with new data (y or n)\n");
		scanf("%c", &res);
		if(res == 'y' || res == 'Y')
		{
		}
		else
		{
			printf("The existing file will NOT be overwritten.\n");
			exit(1);

		}
	}
	return OutFile;
}

void WriteFile(FILE *sFile, float num[])
{
	float avg;
	float sum = 0;
	for(int i = 0; i < LEN; i++)
	{
		fprintf(sFile, "%.4f\n\n", num[i]);
		sum += num[i];
		avg = sum/LEN;
	}
		fprintf(sFile, "----------\n");
		fprintf(sFile, "Sum: %.4f\n\nAvg: %.4f\n", sum, avg);
	return;
}
