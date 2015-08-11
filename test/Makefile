GTEST_DIR = ../src/thirdparty/gtest

TEST_DIR = .
ALGOS_DIR = ../src/algos
ALGOS_HEADERS = $(ALGOS_DIR)/*.h

# All Google Test headers.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

# Flags passed to the preprocessor.
# Set Google Test's header directory as a system directory, such that
# the compiler doesn't generate warnings in Google Test headers.
GT_CPPFLAGS += -isystem $(GTEST_DIR)/include

# Suppress annoying warnings during GTest static lib compilation (-w)
GT_CXXFLAGS += -w -pthread

# Flags passed to the C++ compiler for our tests
CXXFLAGS += -g -Wall -Wextra
CPPFLAGS += -isystem $(GTEST_DIR)/include -I $(ALGOS_DIR)

TEST_OBJ = test_list.o test_sort.o

# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized. This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.
gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(GT_CPPFLAGS) -I$(GTEST_DIR) $(GT_CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(GT_CPPFLAGS) -I$(GTEST_DIR) $(GT_CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

%.o: %.cc $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $<

# A test should link with either gtest.a or
# gtest_main.a, depending on whether it defines its own main()
# function.
test_algos : $(TEST_OBJ) $(ALGOS_DIR)/algos.a gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -lpthread -o $@

.PHONY: test
.PHONY: all
all test: test_algos
	./test_algos

.PHONY: clean
clean :
	rm -f $(TESTS) gtest.a gtest_main.a *.o test_algos

