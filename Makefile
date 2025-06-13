all:
	gcc start.c node.c bst_tree.c -o start

test:
	gcc test_bst.c node.c bst_tree.c -o bst_test

clean:
	rm -f start bst_test