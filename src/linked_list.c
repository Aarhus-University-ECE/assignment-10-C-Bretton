#include <assert.h> /* assert */
#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */

#include "linked_list.h"

/* functions to create lists */
node *make_node(int v, node *q) {
  node *p = malloc(sizeof(node));
  p->value = v;
  p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list(node *p) {
  node *q;
  while (p != NULL) {
    q = p->next;
    free(p);
    p = q;
  }
}

/* print list to console */
void print_list(node *p) {
  // Add your code for exercise 1
  // There is NO testcode for this
  printf("%d ", p->value); // print current value

  if(p->next != NULL) //if next element is not empty
  {
    print_list(p->next); //call print_list on next element
  }
  else{
    return; //else return
  }

}

int sum_squares(node *p) {
  // Add your code for excercise 2
  // You can find the tests in tests.cpp

  //if node is not NULL
  if(p != NULL)
  {
    return p->value*p->value + sum_squares(p->next); //return current node value sqaured + call sum_squares to the next node
  }
  else if(p == NULL)
  {
    return 0; //if current node is NULL, return 0;
  }

}

typedef int (*fn_int_to_int)(int);

node *map(node *p, fn_int_to_int f) { 
  // Add your code for excercise 3

  if (p == NULL) //if current node is NULL
  {
    return NULL; //return NULL
  }
  else
  {
    return make_node(f(p->value), map(p->next, f)); //return the current node value squared by function f, and the map of next node
  }

}

int square(int x) { return x * x; }

// example of another function that can be passed to map
// returns the sign of the number
// -1 if negative, 0 if zero, 1 if positive
int sign(int x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }
