/*
  *@author Vinícius Prata Klôh
*/

#ifndef QUEUE_H
#define QUEUE_H 1

/*
  defines
*/
typedef struct queue Queue;
typedef struct node Node;
/*
  end defines
*/

/*
  functions
*/
int create_queue(Queue** queue);
int insert(Queue** queue, char val);
int withdraw(Queue** queue, char *val);
int print_queue(Queue* queue);
int free_queue(Queue** queue);
/*
  end
*/

#endif /* QUEUE_H 1 */
