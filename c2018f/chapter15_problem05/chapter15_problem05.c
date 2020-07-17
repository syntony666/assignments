/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: 呂柏鴻 */
/* ID: 107820016 */
/* Date: 2018.12.10 */
/* Purpose: RPN運算(使用標頭檔) */
/* Change History: log the change history of the program */
/********************************************************************/

/* chapter15_problem05.c : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。 */

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void evaluate();

int main() {

	for (;;)
	{
		/* 輸入計算式 */
		printf("Enter an RPN expression: ");
		evaluate();

		/* 輸出結果 */
		printf("Value of expression: %d\n", pop());
	}

	return 0;
}

/* RPN計算 */
void evaluate() {
	char ch;
	int op1, op2;
	for (;;) {
		scanf(" %c", &ch);
		switch (ch) {

			/* 若為運算子，先把數字移出堆疊 */
		case'+': case'-': case'*': case'/':
			op1 = pop();
			op2 = pop();
		}

		/* 若輸入為數字, 則將數字移入堆疊 */
		if (ch >= '0' && ch <= '9')
		{
			push(ch - '0');
		}

		/* 若為運算子, 則移入計算結果至堆疊中 */
		else if (ch == '+') {
			push(op1 + op2);
		}
		else if (ch == '-') {
			push(op1 - op2);
		}
		else if (ch == '*') {
			push(op1 * op2);
		}
		else if (ch == '/') {
			push(op1 / op2);
		}
		else if (ch == '=')
		{
			break;
		}


		else
		{
			printf("\n");
			exit(0);
		}
	}

	/* 若結束後還有數字在堆疊中, 告訴使用者錯誤訊息 */
	if (check_top() > 1) {
		printf("Too many operand in this expression.");
		exit(EXIT_FAILURE);
	}

}