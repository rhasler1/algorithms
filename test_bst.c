// BST testing module

#include <stdio.h>
#include <stdlib.h>
#include "node.h"


// BST operations
/*
bst_insertion_test();
bst_min_test();
bst_min_ptr_test();
bst_search_test();
bst_deletion_test();
*/

/*
TODO:
    1. create github repo
    2. finish 1st iteration of BST (recursive)
    3. commit & push to repo
    4. WRITE IN RUST TO GET A BETTER UNDERSTANDING OF OWNERSHIP AND HOW RC<REFCELL<>> WORKS AS A WAY TO BYPASS THE BORROW CHECKER AT COMPILE TIME
*/

int main(int argc, char *argv[])
{
    int size = 10;                                          // number of Nodes

    int *int_array = malloc(sizeof(int) * size);

    Node** node_array = malloc(sizeof(Node*) * size);       // array of pointers to Nodes

    int i;
    for (i = 0; i < 10; i++) {
        int_array[i] = rand() % 100;                        // initialize int_array
    }

    for (i = 0; i < 10; i++) {
        node_array[i] = build_node(int_array[i]);           // initialize node_array & assign payload
    }

    bst_build_tree(node_array, size);                       // assign l & r

    //print_tree(node_array[0]);
    print_tree_structured(node_array[0], size);

    //bst_search(node_array[0], node_array[0]);
    //bst_search(node_array[0], node_array[9]);

    printf("Deleting Node with payload=%d\n", node_array[9]->payload);
    bst_deletion(node_array[0], node_array[0], node_array[9]);
    size--;

    // after deletion size changes... duh, this caused me many problems when working on print_tree_structured function
    print_tree_structured(node_array[0], size);
    
    int depth = bst_height(node_array[0]);
    printf("height of root = %d\n", depth);
}