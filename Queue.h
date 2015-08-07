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

#ifndef C_ALGOS_QUEUE_H_
#define C_ALGOS_QUEUE_H_

#include <stdlib.h>
#include <string.h>
#include "DoubleList.h"

struct Queue {
  struct DoubleList *list;
};

typedef struct Queue Queue;

Queue *createQueue(void) {
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->list = createDoubleList(NULL);
  return q;
}

void enqueue(Queue *q, void *data) {
  addDoubleListNodeHead(q->list, data);
}

/**
 * Dequeue element.
 *
 * Params:
 *
 * q : The Queue structure
 * Returns pointer to data element of node.*
 */
void *dequeue(Queue *q) {
  struct DoubleListNode *tail;
  void *data;

  tail = q->list->tail;
  data = tail ? tail->data : NULL;

  delDoubleListNode(q->list, tail);
  return data;
}

/**
 * peek tail data element
 *
 * Params:
 *
 * q: the Queue structure
 * returns pointer to data element or NULL if queue is empty.
 */
void *peekTail(Queue *q) {
  return q->list->tail ? q->list->tail->data: NULL;
}

int isQueueEmpty(Queue *q) {
  return q->list->tail ? 0 : 1;
}

void delQueue(Queue *q) {
  delDoubleList(q->list);
  free(q);
}

#endif  // C_ALGOS_QUEUE_H_
