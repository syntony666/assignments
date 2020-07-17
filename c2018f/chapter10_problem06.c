/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: 呂柏鴻 */
/* ID: 107820016 */
/* Date: 2018.11.12 */
/* Purpose: RPN計算系統 */
/* Change History: log the change history of the program */
/********************************************************************/

#include <stdio.h>
#include <stdlib.h>

/* 定義堆疊大小 */
#define STACK_SIZE 100

/* 全域變數 */
char rpn[STACK_SIZE];
int top = 0;

/* 函式定義 */
void push(int a);
int pop();
void evaluate();
void overflow();
void underflow();

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
		if (ch >= '0' && ch <='9')
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
	if (top > 1) {
		printf("Too many operand in this expression.");
		exit(EXIT_FAILURE);
	}

}

/* 若佇列已滿則告訴使用者數字過多, 若否, 則將輸入之數值放進佇列中 */
void push(char a) {
	if (top == STACK_SIZE) 
	{
		overflow();
	}
	else 
	{
		rpn[top++] = a;
	}
}

/* 尋找佇列中字元, 若無字元則告訴使用者運算子過多, 若否, 回傳前一個字元且將此字元從佇列清除 */
int pop() {
	if (top == 0) {
		underflow();
	}
	else
	{
		return rpn[--top];
	}
}

/* 佇列已滿提示且不再回到evaluate檢查 */
void overflow() {
	printf("Expression is too complex");
	exit(EXIT_FAILURE);
}

/* 佇列為空提示且不再回到evaluate檢查 */
void underflow() {
	printf("Not enough operands in expression");
	exit(EXIT_FAILURE);
}