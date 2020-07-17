/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: 呂柏鴻 */
/* ID: 107820016 */
/* Date: 2018.10.22 */
/* Purpose: 將一句話倒過來寫 */
/* Change History: log the change history of the program */
/********************************************************************/


#include<stdio.h>
#include<string.h>

int main() {

	char ch, ter = 0, str[1000];
	int last;

	int i;

	printf("Enter a sentence: ");

	/* 輸入句子 */
	for (i = 0; (ch = getchar()) != '\n'; i++) {
		if (ch == '.' || ch == '?' || ch == '!') {  /* 若遇到結束的標點符號停止讀取句子,並特別標註此標點符號 */
			last = i;
			ter = ch;
			break;
		}
		str[i] = ch;
		
	}

	printf("Reversal of sentence: ");

	int j;

	/* 輸出轉換後句子 */
	for (i = last; i >= 0; i--) {     /* 從後面開始讀取 */
		if (str[i] == ' ') {
			for (j = i + 1; j != last; j++) {  /* 若遇到空格即可輸出字元 */

				putchar(str[j]);

			}

			last = i;
			putchar(str[i]);

		}
	}

	/* 輸出第一個單字 */
	for (i = 0; str[i] != ' '; i++) {
		putchar(str[i]);
	}
	
	printf("%c\n\n", ter);  /* 輸出標點符號 */
	
	return 0;
}