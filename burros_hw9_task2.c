/*
 * =====================================================================================
 *
 *       Filename:  burros_hw9_task2.c
 *       	Usage:  ./burros_hw9_task2.c
 *    Description:  hw9_task2 
 *
 *        Version:  1.0
 *        Created:  04/05/2017 01:14:43 AM
 *       Compiler:  gcc -Wall -Werror
 *         Author:  Sterling, Sherry
 * =====================================================================================
 */

#include <stdio.h>		/* For Standard I/O */
#include <stdlib.h>

/* Function Prototypes */

/* Main Program */
int main (int argc, char *argv[])
{
	FILE* zone1 = fopen("zone1.txt", "r");

	if (zone1 == NULL)
	{
		printf("The file was not successfully opened.\n");
		exit(1);
	}
	
	int counter = 0;
	int x = 0, sumx = 0;
	int y = 0, sumy = 0;
	int sumxy = 0;
	int sumx2 = 0;
	char ch;
	int zone[10];

	while (!feof(zone1))
	{
		zone[counter] = ch;
		x = ch[counter] - '0';
		x += sumx;
		counter++;

		zone1[counter] = y;
		y += sumy;
		counter++;
	}

	fclose(zone1);
	return 0;
}
/* Function Defenitions */


