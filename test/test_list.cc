#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "SingleList.h"
#include "Utils.h"

#ifdef __cplusplus
}
#endif

#include "gtest/gtest.h"

static int list1[] = {1};
static int list2[] = {1, 2};
static int list3[] = {1, 2, 3};
static int list4[] = {1, 2, 3, 4};

int countNodes(SingleList *list) {
  SingleListNode *head = list->head;
  int count = 0;
  while (head) {
    count++;
    head = head->next;
  }
  return count;
}

SingleList *createSingleListFromIntArray(int *A, int size) {
  SingleList *list = createSingleList(NULL);

  int i = 0;
  while (i < size)
    addSingleListNode(list, &A[i++]);

  return list;
}

/* Reminder for all tests:
 * last inserted node is the new list head
 */

TEST(SingleList, AddOneDeleteOne) {
  SingleList *list = createSingleListFromIntArray(list1, 1);

  ASSERT_EQ(1, countNodes(list));

  delSingleListNode(list, list->head);
  ASSERT_EQ(0, countNodes(list));

  delSingleList(list);
}

TEST(SingleList, DeleteHead) {
  SingleList *list = createSingleListFromIntArray(list2, 2);

  delSingleListNode(list, list->head);

  ASSERT_EQ(0, list->ops.cmp(list->head->data, &list2[0]));
  ASSERT_EQ(1, countNodes(list));

  delSingleList(list);
}

TEST(SingleList, DeleteTail) {
  SingleList *list = createSingleListFromIntArray(list2, 2);

  delSingleListNode(list, list->head->next);

  ASSERT_EQ(0, list->ops.cmp(list->head->data, &list2[1]));
  ASSERT_EQ(1, countNodes(list));

  delSingleList(list);
}

TEST(SingleList, SearchAndDeleteTail) {
  SingleList *list = createSingleListFromIntArray(list2, 2);

  delSingleListNode(list, searchSingleListNode(list, &list2[0]));

  ASSERT_EQ(0, list->ops.cmp(list->head->data, &list2[1]));
  ASSERT_EQ(1, countNodes(list));

  delSingleList(list);
}

TEST(SingleList, FindMiddle3) {
  SingleList *list = createSingleListFromIntArray(list3, 3);


  ASSERT_EQ(0, list->ops.cmp(findMiddle(list)->data, &list3[1]));
  ASSERT_EQ(3, countNodes(list));

  delSingleList(list);
}

TEST(SingleList, FindMiddle4) {
  SingleList *list = createSingleListFromIntArray(list4, 4);


  ASSERT_EQ(0, list->ops.cmp(findMiddle(list)->data, &list3[2]));
  ASSERT_EQ(4, countNodes(list));

  delSingleList(list);
}

TEST(SingleList, DetectLoop4) {
  SingleList *list = createSingleListFromIntArray(list4, 4);

  SingleListNode *tail = searchSingleListNode(list, &list3[0]);
  tail->next = list->head;
  ASSERT_EQ(1, hasLoop(list));

  // restore
  tail->next = NULL;
  delSingleList(list);
}

TEST(SingleList, DetectLoop3) {
  SingleList *list = createSingleListFromIntArray(list3, 3);

  SingleListNode *tail = searchSingleListNode(list, &list3[0]);
  tail->next = list->head;
  ASSERT_EQ(1, hasLoop(list));

  // restore
  tail->next = NULL;
  delSingleList(list);
}

TEST(SingleList, ReverseList) {
  SingleList *list = createSingleListFromIntArray(list3, 3);

  int oldtail = *(int *)searchSingleListNode(list, &list3[0])->data;
  int oldhead = *(int *)searchSingleListNode(list, &list3[2])->data;

  int newtail = *(int *)searchSingleListNode(list, &list3[2])->data;
  int newhead = *(int *)searchSingleListNode(list, &list3[0])->data;

  reverseSingleList(list);

  ASSERT_EQ(oldtail, newhead);
  ASSERT_EQ(oldhead, newtail);

  delSingleList(list);
}
