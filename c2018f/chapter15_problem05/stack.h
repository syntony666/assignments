/* stack.c及chapter15_problem05.c之標頭檔 */

#ifndef STACK_H
#define STACK_H

/* 定義堆疊大小 */
#define STACK_SIZE 100

/* 函式定義 */
void push(int a);
int pop();
void overflow();
void underflow();
int check_top();

#endif //STACK_H
