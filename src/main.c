#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.c"
#include "btree.c"

void print_tree(struct tree_node *t, int depth){ //prints tree for the node t, with input of depth
  if(Empty(t)){
    return;
  }
  for (int i = 0; i < depth; i++)
  {
    printf("-");
  }
  printf("|%d\n", t->item);

  print_tree(t->left, depth + 1);
  print_tree(t->right, depth + 1);

}
// File for sandboxing and trying out code
int main(int argc, char **argv) {
  // Add your code
  node *xtest = make_node(1, make_node(2, make_node(3, make_node(4, make_node(5, NULL)))));
 
  node *mxtest = map(xtest, square);

  int sum;
  print_list(mxtest);
  sum = sum_squares(mxtest);

  printf("\n%d\n\n", sum);
  
  node *ns = make_node(1, NULL);
  
  node *mns = map(ns, square);

  print_list(mns);
  sum = sum_squares(mns);

  printf("\n%d\n\n", sum);

  //part 4
  struct tree_node *test_root = NULL;
  
  printf("\n\n");
  test_root = Initialize(test_root);
  test_root = Insert(20, test_root);
  test_root = Insert(5, test_root);
  test_root = Insert(1, test_root);
  test_root = Insert(15, test_root);
  test_root = Insert(9, test_root);
  test_root = Insert(7, test_root);
  test_root = Insert(12, test_root);
  test_root = Insert(30, test_root);
  test_root = Insert(25, test_root);
  test_root = Insert(40, test_root);
  test_root = Insert(30, test_root);
  test_root = Insert(42, test_root);

  print_tree(test_root, 0);

  if ((Contains(1, test_root)))
  {
    printf("it contains the number\n");
  }
  else{
    printf("it DOESNT contain number\n");
  } 
  
  if ((Contains(3, test_root)))
  {
    printf("it contains the number\n");
  }
  else{
    printf("it DOESNT contain number\n");
  }

  if ((Contains(42, test_root)))
  {
    printf("it contains the number\n");
  }
  else{
    printf("it DOESNT contain number\n");
  }


  test_root = Insert(-1, test_root);
  
  test_root = Insert(-1, test_root);
  print_tree(test_root, 0);
  test_root = Remove(-1, test_root);

  print_tree(test_root, 0);

  test_root = Remove(-1, test_root);

  print_tree(test_root, 0);

  return 0;
}