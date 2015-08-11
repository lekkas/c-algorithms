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

Graph *createGraph(int nvertices, bool directed);
void deleteGraph(Graph *G);
bool insert_edge(Graph *G, int x, int y, int weight, bool directed);

#endif  // C_ALGOS_GRAPH_H_
