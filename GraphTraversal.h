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

#ifndef C_ALGOS_GRAPHTRAVERSAL_H_
#define C_ALGOS_GRAPHTRAVERSAL_H_

#include <stdbool.h>
#include "Graph.h"
#include "Queue.h"

enum State {
  UNDISCOVERED,
  DISCOVERED,
  PROCESSED
};

/**
 * API
 */
void searchInit(Graph *G, enum State *vstate, int *parent);

/* BFS */
void ubfs_process_vertex_early(enum State *vstate, int v);
void ubfs_process_vertex_late(enum State *vstate, int v);
void ubfs_process_edge(int x, int y, int *parent);

/* DFS */
void udfs_process_vertex_early(enum State *vstate, int v);
void udfs_process_vertex_late(enum State *vstate, int v);
void udfs_process_edge(int x, int y, enum State *vstate, int *parent);

void BFS(Graph *G, int startV, enum State *vstate, int *parent);
void DFS(Graph *G, int startV, enum State *vstate, int *parent);

/**
 * Implementation
 */
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
void BFS(Graph *G, int startV, enum State *vstate, int *parent) {
  Queue *q;

  /* Initialization */
  q = createQueue();

  vstate[startV] = DISCOVERED;
  enqueue(q, (void *)&startV);

  while (!isQueueEmpty(q)) {
    int v = *(int *)dequeue(q);

    /* Set vertex state to DISCOVERED */
    ubfs_process_vertex_early(vstate, v);

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
        } else if (G->directed || vstate[*y] != PROCESSED) {
          ubfs_process_edge(v, *y, parent);
        }

        list = list->next;
    }

    /* Set vertex state to PROCESSED */
    ubfs_process_vertex_late(vstate, v);
  }
}

void DFS(Graph *G, int startV, enum State *vstate, int *parent) {
  /* Set vertex state to DISCOVERED */
  udfs_process_vertex_early(vstate, startV);

  Edge *list = G->edges[startV];
  while (list) {
    int *y = &list->y;

    /**
     * If y is undiscovered, then we know this is the first time
     * we see this edge..
     */
    if (vstate[*y] == UNDISCOVERED) {
      parent[*y] = startV;
      udfs_process_edge(startV, *y, vstate, parent);
      DFS(G, *y, vstate, parent);

      /** If y was processed then we would be sure that
       * we would have already seen this edge.
       */
    } else if (G->directed || vstate[*y] != PROCESSED) {
      udfs_process_edge(startV, *y, vstate, parent);
    }

    list = list->next;
  }

  /* Set vertex state to PROCESSED */
  udfs_process_vertex_late(vstate, startV);
}

/**
 * Processing functions for vertices & edges in undirected graphs
 */

/* BFS */
void ubfs_process_vertex_early(enum State *vstate, int v) {
  vstate[v] = DISCOVERED;
  printf("Discovered vertex %d\n", v);
}

void ubfs_process_vertex_late(enum State *vstate, int v) {
  vstate[v] = PROCESSED;
  printf("Processed vertex %d\n", v);
}

void ubfs_process_edge(int x, int y, int *parent) {
  if (x != parent[y])
    printf("Cross Edge: (%d,%d)\n", x, y);
  else
    printf("Tree Edge: (%d,%d)\n", x, y);
}

/* DFS */
void udfs_process_vertex_early(enum State *vstate, int v) {
  printf("Enter vertex :%d\n", v);
  vstate[v] = DISCOVERED;
}

void udfs_process_vertex_late(enum State *vstate, int v) {
  vstate[v] = PROCESSED;
  printf("Processed vertex %d\n", v);
}

void udfs_process_edge(int x, int y, enum State *vstate, int *parent) {
  if (vstate[y] == UNDISCOVERED) {
    printf("Tree Edge: (%d,%d)\n", x, y);
    return;
  }

  /* If y == parent[x], then we would have already seen this edge and thus
   * would be a tree edge.
   */
  if (y != parent[x]) {
    printf("Back Edge: (%d,%d)\n", x, y);
  }
}
#endif  // C_ALGOS_GRAPHTRAVERSAL_H_
