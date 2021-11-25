#ifndef STACK_H
#define STACK_H 1

typedef struct node Node;
typedef struct stack Stack;
Stack* create_stack(void);
Node* create_new_node(Node* n, int val);
//Node* withdraw_node(Node* n);
//int without_node(Stack* s);
void push(Stack** s, int val);
//int pop(Stack** s);
//void free_stack(Stack* s);
//void print_stack(Stack* s);

#endif /* STACK_H 1 */
