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

#ifndef C_ALGOS_DOUBLELIST_H_
#define C_ALGOS_DOUBLELIST_H_

#include "SingleList.h"

struct DoubleListNode {
  void *data;
  struct DoubleListNode *next;
  struct DoubleListNode *prev;
};

struct DoubleList {
  struct DoubleListNode *head;
  struct DoubleListNode *tail;
  struct DataOps ops;
};

typedef struct DoubleListNode DoubleListNode;
typedef struct DoubleList DoubleList;

/**
 * API
 */

DoubleList *createDoubleList(DataOps *ops);
void delDoubleListNode(DoubleList *list, DoubleListNode *n);
void delDoubleList(DoubleList *list);
void addDoubleListNodeHead(DoubleList *list, void *data);
void addDoubleListNodeTail(DoubleList *list, void *data);
DoubleListNode *searchDoubleListNode(DoubleList *list, void *data);
void printDoubleList(DoubleList *list);


/**
 * Implementation
 */

void printDoubleList(DoubleList *list) {
  DoubleListNode *n;
  for (n = list->head; n != NULL; n=n->next)
    printf("%d ", *(int *)n->data);
  printf("\n");
}

DoubleList *createDoubleList(DataOps *ops) {
  DoubleList *list = (DoubleList *)malloc(sizeof(DoubleList));
  list->head = NULL;
  list->tail = NULL;

  /* if ops == NULL, assume default behavior */
  if (ops == NULL) {
    list->ops.cmp = defaultCmp;
    list->ops.dataToInt = defaultDataToInt;
  } else {
    list->ops = *ops;
  }

  return list;
}

/**
 * Users are responsible to free the data element of the node.
 */
void delDoubleListNode(DoubleList *list, DoubleListNode *n) {
  if (n == NULL)
    return;

  if (n == list->head)
    list->head = n->next;

  if (n == list->tail)
    list->tail = n->prev;

  if (n->next != NULL)
    n->next->prev = n->prev;

  if (n->prev != NULL)
    n->prev->next = n->next;

  free(n);
}

void delDoubleList(DoubleList *list) {
  DoubleListNode *node = list->head;

  while (node) {
    delDoubleListNode(list, node);
    node = node->next;
  }

  free(list);
}

void addDoubleListNodeHead(DoubleList *list, void *data) {
  DoubleListNode *n = (DoubleListNode *)malloc(sizeof(DoubleListNode));

  n->data = data;
  n->next = NULL;
  n->prev = NULL;

  if (list->head) {
    n->next = list->head;
    list->head->prev = n;
  } else { /* no list head == no list tail */
    list->tail = n;
  }

  list->head = n;
}

void addDoubleListNodeTail(DoubleList *list, void *data) {
  DoubleListNode *n = (DoubleListNode *)malloc(sizeof(DoubleListNode));

  n->data = data;
  n->prev = NULL;
  n->next = NULL;

  if (list->tail) {
    n->prev = list->tail;
    list->tail->next = n;
  } else { /* no list tail == no list head */
    list->head = n;
  }

  list->tail = n;
}

DoubleListNode *searchDoubleListNode(DoubleList *list, void *data) {
  DoubleListNode *head = list->head;
  while (head) {
    if (!list->ops.cmp(head->data, data))
      return head;

    head = head->next;
  }
  return NULL;
}


#endif  // C_ALGOS_DOUBLELIST_H_
