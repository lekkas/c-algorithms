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
#include "Queue.h"
#include "GraphTraversal.h"

void searchInit(Graph *G, enum State *vstate, int *parent) {
  int i;
  for (i = 0; i <= G->nvertices; i++) {
    vstate[i] = UNDISCOVERED;
    parent[i] = -1;
  }
}

/**
 * G: The graph
 * startV: start vertex
 * state: vertex state (undiscovered, discovered, processed)
 * parent: the array to store parent-child relations, the tree
 *  edges, in escense.
 */
void BFS(Graph *G, int startV, enum State *vstate, int *parent, GraphOps *ops) {
  Queue *q;

  /* Initialization */
  q = createQueue();

  vstate[startV] = DISCOVERED;
  enqueue(q, (void *)&startV);

  while (!isQueueEmpty(q)) {
    int v = *(int *)dequeue(q);

    /* Set vertex state to DISCOVERED */
    vstate[v] = DISCOVERED;
    if (ops)
      ops->processVertexEarly(v);

    /* Visit all adjacent vertices of v */
    Edge *list = G->edges[v];
    while (list) {
        G->degree[v] += 1;
        int *y = &list->y;

        /* Found undiscovered vertex */
        if (vstate[*y] == UNDISCOVERED) {
          vstate[*y] = DISCOVERED;
          enqueue(q, (void *)y);
          parent[*y] = v;

        /**
         * Note: if the Graph is directed, that's the only time we
         * will have the chance to process this edge, since it will
         * not appear in the adjacency list of y.
         *
         * If the Graph is undirected and we want to process each
         * edge only once, we can process it EITHER when y is
         * unprocessed OR when y is processed.
         *
         * If we do not include such a conditional checking then
         * each edge will be processed twice.
         *
         */
        }

        if (G->directed || vstate[*y] != PROCESSED) {
            if (ops)
              ops->processEdge(v, *y);
        }

        list = list->next;
    }

    /* Set vertex state to PROCESSED */
    vstate[v] = PROCESSED;
    if (ops)
      ops->processVertexLate(v);
  }
}

void DFS(Graph *G, int startV, enum State *vstate, int *parent, GraphOps *ops) {
  /* Set vertex state to DISCOVERED */
  vstate[startV] = DISCOVERED;
  if (ops)
    ops->processVertexLate(startV);

  Edge *list = G->edges[startV];
  while (list) {
    int *y = &list->y;

    /**
     * If y is undiscovered, then we know this is the first time
     * we see this edge..
     */
    if (vstate[*y] == UNDISCOVERED) {
      parent[*y] = startV;
      if (ops)
        ops->processEdge(startV, *y);

      DFS(G, *y, vstate, parent, ops);
    } else if (G->directed || vstate[*y] == PROCESSED) {
        if (ops)
          ops->processEdge(startV, *y);
    }

    list = list->next;
  }

  /* Set vertex state to PROCESSED */
  vstate[startV] = PROCESSED;
  if (ops)
    ops->processVertexLate(startV);
}
