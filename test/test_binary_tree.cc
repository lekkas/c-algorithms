#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "Utils.h"
#include "BinaryTree.h"

#ifdef __cplusplus
}
#endif

#include "gtest/gtest.h"

#define SIZE 100

TEST(BINARYSEARCHTREE, FUNCTIONALITY) {

  int A[] = {9};
  int *B = createIntArray(SIZE);
  BTree *t = createBTree(NULL);


  addBTreeNode(t, &A[0]);
  ASSERT_EQ(9, *(int *)findMin(t)->data);
  ASSERT_EQ(9, *(int *)findMax(t)->data);
  ASSERT_EQ(9, *(int *)findBTreeNode(t, &A[0])->data);

  deleteIntArray(B);
  delBTree(t);
}
