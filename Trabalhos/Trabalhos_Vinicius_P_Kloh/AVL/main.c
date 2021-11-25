#include <stdlib.h>
#include <stdio.h>

#include "avl.h"

/*
  auxiliar function
*/
void flush_in();
/*
  end auxiliar function
*/

int main(void){
  Tree* tree;
  create_tree(&tree);
  int out = 0, value;
  char option;

  printf("\n\n\t\t --_--_--_--_--_--_--_--_--_--_--_--\n");
  printf("\t\t\t  Balanced Tree (AVL)\n");
  printf("\t\t --_--_--_--_--_--_--_--_--_--_--_--\n\n\n");

  do{
    printf("\nEnter\n \'i\' to insert a new node,\n \'d\' to delete a node,\n \'p\' to print the tree, \n \'f\' to free the tree or\n \'e\' to exit.\n");
    scanf("%c", &option);
    flush_in();

    switch (option) {
      case 'i':
        printf("Enter the value of the new node (use integer type).\n");
        scanf("%d", &value);
        flush_in();
        if(insert(&tree, value))
          printf("\n");
        else
          printf("\n");
          print_tree(&tree, 1);
      break;
      case 'd':
        printf("Enter the value of the node (use integer type).\n");
        scanf("%d", &value);
        flush_in();
        if(delete(&tree, value)){
          printf("Node (%d) deleted.\n\n", value);
          print_tree(&tree, 1);
        }
        else
          printf("Can\'t delete the node (%d)\n", value);
      break;
      case 'p':
        printf("Printing the tree...\n\n");
        print_tree(&tree, 1);
      break;
      case 'f':
        destroy_tree(&tree);
        return 0;
      break;
      case 'e':
        out = 1;
      break;
      default:
        printf("Invalid option.\n");
      break;
    }
  } while(!out);

  return 0;
}

void flush_in(){
   int ch;
   while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}
