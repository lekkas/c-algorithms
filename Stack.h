#ifndef C_ALGOS_STACK_H_
#define C_ALGOS_STACK_H_

#include "SingleList.h"

struct Stack {
  struct SingleList *list;
};


struct Stack *createStack(void);
void push(struct Stack *s, void *data);
void *pop(struct Stack *s);
void *peekHead(struct Stack *s);
int isStackEmpty(struct Stack *s);
void delStack(struct Stack *s);

#endif  // C_ALGOS_STACK_H_
