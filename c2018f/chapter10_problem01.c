/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 */
/* Date: 2018.11.5 */
/* Purpose: �A���ˬd */
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
	int nested = 1;   /* ���]�_����l�Ȭ��u */

	printf("Enter parentheses and/or braces: ");

	/* Ū����J���A�� */
	while ( (input = getchar()) !='\n')
	{
		if (input == '{' || input == '(') {   /* �Y��J��{��(, �h����push */
			push(input);
		}
		if (input == ')' && pop() != '(') {   /* �Y��J��), �B�e�@������(, �h�_�������T */
			nested = 0;
		}
		if (input == '}' && pop() != '{') {   /* �Y��J��{, �B�e�@������}, �h�_�������T */
			nested = 0;
		}
	}
	
	/* �Y��C���A�����Q�M������٦�(��{���_������ */
	if (empty() == 0) {
		nested = 0;
	}

	/* �Y�T�w�_������, �h��X���\�T��, �Y�_, �h��X���ѰT�� */
	if (nested) {
		printf("Parentheses/braces are nested properly\n\n");
	}
	else
	{
		printf("Parentheses/braces are not nested properly\n\n");
	}

	return 0;
}

/* �Y��C�w���h�i�D�ϥΪ�{��(�L�h, �Y�_, �h�N��J���ƭȩ�i��C�� */
void push(char ch) {
	if (full()) {
		overflow();
	}
	else {
		context[top++] = ch;
	}
}

/* �M���C���r��, �Y�L�r���h�i�D�ϥΪ�)��}�L�h, �Y�_, �^�ǫe�@�Ӧr���B�N���r���q��C�M�� */
char pop() {
	if (empty()) {
		underflow();
	}
	else {
		return context[--top];
	}
}

/* �T�{��C�O�_�w�� */
int full() {
	if (top == STACK_SIZE) {
		return 1;
	}
	else {
		return 0;
	}
}

/* �T�{��C�O�_���� */
int empty() {
	if (top == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

/* ��C�w�����ܥB���A�^��main�ˬd */
void overflow() {
	printf("Too many characters\n");
	exit(0);
}

/* ��C���Ŵ��ܥB���A�^��main�ˬd */
void underflow() {
	printf("Too many right parentheses/braces\n");
	exit(0);
}