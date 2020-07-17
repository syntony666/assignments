/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 */
/* Date: 2018.12.12 */
/* Purpose: ���y�޲z */
/* Change History: log the change history of the program */
/********************************************************************/

#include <stdio.h>
#include "read_line.h"

#define NAME_LEN 25
#define MAX_PARTS 100

int read_line(char str[], int n);

/* �]�w������ */
struct part {
	int number;
	double price;
	char name[NAME_LEN + 1];
	int on_hand;
} inventory[MAX_PARTS];

/* �w�]��0�Ӫ��� */
int num_parts = 0;

/* �w�q�禡 */
int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

int main(void)
{
	char code;

	/* ��J�u�@�X */
	for (;;) {
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while (getchar() != '\n')
			;
		switch (code) {
		case 'i': insert();	/* ��J���� */
			break;
		case 's': search();	/* �M�䪫�� */
			break;
		case 'u': update();	/* ��s�����T */
			break;
		case 'p': print();	/* ��X�����T */
			break;
		case 'q': return 0;	/* �����{�� */
		default: 
			printf("Illegal code\n");
		}
	}
	printf("\n");
}

/* �M�䪫�󸹽X, �Y�䤣��, �h�^��-1 */
int find_part(int number)
{
	int i;

	for (i = 0; i < num_parts; i++) {
		if (inventory[i].number == number)
			return i;
	}
	return -1;
}

/* ��J���� */
void insert(void)
{
	int part_number;
	double part_price;

	/* �Y��Ʈw�w��, �ǰe�T�� */
	if (num_parts == MAX_PARTS) {
		printf("Database is full; can't add more parts.\n");
		return;
	}

	/* ��J���󸹽X */
	printf("Enter part number: ");
	scanf("%d", &part_number);

	if (find_part(part_number) >= 0) {
		printf("Part already exists.\n");
		return;
	}

	inventory[num_parts].number = part_number;


	/* ��J����W�� */
	printf("Enter part name: ");
	read_line(inventory[num_parts].name, NAME_LEN);

	/* ��J���� */
	printf("Enter part price: $");
	scanf("%lf", &part_price);

	if (part_price < 0) {
		printf("Invalid price");
		return;
	}

	inventory[num_parts].price = part_price;


	/* ��J�ƶq */
	printf("Enter quantity on hand: ");
	scanf("%d", &inventory[num_parts].on_hand);

	num_parts++;
}

/* �M�䪫�� */
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

/* ��s�����T */
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

/* ��X�����T */
void print(void)
{
	int i;

	printf("Part Number   Part Name                "
		"Part Price    Quantity on Hand\n");
	for (i = 0; i < num_parts; i++)
		printf("%7d       %-25s$%7.2f%11d\n", inventory[i].number,
			inventory[i].name, inventory[i].price, inventory[i].on_hand);
}

/* Ū���r�� */
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