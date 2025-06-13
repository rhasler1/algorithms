
// 6/10/2025
// Today I start my journey as a C programmer.
// First, I will build a binary tree, that can be cross compiled.

// compilation process
// -------------------
// source -> object files w/ unresolved vars -> linker resolves -> executable
// .c -> .o -> linker -> executable

// Add compilation directions for Mac, Linux, Windows

#include <stdio.h>
#include <stdlib.h>
#include "node.h"


void bst(int *int_array, int size);
void avl(int *int_array, int size);

// Ideally, I would like all memory allocation and deallocation to be done in the main function.
int main(int argc, char *argv[])
{
    // build nodes
    Node* node0 = build_node(0);
    Node* node1 = build_node(1);
    Node* node2 = build_node(2);
    Node* node3 = build_node(3);
    Node* node4 = build_node(4);

    // assign left/right starting with node0
    insert_node_left    (node0, node1);
    insert_node_right   (node0, node2);
    insert_node_left    (node1, node3);
    insert_node_right   (node1, node4);

    // print tree
    printf("checking tree before free\n");
    print_tree(node0);

    // free tree
    free_tree(node0);

    // check if tree has been freed
    //printf("checking tree after free\n");
    //print_tree(node0);


    // building bst
    int num_elements = 10;
    int *int_array = malloc(sizeof(int) * num_elements);
    
    int i;
    for (i = 0; i < num_elements; i++) {
        int_array[i] = i;
        // check
        //printf("%d\n", int_array[i]);
    }

    bst(int_array, num_elements);
}

//TODO: implement more BST operations
void bst(int *int_array, int size)
{
    printf("Beginning BST\n");
    // array of Node pointers
    Node** node_array = malloc(sizeof(Node*) * size);

    // build nodes for each value contained in int_array
    int i;
    for (i = 0; i < size; i++) {
        node_array[i] = build_node(int_array[i]);
    }

    // check node_array instantiation
    //for (i = 0; i < size; i++) {
    //    printf("Node %d has payload: %d\n", i, node_array[i]->payload);
    //}

    // node_array[0] is root
    // at this point the tree should look like:
    //      [0]
    //           [2]
    bst_insertion(node_array[0], node_array[2]);
    // now it should look like:
    //      [0]
    //           [2]
    //       [1]
    bst_insertion(node_array[0], node_array[1]);
    // and finally:
    //      [0]
    //           [2]
    //       [1]     [3]
    bst_insertion(node_array[0], node_array[3]);

    printf("Printing BST before removing Node 2\n");
    print_tree(node_array[0]);

    printf("Searching for Node 2 before removal\n");
    bst_search(node_array[0], node_array[2]);


    bst_deletion(node_array[0], node_array[0], node_array[2]);
    printf("Printing BST after removing Node 2\n");
    print_tree(node_array[0]);

    printf("Searching for Node 2 after removal\n");
    bst_search(node_array[0], node_array[2]);




    // node_array[2] is root
    //bst_insertion(node_array[2], node_array[1]);
    //bst_insertion(node_array[2], node_array[0]);
    //bst_insertion(node_array[2], node_array[3]);
    //print_tree(node_array[2]);
    //Node* min_ptr = bst_min_ptr(node_array[2]);
    //printf("Testing bst_min_ptr return: %d\n", min_ptr->payload);




    // the print function, simple prints left than right, so print should look like:
    // 0, 2, 1, 3
    //print_tree(node_array[0]);    
    // it does, YIPPEE!

    // search tree for a node
    //bst_search(node_array[0], node_array[1]);
    // working

    // find min
    //int min = bst_min(node_array[2]);
    //printf("min in BST = %d\n", min);

    // delete a node
    // arg1=root, arg2=parent, arg3=node_to_delete
    //printf("Beginning BST deletion\n");
    //bst_deletion(node_array[0], node_array[0], node_array[2]);
    //print_tree(node_array[0]);


    // free Node pointers
    free_tree(node_array[0]);


    // free array of Node pointers
    free(node_array);

    printf("All Done\n");
}

// build a self-balancing BST
// AVL first
void avl(int *int_array, int size)
{

}