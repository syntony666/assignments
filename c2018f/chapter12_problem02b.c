/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: 呂柏鴻 */
/* ID: 107820016 */
/* Date: 2018.12.5 */
/* Purpose: 從前至後讀取確認是否與反向相同 */
/* Change History: log the change history of the program */
/********************************************************************/

#include <stdio.h>
#include <ctype.h>

#define BUFF 50

int main()
{
	char ch, msg[BUFF];
	char *i, *j;

	/* 輸入句子 */
	printf("Enter a sentence: ");

	/* 讀取是字母的字元 */
	for (i = &msg[0]; (ch = tolower(getchar())) != '\n'; i++){
		if (isalpha(ch)) *i = ch;
	}

	/* 檢查 */
		for (j = i - 1, i = &msg[0]; j >= &msg[0]; i++)
	{
		if (*i == 0) break;
		if (*i != *j)
		{
			printf("Not a palindrome");
			return 0;
		}
		j--;
	}
	printf("Palindrome");

}