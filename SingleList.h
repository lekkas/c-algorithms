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

#ifndef C_ALGOS_SINGLELIST_H_
#define C_ALGOS_SINGLELIST_H_

#include "Utils.h"

struct SingleListNode {
  void *data;
  struct SingleListNode *next;
};

struct SingleList {
  struct SingleListNode *head;
  struct DataOps ops;
};

typedef struct SingleListNode SingleListNode;
typedef struct SingleList SingleList;

SingleList *createSingleList(DataOps *ops);
void addSingleListNode(SingleList *list, void *data);
SingleListNode *searchSingleListNode(SingleList *list, void *data);
void printSingleList(SingleList *list);

void delSingleListNode(SingleList *list, SingleListNode *n);
void delSingleList(SingleList *list);

SingleListNode *findMiddle(SingleList *list);
int hasLoop(SingleList *list);
void reverseSingleList(SingleList *list);

#endif  // C_ALGOS_SINGLELIST_H_
