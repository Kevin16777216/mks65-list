#include "LinkList.h"
#include <stdio.h>
void print_list(struct node * list){
  int index = 0;
  printf("[");
  while (list){
    printf("Node %d : %d\n",index++, list->i);
    //Check if last element, if so, don't use comma
    if(list->next){
      printf(",");
      //go to next element
      list = list->next;
    }else{
      break;
    }
  }
  printf("]\n");
}
struct node * insert_front(struct node * list, int value){
  struct node * n = malloc(sizeof(struct node));
  //set value
  n->i = value;
  //Attach to front of list
  n->next = list;
  return n;
}
struct node * free_list(struct node * list){
  while(list){
    struct node * next = list->next;
    printf("Freeing node: %d\n", list->i);
    free(list);
    list = next;
  }
  return list;
}

struct node * remove_node(struct node *front, int data){
  struct node * trailingNode = front;
  struct node * currentNode = front->next;
  //If at head, return next element.
  if (front->i == data){
    free(front);
    return currentNode;
  }
  while(currentNode){
    if(currentNode->i == data){
      //make new link
      trailingNode->next = currentNode->next;
      //remove old ptr
      free(currentNode);
      return front;
    }
    //iterating both ptrs
    trailingNode = currentNode;
    currentNode = currentNode->next;
  }
  //return new font
  return front;
}