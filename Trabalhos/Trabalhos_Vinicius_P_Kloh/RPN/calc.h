/*
  *@author Vinícius Prata Klôh
*/

#ifndef CALC_H
#define CALC_H 1

/*
  functions
*/
int rpn_parser(char *infix, char *postfix);
int rpn_solver(char *postfix, double *result);
/*
  end functions
*/

#endif /* CALC_H 1 */
