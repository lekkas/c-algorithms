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

#include "BinarySearch.h"

static int _binarySearch(int *A, int lo, int hi, int val) {
  int mi = (lo + hi) / 2;   // better: (hi - lo)/2 + lo;

  if (lo > hi)
    return -1;

  if (A[mi] == val)
    return mi;
  else if (A[mi] < val)
    return _binarySearch(A, mi + 1, hi, val);
  else
    return _binarySearch(A, lo, mi - 1, val);
}

int binarySearch(int *A, int size, int val) {
  return _binarySearch(A, 0, size - 1, val);
}

static int _bsearchOccurRight(int *A, int lo, int hi, int val) {
  int mi = (lo + hi) / 2;   //  better: (hi - lo)/2 + lo;

  if (lo > hi)
    return lo;

  if (A[mi] > val) {
    return _bsearchOccurRight(A, lo, mi - 1, val);
  } else {
    return _bsearchOccurRight(A, mi + 1, hi, val);
  }
}

static int _bsearchOccurLeft(int *A, int lo, int hi, int val) {
  int mi = (lo + hi) / 2;   // better: (hi - lo)/2 + lo;

  if (lo > hi)
    return lo;

  if (A[mi] < val) {
    return _bsearchOccurLeft(A, mi + 1, hi, val);
  } else {
    return _bsearchOccurLeft(A, lo, mi - 1, val);
  }
}

int countOccurencies(int *A, int size, int val) {
  int count;
  int rightIdx = _bsearchOccurRight(A, 0, size - 1, val);
  int leftIdx = _bsearchOccurLeft(A, 0, size - 1, val);

  count = rightIdx - leftIdx;

  return count;
}
