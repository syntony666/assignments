/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 (your student ID here) */
/* Date: 2018.09.26 (put program development started date here) */
/* Purpose: ����X	*/
/* Change History: log the change history of the program */
/********************************************************************/


#include<stdio.h>
#include<string.h>

int main() {
	int item_num, date_y, date_m, date_d;
	float price;

	printf("Enter item number: ");
	scanf("%d", &item_num);		/* ��J���X */

	printf("Enter unit price: ");
	scanf("%f", &price);		/* ��J���� */

	printf("Enter purchase date (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &date_m, &date_d, &date_y);	/* ��J��� */

	/* ��X��� */
	printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n%d\t\t$ %-8.2f\t%d/%d/%d", item_num, price, date_m, date_d, date_y);
	
	return 0;
}