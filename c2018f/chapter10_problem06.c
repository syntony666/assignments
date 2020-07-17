/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 */
/* Date: 2018.11.12 */
/* Purpose: RPN�p��t�� */
/* Change History: log the change history of the program */
/********************************************************************/

#include <stdio.h>
#include <stdlib.h>

/* �w�q���|�j�p */
#define STACK_SIZE 100

/* �����ܼ� */
char rpn[STACK_SIZE];
int top = 0;

/* �禡�w�q */
void push(int a);
int pop();
void evaluate();
void overflow();
void underflow();

int main() {

	for (;;)
	{
		/* ��J�p�⦡ */
		printf("Enter an RPN expression: ");
		evaluate();

		/* ��X���G */
		printf("Value of expression: %d\n", pop());
	}
	
	return 0;
}


/* RPN�p�� */
void evaluate() {
	char ch;
	int op1, op2;
	for (;;) {
		scanf(" %c", &ch);
		switch (ch) {
		
		/* �Y���B��l�A����Ʀr���X���| */
		case'+': case'-': case'*': case'/':
			op1 = pop();
			op2 = pop();
		}

		/* �Y��J���Ʀr, �h�N�Ʀr���J���| */
		if (ch >= '0' && ch <='9')
		{
			push(ch - '0');
		}

		/* �Y���B��l, �h���J�p�⵲�G�ܰ��|�� */
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

	/* �Y�������٦��Ʀr�b���|��, �i�D�ϥΪ̿��~�T�� */
	if (top > 1) {
		printf("Too many operand in this expression.");
		exit(EXIT_FAILURE);
	}

}

/* �Y��C�w���h�i�D�ϥΪ̼Ʀr�L�h, �Y�_, �h�N��J���ƭȩ�i��C�� */
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

/* �M���C���r��, �Y�L�r���h�i�D�ϥΪ̹B��l�L�h, �Y�_, �^�ǫe�@�Ӧr���B�N���r���q��C�M�� */
int pop() {
	if (top == 0) {
		underflow();
	}
	else
	{
		return rpn[--top];
	}
}

/* ��C�w�����ܥB���A�^��evaluate�ˬd */
void overflow() {
	printf("Expression is too complex");
	exit(EXIT_FAILURE);
}

/* ��C���Ŵ��ܥB���A�^��evaluate�ˬd */
void underflow() {
	printf("Not enough operands in expression");
	exit(EXIT_FAILURE);
}