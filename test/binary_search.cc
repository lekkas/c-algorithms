#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "BinarySearch.h"

#ifdef __cplusplus
}
#endif

#include "gtest/gtest.h"

TEST(BINARYSEARCH, COUNTOCCURENCIES1) {
  int A[] = {1,1,1,2,3,3,3};
  int len = sizeof(A) / sizeof(A[0]);
  ASSERT_EQ(1, countOccurencies(A, len, 2));
}

TEST(BINARYSEARCH, COUNTOCCURENCIES2) {
  int A[] = {1,1,1,2,2,3,3,3};
  int len = sizeof(A) / sizeof(A[0]);
  ASSERT_EQ(2, countOccurencies(A, len, 2));
}

TEST(BINARYSEARCH, COUNTOCCURENCIES_START1) {
  int A[] = {1,2,2,3,3,3};
  int len = sizeof(A) / sizeof(A[0]);
  ASSERT_EQ(1, countOccurencies(A, len, 1));
}

TEST(BINARYSEARCH, COUNTOCCURENCIES_START2) {
  int A[] = {1,1,2,2,3,3,3};
  int len = sizeof(A) / sizeof(A[0]);
  ASSERT_EQ(2, countOccurencies(A, len, 1));
}

TEST(BINARYSEARCH, COUNTOCCURENCIES_END1) {
  int A[] = {1,1,2,2,3};
  int len = sizeof(A) / sizeof(A[0]);
  ASSERT_EQ(1, countOccurencies(A, len, 3));
}

TEST(BINARYSEARCH, COUNTOCCURENCIES_END2) {
  int A[] = {1,1,2,2,3,3};
  int len = sizeof(A) / sizeof(A[0]);
  ASSERT_EQ(2, countOccurencies(A, len, 3));
}

TEST(BINARYSEARCH, SEARCHMIDDLE) {
  int A[] = {1,1,2,3,3};
  int len = sizeof(A) / sizeof(A[0]);
  ASSERT_GE(binarySearch(A, len, 2), 0);
}

TEST(BINARYSEARCH, SEARCHSTART) {
  int A[] = {1,2,2,3,3};
  int len = sizeof(A) / sizeof(A[0]);
  ASSERT_GE(binarySearch(A, len, 1), 0);
}

TEST(BINARYSEARCH, SEARCHEND) {
  int A[] = {1,1,2,2,3};
  int len = sizeof(A) / sizeof(A[0]);
  ASSERT_GE(binarySearch(A, len, 3), 0);
}
