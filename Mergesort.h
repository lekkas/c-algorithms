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

#ifndef C_ALGOS_MERGESORT_H_
#define C_ALGOS_MERGESORT_H_

#include "Utils.h"
#include "Sorting.h"
#include "Queue.h"

/**
 * MergeSort
 * mergesortA() and mergeA() functions sort Arrays, while
 * mergesortL() and mergeL() functions sort Linked lists.
 */
void mergeSortA(int *A, int lo, int hi);
void mergeA(int *A, int lo, int mi, int hi);
void mergeSortL(void *L, void *lo, void *hi);
void mergeL(void *L, void *lo, void *mi, void *hi);

void mergeSortA(int *A, int lo, int hi) {
  int middle;

  if (lo < hi) {
    middle = (int)((lo + hi) / 2);
    mergeSortA(A, lo, middle);
    mergeSortA(A, middle + 1, hi);
    mergeA(A, lo, middle, hi);
  }
}

void mergeA(int *A, int lo, int mi, int hi) {
  int i;
  int *tmp;

  Queue *q1 = createQueue();
  Queue *q2 = createQueue();

  for (i = lo; i <= mi; i++) {
    tmp = (int *)malloc(sizeof(int));
    *tmp = A[i];
    enqueue(q1, tmp);
  }

  for (i = mi + 1; i <= hi; i++) {
    tmp = (int *)malloc(sizeof(int));
    *tmp = A[i];
    enqueue(q2, tmp);
  }

  i = lo;
  while (!isQueueEmpty(q1) && !isQueueEmpty(q2)) {
    int el1 = *(int *)peekTail(q1);
    int el2 = *(int *)peekTail(q2);

    if (el1 <= el2) {
      A[i++] = *(int *)dequeue(q1);
    } else {
      A[i++] = *(int *)dequeue(q2);
    }
  }

  while (!isQueueEmpty(q1)) A[i++] = *(int *)dequeue(q1);
  while (!isQueueEmpty(q2)) A[i++] = *(int *)dequeue(q2);

  delQueue(q1);
  delQueue(q2);
}

#endif  // C_ALGOS_MERGESORT_H_
