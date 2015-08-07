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

#include <stdio.h>
#include <stdlib.h>

// Find position of min element > 1.
int findMinPos(int *el, int len) {
  int i;
  int min = el[0];

  for (i = len - 1; i >= 0; i--) {
    if (el[i] != 1 && el[i] != 0)
      return i;
  }

  return 0;
}

int findLeftmostOnePos(int *el, int len) {
  int i;

  for (i = len - 1; i >= 0; i--) {
    if (el[i] != 1)
      return i + 1;
  }
  return -1;
}

void packOnes(int *el, int *len, int min) {
  int i, j, k;
  int sum = 0;

  if (min < 2)
    return;

  for (i = *len - 1; i >= 0; i--) {
    if (el[i] != 1)
      break;

    if (el[i] == 1) {
      sum++;
    }

    if (sum == min) {
      j = findLeftmostOnePos(el, *len);
      el[j] = min;
      for (k = i + (min - 1); k > i; k--) {
        el[k] = 0;
      }

      i++;
      *len = *len - (min - 1);
      sum = 0;
    }
  }

  if (sum > 1 && sum < min) {
    j = findLeftmostOnePos(el, *len);
    el[j] = sum;
    for (k = *len - 1; k > *len-sum; k--) {
      el[k] = 0;
    }
    *len = *len - (sum - 1);
  }
}

void printPart(int *el, int len) {
  int i;

  for (i = 0; i < len; i++)
    printf("%d ", el[i]);

  printf("\n");
}

int getPartitionCount(int n) {
  const int kMaxSize = 1000;
  int elements[kMaxSize];
  int i;
  int partitionCount = 1;
  int curPartitionLen = 1;
  int curMin;

  for (i = 0; i < size; i++) {
    elements[i] = 0;
  }

  elements[0] = n;
  printPart(elements, curPartitionLen);

  while (elements[0] > 1) {
    int i = findMinPos(elements, curPartitionLen);
    elements[i] = elements[i] - 1;
    curMin = elements[i];
    elements[curPartitionLen] = 1;
    curPartitionLen++;
    if (curMin > 1)
      packOnes(elements, &curPartitionLen, curMin);

    partitionCount++;
    printPart(elements, curPartitionLen);
  }

  return partitionCount;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage %s [n]\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);
  int partitions = getPartitionCount(n);

  printf("Partitions for n = %d : %d\n", n, partitions);
  return 0;
}
