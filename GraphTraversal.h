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

#include "Graph.h"

enum State {
  UNDISCOVERED,
  DISCOVERED,
  PROCESSED
};

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

#endif  // C_ALGOS_GRAPHTRAVERSAL_H_
