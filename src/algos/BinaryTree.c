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
#include "BinaryTree.h"

BTree *createBTree(DataOps *ops) {
  BTree *tree = (BTree *)malloc(sizeof(BTree));
  tree->root = NULL;

  if (!ops) {
    tree->ops.cmp = defaultCmp;
    tree->ops.dataToInt = defaultDataToInt;
  } else {
    tree->ops = *ops;
  }

  return tree;
}

void addBTreeNode(BTree *tree, void *data) {
  BTreeNode **parent_ptr; /* Useful parent-to-node pointer */
  BTreeNode *parent;
  BTreeNode *node = (BTreeNode *)malloc(sizeof(BTreeNode));

  parent_ptr = &tree->root;
  parent = NULL;
  while (*parent_ptr) {
    parent = *parent_ptr;
    if (tree->ops.cmp(data, (*parent_ptr)->data) < 0)
      parent_ptr = &((*parent_ptr)->left);
    else
      parent_ptr = &((*parent_ptr)->right);
  }

  node->parent = parent;
  node->right = NULL;
  node->left = NULL;
  node->data = data;

  *parent_ptr = node;
}

void delBTreeNode(BTree *tree, BTreeNode *node) {
  BTreeNode **parent_ptr;
  BTreeNode *parent;
  BTreeNode *min;

  if (!node || !node->data)
    return;

  parent = node->parent;
  if (!parent) {
    parent_ptr = &(tree->root);
  } else {
    parent_ptr = tree->ops.cmp(node->data, parent->data) < 0
      ? &(parent->left)
      : &(parent->right);
  }

  if (node->right && node->left) { /* Removal candidate has two children */
    BTreeNode **minParentPtr;
    BTree *t = createBTree(NULL);

    t->root = node->right;
    min = findMin(t);

    minParentPtr = min->parent->left == min
      ? &min->parent->left
      : &min->parent->right;

    /* Remove pointer reference from min node's parent */
    *minParentPtr = NULL;

    min->parent = node->parent;

    /*
     * Take care to correctly set new nodes children
     * Subtle errors can be made here. For example in this
     * initial implementation we always set min->right equal
     * to node->right. This will break when node->right is the
     * only child of the right subtree, thus the minimum.
     */
    min->left = node->left;
    min->right = node->right == min ? NULL : node->right;

    *parent_ptr = min;
  } else if (node->right || node->left) {
    BTreeNode *child;
    child = (node->right) ? node->right : node->left;
    *parent_ptr = child;
    child->parent = node->parent;
  } else { /* node has no children, simply remove it */
    *parent_ptr = NULL;
  }

  free(node);
}

BTreeNode *findBTreeNode(BTree *tree, void *data) {
  BTreeNode *node;

  node = tree->root;
  while (node) {
    if (tree->ops.cmp(data, node->data) < 0)
      node = node->left;
    else if (tree->ops.cmp(data, node->data) > 0)
      node = node->right;
    else
      return node;
  }
  return NULL;
}

BTreeNode *findMin(BTree *tree) {
  BTreeNode *min = tree->root;
  while (min && min->left)
    min = min->left;

  return min;
}

BTreeNode *findMax(BTree *tree) {
  BTreeNode *max = tree->root;
  while (max && max->right)
    max = max->right;

  return max;
}

void traverseBTree(BTreeNode *root) {
  if (root) {
    traverseBTree(root->left);
    processNode(root);
    traverseBTree(root->right);
  }
}

void processNode(BTreeNode *node) {
  printf("%d ", *(int *)node->data);
}

void delBTree(BTree *tree) {
  /* Approach one - For dense trees this algo will have to
   * do O[logn] search to find the minimum every time (n always get smaller
   * however)
   */
  while (tree->root)
    delBTreeNode(tree, tree->root);

  free(tree);

  /* Another approach is to to an in order traversal and free visited nodes
   * O[N] complexity
   */
}

