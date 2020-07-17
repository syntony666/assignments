/* readline.c: 對應到先行編譯過之標頭的來源檔案; 編譯需要此才可成功 */

#include "readline.h"

/* 讀取字串 */
int read_line(char str[], int n)
{
	int ch, i = 0;

	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
	str[i] = '\0';
	return i;
}
