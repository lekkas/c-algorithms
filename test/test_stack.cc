#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "Stack.h"

#ifdef __cplusplus
}
#endif

#include "gtest/gtest.h"

TEST(STACK, PUSH1POP1) {
  Stack *s = createStack();

  int a = 1;
  push(s, (void *)&a);
  ASSERT_EQ(1, *(int *)pop(s));
  ASSERT_EQ(1, isStackEmpty(s));
  delStack(s);
}

TEST(STACK, PUSH10POP10) {
  Stack *s = createStack();

  int A[10];
  for (int i = 0; i < 10; i++) {
    A[i] = i;
    push(s, (void *)&A[i]);
  }

  ASSERT_EQ(9, *(int *)peekHead(s));

  for (int i = 0; i < 10; i++)
    pop(s);

  ASSERT_EQ(1, isStackEmpty(s));
  delStack(s);
}
