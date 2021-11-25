/*
 * =====================================================================================
 *
 *	  Filename:  calc.c
 *
 * Description:  reverse polish notation implementation
 *
 *       Version:  3.2.4
 *       Created:  May 17 2017 03:40:39 pm
 *   Last update:  Jun 18 2017 03:02:06 pm
 *      Compiler:  cc
 *        Author:  Vinicius Prata Kloh
 *  Organization:  Comcidis/LNCC
 *
 * =====================================================================================
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "stack.h"
/* #include "queue.h" */

/*
  auxiliar functions
*/
double calculator(char op, double v1, double v2, double* res);
int check_isOperator(char caract);
int check_isValue(char caract);
int check_operator_priority(char operator);
void concat(char* postfix, char operator);
/*
  end auxiliar functions
*/


/* parser function */
int rpn_parser(char *infix, char *postfix){
  int count;
  char *next;
  char aux[16];
  char op, op_top = '#';
  char trash;
  Stackc *op_stack = NULL;
  int infix_len = strlen(infix);
  double strtod_aux;

  for(count = 0; count < infix_len; count++){
    /* check if is value */
    if(check_isValue(infix[count])){
      if(infix[count-1] == '-'){
        strtod_aux = strtod(&infix[count-1], &next);
        sprintf(aux, "%5.2f", strtod_aux);
        strcat(postfix, aux);
        strcat(postfix, " ");
        count = next - infix;
      } else{
        strtod_aux = strtod(&infix[count], &next);
        sprintf(aux, "%5.2f", strtod_aux);
        strcat(postfix, aux);
        strcat(postfix, " ");
        count = next - infix;
      }
    }
    /* end check if is value */

    /* check if is operator */
    else if(check_isOperator(infix[count])){

      if(infix[count] == '-' && check_isValue(infix[count+1]))
        continue;
      if(get_stackc_top(op_stack, &op_top)){
          /* check operator priority */
          if(check_operator_priority(infix[count]) < check_operator_priority(op_top) && op_top != '('){
            while(check_operator_priority(infix[count]) < check_operator_priority(op_top)){
              if(!get_stackc_top(op_stack, &op_top) || op_top == '(')
                break;
              else{
                popc(&op_stack, &op);
                strncat(postfix, &op, 1);
                strcat(postfix, " ");
                get_stackc_top(op_stack, &op_top);
              }
            }
            pushc(&op_stack, infix[count]);
            get_stackc_top(op_stack, &op_top);
            if(get_stackc_top(op_stack, &op_top) && op_top == ')'){
              popc(&op_stack, &trash);
              if(get_stackc_top(op_stack, &op_top) && op_top == '(')
                popc(&op_stack, &trash);
              else
                pushc(&op_stack, trash);
            }
          }
          /* end check operator priority */

          else{
            pushc(&op_stack, infix[count]);
            get_stackc_top(op_stack, &op_top);
          }
      } else{
        pushc(&op_stack, infix[count]);
      }
    }
    /* end check is operator */
  }

  /* continue */
  while(!popc(&op_stack, &op)){
    if(op != '(' && op != ')'){
      strncat(postfix, &op, 1);
      strcat(postfix, " ");
    }
  }

  return 0;
}

/* solver function */
int rpn_solver(char *postfix, double *result){
  int count;
  char* next;
  Stackd* stackd = NULL;
  double value_1, value_2, res_aux, strtod_aux;
  int postfix_len = strlen(postfix);

  for(count = 0; count < postfix_len; count++){
    /* check is value */
    if(check_isValue(postfix[count])){
      if(postfix[count-1] == '-'){
        strtod_aux = strtod(&postfix[count-1], &next);
        pushd(&stackd, strtod_aux);
        count = next - postfix;
      } else{
        strtod_aux = strtod(&postfix[count], &next);
        pushd(&stackd, strtod_aux);
        count = next - postfix;
      }
    /* end check is value */

    /* check is operator */
    } else if(check_isOperator(postfix[count])){
        if(postfix[count] == '-' && check_isValue(postfix[count+1]))
          continue;
        else if(postfix[count] == 's'){
          popd(&stackd, &value_1);
          value_2 = 0;
        } else{
          popd(&stackd, &value_1);
          popd(&stackd, &value_2);
        }
        calculator(postfix[count], value_1, value_2, &res_aux);
        pushd(&stackd, res_aux);
    }
    /* end check is operator */
  }
  if(popd(&stackd, &res_aux))
    return 1;
  else
    *result = res_aux;
  return 0;
}

int check_isOperator(char caract){
  if(caract == 's' || caract == '(' || caract == ')' || caract == '+' || caract == '-' || caract == '*' || caract == '/')
    return 1;
  else
    return 0;
}

int check_isValue(char caract){
  int vet_values[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int count = 0;
  for(count = 0; count < 10; count++){
    if(caract == (vet_values[count] + 48))
      return 1;
  }
  return 0;
}

int check_operator_priority(char operator){
    switch(operator){
      case '(':   return 5;
      case ')':   return 1;
      case '+':   return 2;
      case '-':   return 2;
      case '*':   return 3;
      case '/':   return 3;
      case 's':   return 4;
      default:    return 0;
    }
}

void concat(char* postfix, char operator){
  sprintf(postfix, "%c", operator);
  strcat(postfix, " ");
}

double calculator(char op, double v1, double v2, double* res){
  switch(op){
    case '+':
      *res = (v1 + v2);
    break;
    case '-':
      *res = (v2 - v1);
    break;
    case '*':
      *res = (v1 * v2);
    break;
    case '/':
      *res = (v2 / v1);
    break;
    case 's':
      *res = sqrt(v1);
    break;
    default :   return 0;
  }
  return 1;
}
