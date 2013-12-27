/* Largest prime factor
 * Problem 003
 *
 * The prime factors of 13195 are 5, 7, 13, and 29.
 *
 * What is the largest prime factor of the number 600851475143?
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
  unsigned long long val;
  struct Node *next;
};

struct List {
  struct Node *first;
  struct Node *last;
};

struct List* new_list() {
  struct List *list = (struct List*) malloc(sizeof(struct List));
  list->first = list->last = NULL;
  return list;
}

int is_prime(struct List *primes, unsigned long long i) {
  struct Node *cursor = primes->first;
  while (cursor != NULL) {
    if (i % cursor->val == 0)
      return 0;
    cursor = cursor->next;
  }
  return 1;
}

void append(struct List *list, unsigned long long i) {
  if (list->last == NULL)
    list->first = list->last = (struct Node*) malloc(sizeof(struct Node));
  else
    list->last = list->last->next = (struct Node*) malloc(sizeof(struct Node));
  list->last->val = i;
}

void destroy(struct List *list) {
  struct Node *cursor;
  while (list->first != list->last) {
    cursor = list->first;
    list->first = list->first->next;
    free(cursor);
  }
  free(list->last);
  free(list);
}

int main() {
  unsigned long long n = 600851475143, i;
  struct List *primes = new_list(), *factors = new_list();
  append(primes, 2);
  append(primes, 3);

  for (i = 5; i * i <= n; i += 2) {
    if (is_prime(primes, i)) {
      append(primes, i);
      if (n % i == 0)
        append(factors, i);
    }
  }

  printf("%llu\n", factors->last->val);

  destroy(primes);
  destroy(factors);
  return 0;
}
