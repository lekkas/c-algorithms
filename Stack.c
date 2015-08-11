/*
 * Copyright (c) 2015 Kostas Lekkas
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdlib.h>
#include <string.h>
#include "Stack.h"

struct Stack *createStack(void) {
  struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
  s->list = createSingleList(NULL);
  return s;
}

void push(struct Stack *s, void *data) {
  addSingleListNode(s->list, data);
}

/**
 * Pop element.
 *
 * Params:
 *
 * q : The Stack structure
 *
 */
void *pop(struct Stack *s) {
  struct SingleListNode *item;
  void *item_data;

  item = s->list->head;
  item_data = (s->list->head) ? s->list->head->data : NULL;

  if (item)
    delSingleListNode(s->list, item);

  return item_data;
}

/**
 * peek tail data element
 *
 * Params:
 *
 * q: the Stack structure
 * returns pointer to data element or NULL if queue is empty.
 */
void *peekHead(struct Stack *s) {
  return s->list->head ? s->list->head->data: NULL;
}

int isStackEmpty(struct Stack *s) {
  return s->list->head ? 0 : 1;
}

void delStack(struct Stack *s) {
  delSingleList(s->list);
  free(s);
}

