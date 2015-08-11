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

#ifndef C_ALGOS_BINARYTREE_H_
#define C_ALGOS_BINARYTREE_H_

#include "Utils.h"

struct BTreeNode {
  void *data;
  struct BTreeNode *left;
  struct BTreeNode *right;
  struct BTreeNode *parent;
};

struct BTree {
  struct BTreeNode *root;
  struct DataOps ops;
};

typedef struct BTree BTree;
typedef struct BTreeNode BTreeNode;

BTree *createBTree(DataOps *ops);
void addBTreeNode(BTree *tree, void *data);

BTreeNode *findMin(BTree *tree);
BTreeNode *findMax(BTree *tree);
BTreeNode *findBTreeNode(BTree *tree, void *data);
void traverseBTree(BTreeNode *root); /* In-order traversal */
void processNode(BTreeNode *node);

void delBTreeNode(BTree *tree, BTreeNode *node);
void delBTree(BTree *tree);

#endif  // C_ALGOS_BINARYTREE_H_
