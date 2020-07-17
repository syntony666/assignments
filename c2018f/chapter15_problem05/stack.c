/* stack.c: 對應到先行編譯過之標頭的來源檔案; 編譯需要此才可成功 */

#include "stack.h"
#include <stdlib.h>

/* 全域變數 */
char rpn[STACK_SIZE];
int top = 0;

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

/* 將top放入main使用 */
int check_top() {
	return top;
}