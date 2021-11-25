/*
  *@author Vinícius Prata Klôh
*/

#include <stdio.h>
#include <stdlib.h>
#include "pp_utils.h"
#include "colors.h"

FILE *pFile = NULL;

/* Open the input file */
int openFile(const char *island){
  pFile = fopen(island, "r");
  if(pFile == NULL)
    return 1;
  return 0;
}

/* Close the input file */
int closeFile(){
  if(pFile == NULL)
    return 1;
  fclose(pFile);
  return 0;
}

/* Size of the island */
int load_size(int **height, int **width, const char *island){
  if(openFile(island) == 1)
    return 1;
  int aux1 = 0, aux2 = 0;
  fscanf(pFile, "%d", &aux1);
  *height = &aux1;
  fscanf(pFile, "%d", &aux2);
  *width = &aux2;
  return 0;
}

/* Geometry of the island and mesh of nodes used for the calculation */
int load_values(int **pMatrix){
  int column = 0, aux = 0;
  while(!feof(pFile)){
    fscanf(pFile, "%d", &aux);
    pMatrix[0][column] = aux;
    column++;
  }
  closeFile(pFile);
  return 0;
}

/* Define the color spectrum for differs values of the concentration */
void color_spectrum(const double element, const char type){
  if(element == 0.0 && type == 'w')                   /* Water */
    //set_foreground(BLUE);
    set_background(BLUE);
  if(element == 0.0 && type == 't')                   /* Without concentration */
    //set_foreground(GREEN);
    set_background(GREEN);
  if(element > 0.0 && element <= 33.0)                /* Below 33% of the concentration */
    //set_foreground(MAGENTA);
    set_background(MAGENTA);
  if(element > 33.0 && element <= 75.0)               /* Between 33% and 75% */
    //set_foreground(ORANGE);
    set_background(ORANGE);
  if(element > 75.0)                                  /* In addition to 75% */
    //set_foreground(RED);
    set_background(RED);
}

/* Print the propagtion of the poluent at each iteration */
void print_poluent_propagation(const Island *pMatrix_2nd, const int nrows, const int ncols){
  system("clear");
  int i = 0, j = 0;
  for(i=0; i<nrows; i++){
    for(j=0; j<ncols; j++){
      color_spectrum(pMatrix_2nd[(i*ncols)+j].value, pMatrix_2nd[(i*ncols)+j].type);
      printf(" %010.6lf ", pMatrix_2nd[(i*ncols)+j].value);
    }
    printf("\n");
  }
  set_foreground(DEFAULT);
  set_background(DEFAULT);
}

/* Print the results of the simulation */
void print_stats(const int iter, const int max_iter, const double largest_variation, const double tol, const double total_pol){
  set_foreground(DEFAULT);
  set_background(DEFAULT);
  printf("\nNumber of iterations:\t%d\t\t/\t%d\nLargest variation:\t%.10lf\t/\t%.10f\nTotal of pollutant:\t%.1lf\n", iter, max_iter, largest_variation, tol, total_pol);
}
