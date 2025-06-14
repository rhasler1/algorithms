# compiler
CC := gcc

# directories
SRC := ./src
TEST := ./test
INCLUDE := ./include
BIN = ./bin
LIB = ./lib

# source files
COMMON_FILES := $(SRC)/tree_node.c $(SRC)/bst.c
TEST_FILES := $(TEST)/test_bst.c

# output files
TEST_OUT := $(BIN)/test_bst
LIB_OUT := $(LIB)/libbst.so

# compilation flags
CFLAGS := -I$(INCLUDE)
LDFLAGS := -fPIC -shared

# targets
.PHONY: all test build-lib clean

all: test build-lib

# test
test: | $(BIN)
	$(CC) $(CFLAGS) $(TEST_FILES) $(COMMON_FILES) -o $(TEST_OUT)

# library
build-lib: | $(LIB)
	$(CC) $(CFLAGS) $(LDFLAGS) $(COMMON_FILES) -o $(LIB_OUT)

# clean
clean:
	rm -f $(TEST_OUT) $(LIB_OUT)