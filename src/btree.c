#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_node *Insert(int x, struct tree_node *t) {
  // Insert item x into the tree t

  
  //If an Empty Node is found create a new node with item x and set t as the created node
  if (Empty(t))
  {
    
    //Create new node t, with the item set as x
    t = CreateNode(x);
  }
  //else if x is less or equal to current node item go to the left child
  else if(x <= t->item){
    t->left = Insert(x, t->left);
  }
  //else if x is larger than current node item go to the right child
  else if(x > t->item){
    t->right = Insert(x, t->right);
  }

  return t; //return the node
}

struct tree_node *Remove(int x, struct tree_node *t) {
  // Remove one item from the tree t

  //Check if the tree contains the item, if not return node t
  if(!Contains(x, t)){
     return t;
  }
  //if x is equal to the current node item
  if (x == t->item)
  {
    

    //if there is no children
    if(Empty(t->left) && Empty(t->right)){
      
      //make a temp as the either t left or right which is NULL, free t, and then return t as NULL with return temp
      struct tree_node *temp = t->right;
      free(t);
      return temp;
    }
    //if there is only one child
    else if(Empty(t->left) != Empty(t->right)){
      
      //if the right child is not empty
      if (!Empty(t->right))
      {
        //set temp as t's right child, then free t and return temp (right child)
        struct tree_node *temp = t->right;
        free(t);
        return temp;
        
      }
      //else the left child is not empty
      else{
        //set temp as t's left child, then free t and return temp (left child)
        struct tree_node *temp = t->left;
        free(t);
        return temp;

      }

    }
    //two children
    else{
      
      //if there are 2 children, the item removed should be replaces with either
      //the smallest in the right tree or the largest in the left tree. This will go for the smallest in the right child

      //Creating a temp of the right child, to find the value to swap.
      struct tree_node *temp = t->right;
      
      //search for the left most item in the right child, to find the replacement
      while(!Empty(temp->left)){
        temp = temp->left;
      }
      //replace the t's item with the found replacement temp item
      t->item = temp->item;
      Remove(t->item, t->right); //then remove the replacement from right child
      return t;
    }
  }
  //else if item is not found, and x is less than current node item, remove item from the left child
  else if(x < t->item){
    t->left = Remove(x, t->left);
    return t;
  }
  //else if x is larger than current node item, remove it from the right child
  else if(x > t->item){
    t->right = Remove(x, t->right); 
    return t;
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
  //set t as NULL
  t = NULL;
  
  return t; //return the initialized node
}

struct tree_node *CreateNode(int x) {
  // Create a new tree node with item x
  struct tree_node *newnode = malloc(sizeof(struct tree_node));
  //set item to value x and left child and right child to NULL
  newnode->item = x; 
  newnode->left = NULL;
  newnode->right = NULL;

  return newnode; //return the  created note
}


int Empty(struct tree_node *t) {
  // Test if empty
  if(t == NULL){
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
