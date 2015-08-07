.PHONY: test

all test :
	$(MAKE) -C test/ test

clean :
	rm -f test/test_all test/gtest.a test/gtest_main.a test/*.o
