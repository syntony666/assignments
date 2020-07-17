/********************************************************************/
/* Class: Computer Programming, Fall 2018							*/
/* Author: 呂柏鴻													*/
/* ID: 107820016													*/
/* Date: 2018.12.7													*/
/* Purpose: 外文姓名轉換 */
/* Change History: log the change history of the program			*/
/********************************************************************/

#include <stdio.h>

#define LEN 100

void reverse_name(char *name);

int main() 
{

	char full_name[LEN], first_name[LEN / 2], last_name[LEN / 2];

	/* 輸入名字 */
	printf("Enter a first and last name: ");

	/* 將兩個字串格式化 */
	scanf("%s %s", first_name, last_name);
	sprintf(full_name, "%s %s", first_name, last_name);

	/* 輸出字串 */
	printf("The reversal name: ");

	reverse_name(&full_name);
	
}

/* 姓名轉換 */
void reverse_name(char *name) {

	char first_name_letter = 0;
	int space = 0;

	for (; *name ; name++)
	{
		if (!first_name_letter)
		{
			if (*name != ' ')
				first_name_letter = *name;
		}
		else if (space == 0)
		{
			if (*name == ' ')
				space = 1;
		}
		else if (*name != ' ')
			putchar(*name);
	}

	printf(", %c.", first_name_letter);

}