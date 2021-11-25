/*
  *@author Vinícius Prata Klôh
*/

#ifndef STACK_H
#define STACK_H 1

/*
  defines
*/
typedef struct stackc Stackc;
typedef struct stackd Stackd;
/*
  end defines
*/

/*
  functions
*/
int pushc(Stackc** stackc, char val);
int popc(Stackc** stackc, char *val);
int pushd(Stackd** stackd, double val);
int popd(Stackd** stackd, double *val);
int print_stackc(Stackc *stackc);
int print_stackd(Stackd *stacki);
int free_stack(Stackc** stackc);
int get_stackc_top(Stackc* stackc, char *val);
int get_stackd_top(Stackd* stackd, double *val);
/*
  end functions
*/

#endif /* STACK_H 1 */
