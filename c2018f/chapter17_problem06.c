/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: 呂柏鴻 */
/* ID: 107820016 */
/* Date: 2019.1.4 */
/* Purpose: 字串排序 */
/* Change History: log the change history of the program */
/********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 20
#define MAX_WORDS 50

int read_line(char str[], int n);
int compare_strings(const void *p, const void *q);

int main(void) {
  char *words[MAX_WORDS], word[MAX_LEN + 1];
  int i, num_words = 0;

  for (;;) {

    if (num_words == MAX_WORDS) {
      printf("----- No Space Left -----");
      break;
    }

    printf("Enter word: ");
    read_line(word, MAX_LEN);

    if (strlen(word) == 0) {
      break;
    }

    words[num_words] = (char *)malloc(strlen(word) + 1);

    if (words[num_words] == NULL) {
      printf("----- No Space Left -----");
      break;
    }

    strcpy(words[num_words], word);
    num_words++;
  }

  qsort(words, num_words, sizeof(char *), compare_strings);

  printf("\nIn sorted order: ");

  for (i = 0; i < num_words; i++)
    printf(" %s", words[i]);

  printf("\n");
  return 0;
}

int read_line(char str[], int n) {
  int ch, i = 0;
  while ((ch = getchar()) != '\n') {

    if (i < n)
      str[i++] = ch;
  }
  str[i] = '\0';
  return i;
}

int compare_strings(const void *p, const void *q) {
  return strcmp(*(char **)p, *(char **)q);
}