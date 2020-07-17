/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: 呂柏鴻 */
/* ID: 107820016 */
/* Date: 2018.12.10 */
/* Purpose: 提醒事項(使用標頭檔) */
/* Change History: log the change history of the program */
/********************************************************************/

/* chapter15_problem04.c : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。 */

#include "readline.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char reminders[MAX_REMIND][MSG_LEN + 3];
	char day_str[3], msg_str[MSG_LEN + 1];
	int day, i, j, num_remind = 0;

	for (;;)
	{
		if (num_remind == MAX_REMIND)
		{
			printf("-- No space left --\n");
			break;
		}

		/* 輸入提醒事項與時間 */
		printf("Enter a day and reminder: ");
		scanf("%2d", &day);
		if (day == 0)
			break;
		sprintf(day_str, "%2d", day);
		read_line(msg_str, MSG_LEN);

		for (i = 0; i < num_remind; i++)
			if (strcmp(day_str, reminders[i]) < 0)
				break;
		for (j = num_remind; j > i; j--)
			strcpy(reminders[j], reminders[j - 1]);

		strcpy(reminders[i], day_str);
		strcat(reminders[i], msg_str);

		num_remind++;
	}

	/*　輸出結果　*/
	printf("\nDay Reminder\n");
	for (i = 0; i < num_remind; i++)
		printf(" %s\n", reminders[i]);

	return 0;
}
