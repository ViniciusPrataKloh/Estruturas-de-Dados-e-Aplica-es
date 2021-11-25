/*
 * =====================================================================================
 *
 *	 Filename:  pp_utils.c
 *
 *   Description:  pollutant propagation implementation
 *
 *        Version:  3.3.7
 *        Created:  Apr 20 2017 03:42:37 pm
 *    Last update:  Jun 19 2017 08:16:15 pm
 *       Compiler:  cc
 *         Author:  Vinícius Prata Klôh
 *
 * =====================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pp_utils.h"
#include "io.h"

/*
  auxiliar function
*/
double check_neighbors(const int *pMatrix, const Island *pMatrix_2nd, double **pMatrix_temp, int i, int j);
/*
  end auxiliar function
*/

int nrows = 0, ncols = 0;

/* Create a primary matrix according to input island file */
int create_matrix(int **pMatrix, const char *island){
  int *a = NULL, *l = NULL;
  if(load_size(&a, &l, island) == 1)
    return 1;
  nrows = *a; ncols = *l;
  pMatrix[0] = (int *) malloc(sizeof(int)*(nrows*ncols));
  load_values(pMatrix);
  return 0;
}

/* Create a secondary matrix to compute the values of the concetrantion of poluent */
int create_matrix_2nd(int **pMatrix, Island **pMatrix_2nd){
  int column = 0;
  pMatrix_2nd[0] = (Island *) malloc(sizeof(Island)*(nrows*ncols));
  for(column=0; column<nrows*ncols; column++){
    if(pMatrix[0][column] == 0){
      pMatrix_2nd[0][column].value = 0.0;
      pMatrix_2nd[0][column].type = 'w';
    }
    if(pMatrix[0][column] == 1){
      pMatrix_2nd[0][column].value = 0.0;
      pMatrix_2nd[0][column].type = 't';
    }

    if(pMatrix[0][column] == 2){
      pMatrix_2nd[0][column].value = 100.0;
      pMatrix_2nd[0][column].type = 'p';
    }
  }
  return 0;
}

/* Compute the concentration and verify the convergence */
int solver(const int *pMatrix, Island **pMatrix_2nd, const double tol, const int max_iter){
  int i, j, element, iter = 0;
  double variation = 0.0f, largest_variation = 0.0f, total_pol = 0.0f;
  double *pMatrix_temp = (double *) malloc(sizeof(double)*(nrows*ncols));
  for(i=0; i<nrows*ncols; i++){
    pMatrix_temp[i] = 0.0f;
  }
  /* Compute the concentration for each node */
  do{
    largest_variation = 0.0f;
    for(i=0; i<nrows; i++){
      for(j=0; j<ncols; j++){
        element = (i * ncols) + j;
        if(pMatrix[element] == 1)
          check_neighbors(pMatrix, pMatrix_2nd[0], &pMatrix_temp, i, j);
      }
    }
    /* Compute the variation of the concentration values
          at all nodes between the previous iteration */
    for(i=0; i<nrows; i++){
      for(j=0; j<ncols; j++){
        element = (i * ncols) + j;
        variation = pMatrix_temp[element] - pMatrix_2nd[0][element].value;
        /* Verify the largest variation over all nodes */
        if(variation > largest_variation)
          largest_variation = variation;
      }
    }
    /* Update the concentration computed at each node*/
    for(i=0; i<nrows; i++){
      for(j=0; j<ncols; j++){
        element = (i * ncols) + j;
        if(pMatrix[element] == 1)
          pMatrix_2nd[0][element].value = pMatrix_temp[element];
          total_pol += pMatrix_2nd[0][element].value;
      }
    }
    print_poluent_propagation(pMatrix_2nd[0], nrows, ncols);
    print_stats(iter, max_iter, largest_variation, tol, total_pol);
    if(iter >= max_iter){
      return 1; /* Did not converge */
    }
    iter++;
   /* sleep(1); */
  } while(largest_variation >= tol);
  return 0; /* Did converge */
}

/* Check the neighbors nodes and compute the average */
double check_neighbors(const int *pMatrix, const Island *pMatrix_2nd, double **pMatrix_temp, int i, int j){
  double aux = 0;

  /* Left neighbor */
  if((j-1) >= 0){
    if(pMatrix[(i*ncols)+(j-1)] != 0){
      aux += pMatrix_2nd[(i*ncols)+(j-1)].value;
    } else if(pMatrix[(i*ncols)+(j-1)] == 0){
      aux += pMatrix_2nd[(i*ncols)+(j-1)].value;
    }
  } else if((j-1) < 0){
    aux += 0.0;
  }

   /* Right neighbor */
  if(j+1 < ncols){
    if(pMatrix[(i*ncols)+(j+1)] != 0){
      aux += pMatrix_2nd[(i*ncols)+(j+1)].value;
    } else if(pMatrix[(i*ncols)+(j+1)] == 0){
      aux += pMatrix_2nd[(i*ncols)+(j+1)].value;
    }
  } else if(j+1 == ncols){
    aux += 0.0;
  }

   /* Top neighbor */
  if((i-1) >= 0){
    if(pMatrix[((i-1)*ncols)+j] != 0){
      aux += pMatrix_2nd[((i-1)*ncols)+j].value;
    } else if(pMatrix[((i-1)*ncols)+j] == 0){
      aux += pMatrix_2nd[((i-1)*ncols)+j].value;
    }
  } else if((i-1) < 0){
    aux += 0.0;
  }

   /* Bottom neighbor*/
  if((i+1) < nrows){
    if(pMatrix[((i+1)*ncols)+j] != 0){
      aux += pMatrix_2nd[((i+1)*ncols)+j].value;
    } else if(pMatrix[((i+1)*ncols)+j] == 0){
      aux += pMatrix_2nd[((i+1)*ncols)+j].value;
    }
  } else if((i+1) == nrows){
    aux += 0.0;
  }

  /* Average values of the concentration at the four neighbors */
  pMatrix_temp[0][(i*ncols)+j] = (aux/4);
  return 0;
}
