#include <stdio.h>
#include "LinkList.h"
int main(void) {
  struct node * list = NULL;

  printf("Printing empty list:\n");
  print_list(list);

  printf("Adding #s 0-9 to list.");
  int i;
  for(i = 0; i < 10; i++){
    list = insert_front(list, i);
  }
  
  printf("Printing list:\n");
  print_list(list);

  printf("Removing 9:\n");
  list = remove_node(list, 9);
  print_list(list);

  printf("Removing 4:\n");
  list = remove_node(list, 4);
  print_list(list);
  
  printf("Removing 0:\n");
  remove_node(list, 0);
  print_list(list);
  
  printf("Removing -1:\n");
  list = remove_node(list, -1);
  print_list(list);

  list = free_list(list);
  printf("Printing list:\n");
  print_list(list);
  free(list);
  return 0;
}
