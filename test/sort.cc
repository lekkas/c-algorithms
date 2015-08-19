#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "QuickSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "Utils.h"

#ifdef __cplusplus
}
#endif

#include "gtest/gtest.h"

int list1[] = {1};
int list2[] = {1, 2};
int ulist2[] = {2, 1};
int list3[] = {1, 2, 3};
int ulist3[] = {3, 1, 2};

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

// QuickSort

TEST(QUICKSORT, SORT1) {
  int *list = copyList(list1, 1);
  quickSort(list, 0, 0);
  ASSERT_EQ(1, isSorted(list, 1));
  free(list);
}

TEST(QUICKSORT, SORT2) {
  int *list = copyList(ulist2, 2);
  quickSort(list, 0, 1);
  ASSERT_EQ(1, isSorted(list, 2));
  free(list);
}

TEST(QUICKSORT, SORT3) {
  int *list = copyList(ulist3, 3);
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

TEST(QUICKSORT, SORT50K) {
  int size = 50000;
  int *list = createIntArray(size);
  quickSort(list, 0, size - 1);
  ASSERT_EQ(1, isSorted(list, size));
  free(list);
}

TEST(QUICKSORT, SORT2_SORTED) {
  int *list = copyList(list2, 2);
  quickSort(list, 0, 1);
  ASSERT_EQ(1, isSorted(list, 2));
  free(list);
}

TEST(QUICKSORT, SORT3_SORTED) {
  int *list = copyList(list3, 3);
  quickSort(list, 0, 2);
  ASSERT_EQ(1, isSorted(list, 3));
  free(list);
}

TEST(QUICKSORT, SORT10K_SORTED) {
  int size = 10000;
  int *list = createIntArray(size);
  quickSort(list, 0, size - 1);

  quickSort(list, 0, size - 1);
  ASSERT_EQ(1, isSorted(list, size));
  free(list);
}

// MergeSort

TEST(MERGESORT, SORT1) {
  int *list = copyList(list1, 1);
  mergeSortA(list, 0, 0);
  ASSERT_EQ(1, isSorted(list, 1));
  free(list);
}

TEST(MERGESORT, SORT2) {
  int *list = copyList(ulist2, 2);
  mergeSortA(list, 0, 1);
  ASSERT_EQ(1, isSorted(list, 2));
  free(list);
}

TEST(MERGESORT, SORT3) {
  int *list = copyList(ulist3, 3);
  mergeSortA(list, 0, 2);
  ASSERT_EQ(1, isSorted(list, 3));
  free(list);
}

TEST(MERGESORT, SORT10K) {
  int size = 10000;
  int *list = createIntArray(size);
  mergeSortA(list, 0, size - 1);
  ASSERT_EQ(1, isSorted(list, size));
  free(list);
}

TEST(MERGESORT, SORT50K) {
  int size = 50000;
  int *list = createIntArray(size);
  mergeSortA(list, 0, size - 1);
  ASSERT_EQ(1, isSorted(list, size));
  free(list);
}

TEST(MERGESORT, SORT2_SORTED) {
  int *list = copyList(list2, 2);
  mergeSortA(list, 0, 1);
  ASSERT_EQ(1, isSorted(list, 2));
  free(list);
}

TEST(MERGESORT, SORT3_SORTED) {
  int *list = copyList(list3, 3);
  mergeSortA(list, 0, 2);
  ASSERT_EQ(1, isSorted(list, 3));
  free(list);
}

TEST(MERGESORT, SORT10K_SORTED) {
  int size = 10000;
  int *list = createIntArray(size);
  quickSort(list, 0, size - 1);

  mergeSortA(list, 0, size - 1);
  ASSERT_EQ(1, isSorted(list, size));
  free(list);
}

// HeapSort

TEST(HEAPSORT, SORT1) {
  int *list = copyList(list1, 1);
  heapSort(list, 1);
  ASSERT_EQ(1, isSorted(list, 1));
  free(list);
}

TEST(HEAPSORT, SORT2) {
  int *list = copyList(ulist2, 2);
  heapSort(list, 2);
  ASSERT_EQ(1, isSorted(list, 2));
  free(list);
}

TEST(HEAPSORT, SORT3) {
  int *list = copyList(ulist3, 3);
  heapSort(list, 3);
  ASSERT_EQ(1, isSorted(list, 3));
  free(list);
}

TEST(HEAPSORT, SORT10K) {
  int size = 10000;
  int *list = createIntArray(size);
  heapSort(list, size);
  ASSERT_EQ(1, isSorted(list, size));
  free(list);
}

TEST(HEAPSORT, SORT50K) {
  int size = 50000;
  int *list = createIntArray(size);
  heapSort(list, size);
  ASSERT_EQ(1, isSorted(list, size));
  free(list);
}

TEST(HEAPSORT, SORT2_SORTED) {
  int *list = copyList(list2, 2);
  heapSort(list, 2);
  ASSERT_EQ(1, isSorted(list, 2));
  free(list);
}

TEST(HEAPSORT, SORT3_SORTED) {
  int *list = copyList(list3, 3);
  heapSort(list, 3);
  ASSERT_EQ(1, isSorted(list, 3));
  free(list);
}

TEST(HEAPSORT, SORT10K_SORTED) {
  int size = 10000;
  int *list = createIntArray(size);
  quickSort(list, 0, size - 1);

  heapSort(list, size);
  ASSERT_EQ(1, isSorted(list, size));
  free(list);
}

// InsertionSort

TEST(INSERTIONSORT, SORT1) {
  int *list = copyList(list1, 1);
  insertionSort(list, 1);
  ASSERT_EQ(1, isSorted(list, 1));
  free(list);
}

TEST(INSERTIONSORT, SORT2) {
  int *list = copyList(ulist2, 2);
  insertionSort(list, 2);
  ASSERT_EQ(1, isSorted(list, 2));
  free(list);
}

TEST(INSERTIONSORT, SORT3) {
  int *list = copyList(ulist3, 3);
  insertionSort(list, 3);
  ASSERT_EQ(1, isSorted(list, 3));
  free(list);
}

TEST(INSERTIONSORT, SORT10K) {
  int size = 10000;
  int *list = createIntArray(size);
  insertionSort(list, size);
  ASSERT_EQ(1, isSorted(list, size));
  free(list);
}
/*
TEST(INSERTIONSORT, SORT50K) {
  int size = 50000;
  int *list = createIntArray(size);
  insertionSort(list, size);
  ASSERT_EQ(1, isSorted(list, size));
  free(list);
}
*/
TEST(INSERTIONSORT, SORT2_SORTED) {
  int *list = copyList(list2, 2);
  insertionSort(list, 2);
  ASSERT_EQ(1, isSorted(list, 2));
  free(list);
}

TEST(INSERTIONSORT, SORT3_SORTED) {
  int *list = copyList(list3, 3);
  insertionSort(list, 3);
  ASSERT_EQ(1, isSorted(list, 3));
  free(list);
}

TEST(INSERTIONSORT, SORT10K_SORTED) {
  int size = 10000;
  int *list = createIntArray(size);
  quickSort(list, 0, size - 1);

  insertionSort(list, size);
  ASSERT_EQ(1, isSorted(list, size));
  free(list);
}

// SelectionSort

TEST(SELECTIONSORT, SORT1) {
  int *list = copyList(list1, 1);
  selectionSort(list, 1);
  ASSERT_EQ(1, isSorted(list, 1));
  free(list);
}

TEST(SELECTIONSORT, SORT2) {
  int *list = copyList(ulist2, 2);
  selectionSort(list, 2);
  ASSERT_EQ(1, isSorted(list, 2));
  free(list);
}

TEST(SELECTIONSORT, SORT3) {
  int *list = copyList(ulist3, 3);
  selectionSort(list, 3);
  ASSERT_EQ(1, isSorted(list, 3));
  free(list);
}

TEST(SELECTIONSORT, SORT10K) {
  int size = 10000;
  int *list = createIntArray(size);
  selectionSort(list, size);
  ASSERT_EQ(1, isSorted(list, size));
  free(list);
}
/*
TEST(SELECTIONSORT, SORT50K) {
  int size = 50000;
  int *list = createIntArray(size);
  selectionSort(list, size);
  ASSERT_EQ(1, isSorted(list, size));
  free(list);
}
*/
TEST(SELECTIONSORT, SORT2_SORTED) {
  int *list = copyList(list2, 2);
  selectionSort(list, 2);
  ASSERT_EQ(1, isSorted(list, 2));
  free(list);
}

TEST(SELECTIONSORT, SORT3_SORTED) {
  int *list = copyList(list3, 3);
  selectionSort(list, 3);
  ASSERT_EQ(1, isSorted(list, 3));
  free(list);
}

TEST(SELECTIONSORT, SORT10K_SORTED) {
  int size = 10000;
  int *list = createIntArray(size);
  quickSort(list, 0, size - 1);

  selectionSort(list, size);
  ASSERT_EQ(1, isSorted(list, size));
  free(list);
}
