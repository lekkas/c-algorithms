CC = gcc
ALGOS_DIR = src/algos
TEST_DIR = test

.PHONY: test
.PHONY: all
all test: algos
	$(MAKE) -C $(TEST_DIR) test

.PHONY: algos
algos:
	$(MAKE) -C $(ALGOS_DIR)

.PHONY: clean
clean:
	rm -f test/test_all test/gtest.a test/gtest_main.a test/*.o
	$(MAKE) -C $(ALGOS_DIR) clean
	$(MAKE) -C $(TEST_DIR) clean
