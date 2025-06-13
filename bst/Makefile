# vars
OS :=
CC := gcc
lib_flags :=

common_files := node.c bst_tree.c

test_files := test_bst.c
test_out := ../bin_test/test_bst

lib_out := ../lib/$(OS)/libbst.so

# set flags by OS
ifeq ($(OS),MAC)
	lib_flags := -shared -fPIC
endif

ifeq ($(OS),LINUX)
	lib_flags := -shared -fPIC
endif

# targets
.PHONY: all test lib clean

test:
	$(CC) $(test_files) $(common_files) -o $(test_out)

lib:
	$(CC) $(lib_flags) $(common_files) -o $(lib_out)

# clean
clean:
	rm -f $(test_out) $(lib_out)