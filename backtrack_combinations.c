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
#include <stdbool.h>
#include <stdlib.h>

/**
 * All sets / Combinations
 *
 * Backtrack Algorithm
 *
 */
void getCandidates(bool *candidates, int *c) {
  candidates[0] = true;
  candidates[1] = false;
  *c = 2;
}

bool isSolution(int k, int n) {
  return k == n;
}

void printSolution(bool *a, int k) {
  int i;

  printf("{ ");
  for (i = 1; i <= k; i++) {
    if (a[i] == true)
      printf("%d ", i);
  }
  printf("}");
}

void backtrack(bool *a, int k, int n) {
  bool candidates[2];
  int c;
  int i;

  if (isSolution(k, n)) {
    printSolution(a, k);
    printf("\n");
  } else {
    k = k + 1;
    getCandidates(candidates, &c);
    for (i = 0; i < c; i++) {
      a[k] = candidates[i];
      backtrack(a, k, n);
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s [n]\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);
  int kSolSize = n + 1;
  bool a[kSolSize];
  int i;

  backtrack(a, 0, n);
  return 0;
}
