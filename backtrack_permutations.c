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
#include <stdbool.h>

struct Solution {
  int *A;
  bool *H;
  int n;
};

typedef struct Solution Solution;

bool isSolution(Solution *sol, int k) {
  return (sol->n == k);
}

void printSolution(Solution *sol) {
  for (int i = 1; i <= sol->n; ++i) {
    printf("%d ", sol->A[i]);
  }
  printf("\n");
}

void initSolution(Solution *sol) {
  for (int i = 0; i <= sol->n; ++i) {
    sol->A[i] = -1;
    sol->H[i] = false;
  }
}

void makeMove(Solution *sol, int k, int cand) {
  sol->A[k] = cand;
  sol->H[cand] = true;
}

void undoMove(Solution *sol, int k, int cand) {
  sol->A[k] = -1;
  sol->H[cand] = false;
}

void backtrack(Solution *sol, int k) {
  if (isSolution(sol, k)) {
    printSolution(sol);
  } else {
    k = k + 1;

    /* Scan through candidates */
    for (int i = 1; i <= sol->n; i++) {
      if (!sol->H[i]) {
        makeMove(sol, k, i);
        backtrack(sol, k);
        undoMove(sol, k, i);
      }
    }
  }
}

int main(int argc, char *argv[]) {
  Solution sol;

  if (argc != 2) {
    printf("Usage: %s [n] - Will print permutations of numbers 1 - n\n",
        argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);
  int A[n + 1];   // Need to store A[1] ... A[k]
  bool H[n + 1];
  sol.A = A;
  sol.H = H;
  sol.n = n;

  backtrack(&sol, 0);
}

