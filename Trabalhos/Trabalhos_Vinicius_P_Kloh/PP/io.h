/*
  *@author Vinícius Prata Klôh
*/

#ifndef IO_H
#define IO_H 1

/*
  functions
*/
int openFile(const char *island);
int closeFile();
int load_size(int **height, int **width, const char *island);
int load_values(int **pMatrix);
void print_poluent_propagation(const Island *pMatrix_2nd, const int nrows, const int ncols);
void print_stats(const int iter, const int max_iter, const double largest_variation, const double tol, const double total_pol);
void color_spectrum(const double element, const char type);
/*
  end functions
*/

#endif /* IO_H */
