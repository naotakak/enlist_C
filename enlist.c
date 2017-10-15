#include <stdio.h>
#include <stdlib.h>

struct node {
  int i;
  struct node * next;
};

void print_list(struct node *);
struct node * insert_front(struct node *, int);
struct node * free_list(struct node *);

int main() {
  struct node * start;
  start = (struct node *)malloc( sizeof(struct node) );
  int i = 1;
  printf("\n\nBuilding up list [10, 9, ...  0]\n");
  for (; i < 12; i ++) {
    printf("start node: %p", start);
    print_list(start);
    start = insert_front(start, i);
  }
  start = free_list(start);
  printf("\nfreed list:%p\n", start);
  return 0;
}

void print_list(struct node * list) {
  printf("[ ");
  while (list) {
    printf("%d ", (* list).i);
    list = (* list).next;
  }
  printf("]\n");
}

struct node * insert_front(struct node * next, int val) {
  struct node * new;
  new = (struct node *)malloc( sizeof(struct node) );
  (* new).next = next;
  (* new).i = val;
  return new;
}

struct node * free_list(struct node * list) {
  struct node * p;
  while (list) {
    p = (* list).next;
    free(list);
    list = p;
  }
  return list;
}
