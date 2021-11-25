#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"
/* #include "queue.h" */
#include "calc.h"

/*
  auxiliar function
*/
void flush_in();
/*
  end auxiliar function
*/

int main(void){
  char infix[1024];
  char postfix[1024]; postfix[0] = '\0';
  double result;
  rpn_parser(infix, postfix);
  rpn_solver(postfix, &result);

  printf("\n\t\t\t --_--_--_--_--_--_--_--_--_--_--_--_--\n");
  printf("\n\t\t\t  Reverse Polish Notation - Calculator\n");
  printf("\n\t\t\t --_--_--_--_--_--_--_--_--_--_--_--_--\n\n\n");

  do{
    printf("Enter the expression and press \'Enter\'.\n");
    fgets(infix, 1024, stdin);

    if(!rpn_parser(infix, postfix)){
      printf("\nPostfix: \t %s\n", postfix);
      if(!rpn_solver(postfix, &result))
        printf("\nResult: \t %f\n\n", result);
    }else
      printf("\nError on parse function...\n");
    postfix[0] = '\0';
  }while(1);

  return 0;
}

void flush_in(){
   int ch;
   while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}
