#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "Quicksort.h"
#include "Mergesort.h"
#include "Heapsort.h"
#include "Selectionsort.h"
#include "Insertionsort.h"
#include "Utils.h"

#ifdef __cplusplus
}
#endif

#include "gtest/gtest.h"

int list1[] = {1};
int list2[] = {1,2};
int ulist2[] = {2,1};
int list3[] = {1,2,3};
int ulist3[] = {3,1,2};

int isSorted(int *A, int size) {
  int i;
  for (i = 0; i < size - 1; i++)
    if (A[i] > A[i + 1])
      return 0;

  return 1;
}

int *copyList(int *A, int size) {
  int *list = (int *)malloc(size * sizeof(int));
  for (int i = 0; i < size; i++)
    list[i] = A[i];

  return list;
}

void printList(int *A, int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", A[i]);

  printf("\n");
}


TEST(QUICKSORT, SORT1) {
  int *list = copyList(list1, 1);
  quickSort(list, 0, 0);
  ASSERT_EQ(1, isSorted(list, 1));
  free(list);
}

TEST(QUICKSORT, SORT2) {
  int *list = copyList(list2, 2);
  quickSort(list, 0, 1);
  ASSERT_EQ(1, isSorted(list, 2));
  free(list);
}

TEST(QUICKSORT, SORT3) {
  int *list = copyList(list3, 3);
  quickSort(list, 0, 2);
  ASSERT_EQ(1, isSorted(list, 3));
  free(list);
}

TEST(QUICKSORT, SORT10K) {
  int size = 10000;
  int *list = createIntArray(size);
  quickSort(list, 0, size - 1);
  ASSERT_EQ(1, isSorted(list, size));
  free(list);
}

TEST(QUICKSORT, SORT1M) {
  int size = 1000000;
  int *list = createIntArray(size);
  quickSort(list, 0, size - 1);
  ASSERT_EQ(1, isSorted(list, size));
  free(list);
}

// - other sorting algos
// - sorted array tsting
