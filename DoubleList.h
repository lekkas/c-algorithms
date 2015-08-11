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

DoubleList *createDoubleList(DataOps *ops);
void delDoubleListNode(DoubleList *list, DoubleListNode *n);
void delDoubleList(DoubleList *list);
void addDoubleListNodeHead(DoubleList *list, void *data);
void addDoubleListNodeTail(DoubleList *list, void *data);
DoubleListNode *searchDoubleListNode(DoubleList *list, void *data);
void printDoubleList(DoubleList *list);

#endif  // C_ALGOS_DOUBLELIST_H_
