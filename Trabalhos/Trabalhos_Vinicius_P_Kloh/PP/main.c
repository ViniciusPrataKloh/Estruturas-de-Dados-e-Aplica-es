#include <stdio.h>
#include <stdlib.h>
#include "pp_utils.h"

int main(int argc, char *argv[]){

  /* Check input parameters */
  if (argc != 4){
    printf("\n Input parameters necessary:\n \'i)\'input file,\n \'ii)\' tolerance and\n \'iii)\' max number of iterations...\n Example: ./poluent_progagation island/island.txt 0.0001 100\n\n");
    return 1;
  }

  /* Initializing the pointers to the arrays */
  int *pMatrix = NULL;
  Island *pMatrix_2nd = NULL;

  /* Create the primary matrix */
  if(create_matrix(&pMatrix, argv[1]) == 1){
    printf("\nError: file note found...\n\n");
    return 0;
  }

  /* Create the secondary matrix */
  if(create_matrix_2nd(&pMatrix, &pMatrix_2nd) == 1)
    printf("\nError: 2nd Matrix did not create...\n\n");

  /* Call the solver function to calculate the pollutant propagation*/
  if(solver(pMatrix, &pMatrix_2nd, atof(argv[2]), atoi(argv[3])) == 1){
    printf("\nHave not converged...\n\n");
  } else
    printf("\nConverged...\n\n");

  return 0;
}
