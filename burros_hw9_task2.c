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
//Set variables
	int counter = 0;
	float x = 0.0, sumx = 0.0;
	float y = 0.0, sumy = 0.0;
	float sumxy = 0.0;
	float sumx2 = 0.0;

//Save variables from file
	while (!feof(zone1))
	{
		zone1[counter] = x;
		sumx += x;
		sumx2 += x*x;
		counter++;

		zone1[counter] = y;
		sumy += y;
		sumxy += x*y;
		counter++;
	}
//Calculate values

	float m, b;
	m = (x*y - 4.0*sumxy)/(x*x - 4.0*sumx2);
	b = (x*sumxy - sumx2*y)/(x*x - 4.0*sumx2);
	printf("m = %1.3f	b = %1.3f", m, b);

	return 0;
}
/* Function Defenitions */


