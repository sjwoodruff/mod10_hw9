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

/* Main Program */
int main (int argc, char *argv[])
{
//Open file
	FILE* zone1 = fopen("zone1.txt", "r");

//File error messgae
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
	float m, b;
	int zone[9];

//Save variables from file
	while (fscanf(zone1, "%d", &zone[counter]) != EOF)
	{  
	if (counter % 2 == 0 || counter == 0)
		{
		x = zone[counter];
		sumx += x;
		sumx2 += x*x;
		counter++;
		}
	else
		{
		y = zone[counter];
		sumy += y;
		sumxy += x*y;
		counter++;
		}
	}

//Calculate values
	m = (sumx*sumy - 4.0*sumxy)/(sumx*sumx - 4.0*sumx2);
	b = (sumx*sumxy - sumx2*sumy)/(sumx*sumx - 4.0*sumx2);
	printf("m = %1.3f	b = %1.3f\n", m, b);

	return 0;
}
