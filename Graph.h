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

#ifndef C_ALGOS_GRAPH_H_
#define C_ALGOS_GRAPH_H_

#include <stdbool.h>
#include <stdlib.h>

struct Edgenode {
  int y; /* Destination Vertex */
  int weight;
  struct Edgenode *next; /* Reminder: this is an adjacency list */
};

struct Graph {
  //  Matrix to store vertex adjacency list for every
  //  vertex. For example, edges[1] has the adjacency
  //  list for vertex 1.
  struct Edgenode **edges;
  int *degree;
  int nvertices;  /* Number of vertices */
  int nedges;     /* Number of edges */
  bool directed;
};

typedef struct Graph Graph;
typedef struct Edgenode Edge;

/**
 * API
 */
Graph *createGraph(int nvertices, bool directed);
void deleteGraph(Graph *G);
bool insert_edge(Graph *G, int x, int y, int weight, bool directed);


Graph *createGraph(int nvertices, bool directed) {
  int i;
  Graph *G = (Graph *)malloc(sizeof(Graph));
  G->edges = (Edge **)malloc(sizeof(Edge *) * (nvertices + 1));
  G->degree = (int *)malloc(sizeof(int) * (nvertices + 1));

  G->nvertices = nvertices;
  G->directed = false;
  G->nedges = 0;

  /* Initialize adjacency lists */
  for (i = 0; i <= nvertices; i++) {
    G->edges[i] = NULL;
    G->degree[i] = 0;
  }
  return G;
}

void deleteGraph(Graph *G) {
  int i;

  free(G->degree);

  for (i = 0; i <= G->nvertices; i++) {
    Edge *head = G->edges[i];
    while (head != NULL) {
      Edge *tmp = head->next;
      free(head);
      head = tmp;
    }
  }
  free(G->edges);
  free(G);
}

/*
 * Returns true if edge was added in the graph
 */
bool insert_edge(Graph *G, int x, int y, int weight, bool directed) {
  bool xy = false;
  bool yx = false;

  Edge *edge = G->edges[x];
  while (edge) {
    if (edge->y == y) {   // Edge (x,y) is already in the graph
      xy = true;
      break;
    }
    edge = edge->next;
  }

  if (!xy) {
    xy = true;
    edge = (Edge *)malloc(sizeof(Edge));
    edge->y = y;
    edge->weight = weight;

    /* Add new edge at the head of the adjacency list */
    edge->next = G->edges[x];
    G->edges[x] = edge;
  }

  /* If graph is not directed we also want to add yx
   *
   * TODO: A smarter way to do this (and avoid repeating ourselves)
   * is to call insert_edge() again with directed == true
   *
   */
  if (!directed) {
    edge = G->edges[y];
    while (edge) {
      if (edge->y == x) {
        yx = true;
        break;
      }
      edge = edge->next;
    }

    if (!yx) {
      yx = true;
      edge = (Edge *)malloc(sizeof(Edge));
      edge->y = x;
      edge->weight = weight;
      edge->next = G->edges[y];
      G->edges[y] = edge;
    }
  }
  return xy;
}

#endif  // C_ALGOS_GRAPH_H_
