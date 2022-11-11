#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_node *Insert(int x, struct tree_node *t) {
  // Insert item x into the tree t

  
  //If an Empty Node is found input item x and initialize a left and right for it
  if (Empty(t))
  {
    t->item = x;

    struct tree_node *left = Initialize(left);
    t->left = left;
    
    struct tree_node *right = Initialize(right);
    t->right = right;

  }
  //else if x is less or equal to current node item go to the left child
  else if(x <= t->item){
    Insert(x, t->left);
  }
  //else if x is larger than current node item go to the right child
  else if(x > t->item){
    Insert(x, t->right);
  }

  return t; //return the node
}

struct tree_node *Remove(int x, struct tree_node *t) {
  // Remove one item from the tree t

  //Check if the tree contains the item, if not return node t
  if(!Contains(x, t)){
     return t;
  }
  //if x is equal to the current node
  if (x == t->item)
  {
    

    //if there is no children
    if(Empty(t->left) && Empty(t->right)){
      
      //the item is NULL'ed, to remove the item from the tree
      t->item = NULL;
      
    }
    //if there is only one child
    else if(Empty(t->left) != Empty(t->right)){
      
      //if the right child is not empty
      if (!Empty(t->right))
      {

        //set the item as the right childs item, to remove the current item
        t->item = t->right->item;
        Remove(t->item, t->right); //then removes the right child item, from the right child tree, recursive

        
      }
      //else the left child is not empty
      else{
        
        //set the item as the left childs item, to remove current item
        t->item = t->left->item;
        Remove(t->item, t->left); //then remove the left item, from the left child tree, recursive 
        

      }

    }
    //two children
    else{
      
      //if there are 2 children, the item removed should be replaces with either
      //the smallest in the right tree or the largest in the left tree. This will go for the smallest in the left

      //Creating a temporary clone of the right child, to find the value to swap.
      struct tree_node *temp = Initialize(temp);
      temp = t->right;
      
      //search for the left most item in the right child, to replace the item to be removed
      while(!Empty(temp->left)){
        temp = temp->left;
      }

      //replace the nodes item with the found replacement
      t->item = temp->item;
      Remove(t->item, t->right); //then remove the replacement which was found in the right child tree


    }
  }
  //else if item is not found, and x is less than current node item, remove item from the left child
  else if(x < t->item){
    Remove(x, t->left);
  }
  //else if x is larger than current node item, remove it from the right child
  else if(x > t->item){
    Remove(x, t->right); 
  }

  //return node t
  return t;
}

int Contains(int x, struct tree_node *t) {

  // Return true if the tree t contains item x. Return false otherwise.
  //if the tree is empty, return 0 (false)
  if(Empty(t)){
    return 0;
  }
  //else if x is equal to current node return true
  else if (x == t->item)
  {
    return 1;
  }
  //if x is less than item and the left child is not NULL, check the left child if it contains x
  else if(x < t->item && t->left != NULL){
    return Contains(x, t->left);
  }
  //if x is larger than item and the right child is not NULL, check if the right child contains x
  else if(x > t->item && t->right != NULL){
    return Contains(x, t->right); 
  }
  //else x was not found return false
  else{
    return 0;
  }

  
}

struct tree_node *Initialize(struct tree_node *t) {
  // Create an empty tree node
  t = (struct tree_node*)malloc(sizeof(struct tree_node));
  //set item, left child and right child to NULL
  t->item = NULL; 
  t->left = NULL;
  t->right = NULL;

  return t; //return the initialized node
}

int Empty(struct tree_node *t) {
  // Test if empty
  if(t->item == NULL){
    return 1; //if the first item in the tree t is NULL, tree is empty, return true
  }
  else{
    return 0; //else tree is not empty return false
  }
  
}

int Full(struct tree_node *t) {
  // Test if full

  //it cant be checked if full, as the list is dynamic and not a set size.
  return 0;
}
