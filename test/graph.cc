#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "Utils.h"
#include "Graph.h"
#include "GraphTraversal.h"
#include "Queue.h"
#include <stdbool.h>

#ifdef __cplusplus
}
#endif

#include "gtest/gtest.h"

Queue *q = NULL;

void processVertexEarly(int v) {
  v--;
}

void processVertexLate(int v) {
  v--;
}

struct edge {
  int x;
  int y;
};

typedef struct edge edge;

edge *newEdge(int x, int y) {
  edge *e = (edge *)malloc(sizeof(edge));
  e->x = x;
  e->y = y;

  return e;
}

void processEdge(int x, int y) {
  edge *e = newEdge(x,y);
  enqueue(q, e);
}

int graph[10][2] = {
  {1, 2},
  {2, 3},
  {1, 3},
  {4, 5},
  {8, 7},
  {6, 2},
  {2, 10},
  {9, 6},
  {8, 5},
  {9, 5}
};

TEST(GRAPHTRAVERSAL, DFS_SMOKETEST) {
  GraphOps ops;
  Graph *G;
  enum State *vstate;
  int *parent;
  int nvertices = 10;
  int nedges = 10;

  G = createGraph(nvertices, false);
  q = createQueue();

  parent = (int *)malloc(sizeof(int) * (G->nvertices + 1));
  vstate = (enum State *)malloc(sizeof(enum State) * (G->nvertices + 1));

  ops.processVertexEarly = processVertexEarly;
  ops.processVertexLate = processVertexLate;
  ops.processEdge = processEdge;

  for (int i = 0; i < nedges; i++)
    insert_edge(G, graph[i][0], graph[i][1], 0, false); // false for undirected

  searchInit(G, vstate, parent);
  DFS(G, 1, vstate, parent, &ops);

  for (int i = 1; i <= nvertices; i++)
    ASSERT_EQ(PROCESSED, vstate[i]);

  int cnt = 0;
  while (!isQueueEmpty(q)) {
    edge *e = (edge *)dequeue(q);
    cnt++;
    free(e);
  }

  ASSERT_EQ(nedges, cnt);

  free(parent);
  free(vstate);
  delQueue(q);
  deleteGraph(G);
}

TEST(GRAPHTRAVERSAL, BFS_SMOKETEST) {
  GraphOps ops;
  Graph *G;
  enum State *vstate;
  int *parent;
  int nvertices = 10;
  int nedges = 10;

  G = createGraph(nvertices, false);
  q = createQueue();

  parent = (int *)malloc(sizeof(int) * (G->nvertices + 1));
  vstate = (enum State *)malloc(sizeof(enum State) * (G->nvertices + 1));

  ops.processVertexEarly = processVertexEarly;
  ops.processVertexLate = processVertexLate;
  ops.processEdge = processEdge;

  for (int i = 0; i < nedges; i++)
    insert_edge(G, graph[i][0], graph[i][1], 0, false); // false for undirected

  searchInit(G, vstate, parent);
  BFS(G, 1, vstate, parent, &ops);

  for (int i = 1; i <= nvertices; i++)
    ASSERT_EQ(PROCESSED, vstate[i]);


  int cnt = 0;
  while (!isQueueEmpty(q)) {
    edge *e = (edge *)dequeue(q);
    cnt++;
    free(e);
  }

  ASSERT_EQ(nedges, cnt);

  free(parent);
  free(vstate);
  delQueue(q);
  deleteGraph(G);
}
