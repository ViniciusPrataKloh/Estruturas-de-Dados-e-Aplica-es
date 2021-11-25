/*
  *@author Vinícius Prata Klôh
*/

#ifndef AVL_H
#define AVL_H 1

/*
  defines
*/
typedef struct tree Tree;
typedef struct node Node;
/*
  end defines
*/

/*
  functions
*/
int create_tree(Tree** tree);
int destroy_tree(Tree** tree);
int insert(Tree** tree, int value);
int delete(Tree** tree, int value);
int print_tree(Tree** tree, int i);
/*
  end functions
*/

#endif /* AVL_H 1 */
