/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: 呂柏鴻 */
/* ID: 107820016 */
/* Date: 2018.11.5 */
/* Purpose: 括號檢查 */
/* Change History: log the change history of the program */
/********************************************************************/


#include<stdio.h>

#define STACK_SIZE 100

char context[STACK_SIZE];
int top = 0;

void push(char ch);
char pop();
int full();
int empty();
void overflow();
void underflow();



int main() {

	char input;
	int nested = 1;   /* 假設巢狀原始值為真 */

	printf("Enter parentheses and/or braces: ");

	/* 讀取鍵入之括號 */
	while ( (input = getchar()) !='\n')
	{
		if (input == '{' || input == '(') {   /* 若鍵入為{或(, 則執行push */
			push(input);
		}
		if (input == ')' && pop() != '(') {   /* 若鍵入為), 且前一項不為(, 則巢狀不正確 */
			nested = 0;
		}
		if (input == '}' && pop() != '{') {   /* 若鍵入為{, 且前一項不為}, 則巢狀不正確 */
			nested = 0;
		}
	}
	
	/* 若佇列中括號未被清除表示還有(或{未巢狀完成 */
	if (empty() == 0) {
		nested = 0;
	}

	/* 若確定巢狀完成, 則輸出成功訊息, 若否, 則輸出失敗訊息 */
	if (nested) {
		printf("Parentheses/braces are nested properly\n\n");
	}
	else
	{
		printf("Parentheses/braces are not nested properly\n\n");
	}

	return 0;
}

/* 若佇列已滿則告訴使用者{或(過多, 若否, 則將輸入之數值放進佇列中 */
void push(char ch) {
	if (full()) {
		overflow();
	}
	else {
		context[top++] = ch;
	}
}

/* 尋找佇列中字元, 若無字元則告訴使用者)或}過多, 若否, 回傳前一個字元且將此字元從佇列清除 */
char pop() {
	if (empty()) {
		underflow();
	}
	else {
		return context[--top];
	}
}

/* 確認佇列是否已滿 */
int full() {
	if (top == STACK_SIZE) {
		return 1;
	}
	else {
		return 0;
	}
}

/* 確認佇列是否為空 */
int empty() {
	if (top == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

/* 佇列已滿提示且不再回到main檢查 */
void overflow() {
	printf("Too many characters\n");
	exit(0);
}

/* 佇列為空提示且不再回到main檢查 */
void underflow() {
	printf("Too many right parentheses/braces\n");
	exit(0);
}