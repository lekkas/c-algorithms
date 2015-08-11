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
#include <stdio.h>
#include "SingleList.h"

SingleList *createSingleList(DataOps *ops) {
  SingleList *list = (SingleList *)malloc(sizeof(SingleList));
  list->head = NULL;

  if (ops == NULL) {
    list->ops.cmp = defaultCmp;
    list->ops.dataToInt = defaultDataToInt;
  } else {
    list->ops = *ops;
  }

  return list;
}

void delSingleListNode(SingleList *list, SingleListNode *node) {
  struct SingleListNode **prev, *cur;

  if (!node)
    return;

  prev = &list->head;
  cur = list->head;

  while (cur) {
    if (node == cur) {
      *prev = cur->next;
      free(cur);
      return;
    }
    prev = &(cur->next);
    cur = cur->next;
  }
}

void delSingleList(SingleList *list) {
  struct SingleListNode *node;

  node = list->head;
  while (node) {
    delSingleListNode(list, node);
    node = node->next;
  }
  free(list);
}

/**
 * Adds new nodes to the head of the list
 */
void addSingleListNode(SingleList *list, void *data) {
  SingleListNode *n =
    (SingleListNode *)malloc(sizeof(SingleListNode));

  n->data = data;
  n->next = list->head;
  list->head = n;
}

SingleListNode *searchSingleListNode(SingleList *list, void *data) {
  SingleListNode *head = list->head;
  while (head) {
    if (!list->ops.cmp(head->data, data))
      return head;

    head = head->next;
  }
  return NULL;
}

/**
 * Run through list and print its elements
 */
void printSingleList(SingleList *list) {
  if (!list)
    return;

  SingleListNode *node = list->head;
  while (node) {
    printf("%d ", list->ops.dataToInt(node->data));
    node = node->next;
  }
}

/**
 * Find middle node
 */
SingleListNode *findMiddle(SingleList *list) {
  SingleListNode *fast, *slow;

  fast = list->head;
  slow = list->head;

  /* When fast reaches NULL, slow will be the middle node */
  while (fast && fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

/**
 * Return 1 if list has a loop
 */
int hasLoop(SingleList *list) {
  struct SingleListNode *fast, *slow;

  fast = list->head;
  slow = list->head;

  while (fast) {
    if (fast->next == slow || (fast->next && (fast->next->next == slow)))
      return 1;

    fast = (fast->next && fast->next->next) ? fast->next->next : NULL;
    slow = slow->next;
  }
  return 0;
}


void reverseSingleList(SingleList *list) {
  SingleListNode *p, *prev, *tmp;

  if (list->head == NULL)
    return;

  prev = NULL;
  for (p=list->head; p != NULL; ) {
    tmp = p->next;
    p->next = prev;
    prev = p;
    p = tmp;
  }
  list->head = prev;
}
