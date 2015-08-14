#ifndef C_ALGOS_STACK_H_
#define C_ALGOS_STACK_H_

#include "SingleList.h"

struct Stack {
  struct SingleList *list;
};

typedef struct Stack Stack;

Stack *createStack(void);
void push(Stack *s, void *data);
void *pop(Stack *s);
void *peekHead(Stack *s);
int isStackEmpty(Stack *s);
void delStack(Stack *s);

#endif  // C_ALGOS_STACK_H_
