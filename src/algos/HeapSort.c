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

#include "HeapSort.h"
#include "Utils.h"

int getParent(int p) {
  if (p == 0)
    return -1;

  return (int)((p-1)/2);
}

int getLeftChild(int p) {
  return 2*p + 1;
}

/* Max-heap - parents must be bigger than their children */
void bubble_down(int *A, int size, int p) {
  int lchild = getLeftChild(p);
  int rchild = lchild + 1;
  int maxChild;

  if (lchild >= size)
    return;

  if (rchild >= size)
    maxChild = lchild;
  else
    maxChild = (A[lchild] >= A[rchild]) ? lchild : rchild;

  if (A[p] < A[maxChild]) {
    swap(&A[p], &A[maxChild]);
    bubble_down(A, size, maxChild);
  }
}

void heapify(int *A, int size) {
  int pos = size - 1;
  while (pos >= 0) {
    bubble_down(A, size, pos);
    pos--;
  }
}

/* Heapsort for max-Heap */
void heapSort(int *A, int size) {
  int i;

  heapify(A, size);

  for (i = 0; i < size; i++) {
    swap(&A[0], &A[size - 1 - i]);  // A[0] contains max element;
    bubble_down(A, size - i - 1, 0);
  }
}

int isMaxHeap(int *A, int size) {
  int i;
  for (i=0; i < size; i++) {
    int lchild = getLeftChild(i);
    int rchild = lchild + 1;
    int maxChild;

    if (lchild >= size)
      continue;

    if (rchild >= size)
      maxChild = lchild;
    else
      maxChild = A[lchild] >= A[rchild] ? lchild : rchild;

    if (A[i] < A[maxChild])
      return 0;
    else
      continue;
  }
  return 1;
}

int isMinHeap(int *A, int size) {
  int i;
  for (i=0; i < size; i++) {
    int lchild = getLeftChild(i);
    int rchild = lchild + 1;
    int minChild;

    if (lchild >= size)
      continue;

    if (rchild >= size)
      minChild = lchild;
    else
      minChild = A[lchild] <= A[rchild] ? lchild : rchild;

    if (A[i] > A[minChild])
      return 0;
    else
      continue;
  }
  return 1;
}
