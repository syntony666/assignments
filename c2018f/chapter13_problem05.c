/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: 呂柏鴻 */
/* ID: 107820016 */
/* Date: 2018.12.5 */
/* Purpose: 用command line求出總和 */
/* Change History: log the change history of the program */
/********************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i, sum = 0;

	if (argc == 1)
	{
		printf("Usage: Enter integers as command-line arguments.");
		return 0;
	}

	/* 求出總和 */
	for (i = 1; i < argc; i++) {
		sum += atoi(argv[i]);
	}

	printf("Total: %d", sum);

	return 0;
}