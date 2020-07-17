/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: 呂柏鴻 */
/* ID: 107820016 */
/* Date: 2018.12.12 */
/* Purpose: 物流管理 */
/* Change History: log the change history of the program */
/********************************************************************/

#include <stdio.h>
#include "read_line.h"

#define NAME_LEN 25
#define MAX_PARTS 100

int read_line(char str[], int n);

/* 設定物件資料 */
struct part {
	int number;
	double price;
	char name[NAME_LEN + 1];
	int on_hand;
} inventory[MAX_PARTS];

/* 預設有0個物件 */
int num_parts = 0;

/* 定義函式 */
int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

int main(void)
{
	char code;

	/* 輸入工作碼 */
	for (;;) {
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while (getchar() != '\n')
			;
		switch (code) {
		case 'i': insert();	/* 輸入物件 */
			break;
		case 's': search();	/* 尋找物件 */
			break;
		case 'u': update();	/* 更新物件資訊 */
			break;
		case 'p': print();	/* 輸出物件資訊 */
			break;
		case 'q': return 0;	/* 結束程式 */
		default: 
			printf("Illegal code\n");
		}
	}
	printf("\n");
}

/* 尋找物件號碼, 若找不到, 則回傳-1 */
int find_part(int number)
{
	int i;

	for (i = 0; i < num_parts; i++) {
		if (inventory[i].number == number)
			return i;
	}
	return -1;
}

/* 輸入物件 */
void insert(void)
{
	int part_number;
	double part_price;

	/* 若資料庫已滿, 傳送訊息 */
	if (num_parts == MAX_PARTS) {
		printf("Database is full; can't add more parts.\n");
		return;
	}

	/* 輸入物件號碼 */
	printf("Enter part number: ");
	scanf("%d", &part_number);

	if (find_part(part_number) >= 0) {
		printf("Part already exists.\n");
		return;
	}

	inventory[num_parts].number = part_number;


	/* 輸入物件名稱 */
	printf("Enter part name: ");
	read_line(inventory[num_parts].name, NAME_LEN);

	/* 輸入價格 */
	printf("Enter part price: $");
	scanf("%lf", &part_price);

	if (part_price < 0) {
		printf("Invalid price");
		return;
	}

	inventory[num_parts].price = part_price;


	/* 輸入數量 */
	printf("Enter quantity on hand: ");
	scanf("%d", &inventory[num_parts].on_hand);

	num_parts++;
}

/* 尋找物件 */
void search(void)
{
	int i, number;

	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);
	if (i >= 0) {
		printf("Part name: %s\n", inventory[i].name);
		printf("Part price: %f\n", inventory[i].price);
		printf("Quantity on hand: %d\n", inventory[i].on_hand);
	}
	else
		printf("Part not found.\n");
}

/* 更新物件資訊 */
void update(void)
{
	int i, number, change;

	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);
	if (i >= 0) {
		printf("Enter change in quantity on hand: ");
		scanf("%d", &change);
		inventory[i].on_hand += change;
	}
	else
		printf("Part not found.\n");
}

/* 輸出物件資訊 */
void print(void)
{
	int i;

	printf("Part Number   Part Name                "
		"Part Price    Quantity on Hand\n");
	for (i = 0; i < num_parts; i++)
		printf("%7d       %-25s$%7.2f%11d\n", inventory[i].number,
			inventory[i].name, inventory[i].price, inventory[i].on_hand);
}

/* 讀取字串 */
int read_line(char str[], int n)
{
	int ch, i = 0;

	while (isspace(ch = getchar()))
		;
	while (ch != '\n' && ch != EOF) {
		if (i < n)
			str[i++] = ch;
		ch = getchar();
	}
	str[i] = '\0';
	return i;
}