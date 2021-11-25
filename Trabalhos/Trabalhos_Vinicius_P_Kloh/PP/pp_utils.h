/*
  *@author Vinícius Prata Klôh
*/

#ifndef PP_UTILS_H
#define PP_UTILS_H 1

/*
  define island struct
*/
struct island{
  double value;
  char type;
};typedef struct island Island;
/*
  end define
*/

/*
  functions
*/
int create_matrix(int **pMatrix, const char *island);
int create_matrix_2nd(int **pMatrix, Island **pMatrix_2nd);
int solver(const int *pMatrix, Island **pMatrix_2nd, const double tol, const int max_iter);
/*
  end functions
*/


#endif /* PP_UTILS_H 1 */
