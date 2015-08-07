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

#ifndef C_ALGOS_UTILS_H_
#define C_ALGOS_UTILS_H_

#include <stdlib.h>
#include <stdio.h>

#define MAX_RAND 4098  // Maximum random generated number

struct DataOps {
  /* Returns -1, 1 ,0 if thiss<that, thiss>that, thiss==that respectively */
  int (*cmp)(void *thiss, void *that);
  int (*dataToInt)(void *data);
};

typedef struct DataOps DataOps;

/**
 * API
 */
void swap(int *a, int *b);
int *createIntArray(int size);
void printIntArray(int *A, int size);
void deleteIntArray(int *A);

int defaultCmp(void *thiss, void *that);
int defaultDataToInt(void *data);

/**
 * Implementation
 */
void swap(int *a, int *b) {
  if (a == b)
    return;

  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void printIntArray(int *A, int size) {
  int i;

  for (i = 0; i < size; i++)
    printf("%d ", A[i]);

  printf("\n");
}

int *createIntArray(int size) {
  int i;
  int *A = (int *)malloc(size * sizeof(int));

  for (i = 0; i < size; i++)
    A[i] = rand() % MAX_RAND;

  return A;
}

void deleteIntArray(int *A) {
  if (A)
    free(A);
}

/* Default function that compares data struct members */
int defaultCmp(void *thiss, void *that) {
  if (*(int *)thiss < *(int *)that) {
    return -1;
  } else if (*(int *)thiss > *(int *)that) {
    return 1;
  } else {
    return 0;
  }
}

int defaultDataToInt(void *data) {
  return *(int *)data;
}

#endif  // C_ALGOS_UTILS_H_
