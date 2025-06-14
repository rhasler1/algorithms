// test module for ../bst.c
//TODO: work

#include "tree_node.h"
#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

int check_bst_build_tree_nodes(TreeNode** node_array, int* int_array, int size);
int check_bst_build_tree(TreeNode* root, int* int_array, int size);
int check_bst_build_tree_helper(TreeNode* root, int* sorted_int_array, int size);
int check_bst_search(TreeNode* found, int payload);

int main() {
    int size = 10;
    int *int_array = malloc(sizeof(int) * size);
    int status;

    int i;
    for (i = 0; i < size; i++) int_array[i] = rand() % 100;

    // test bst build tree nodes
    TreeNode** node_array = bst_build_tree_nodes(int_array, size);
    printf("### TEST FUNCTION: check_bst_build_tree_nodes(node_array, int_array, size) ###\n");
    status = check_bst_build_tree_nodes(node_array, int_array, size);
    if (status == 1) printf("PASS"); else printf("FAIL");
    printf("\n"); 


    // test bst build tree
    TreeNode* root = bst_build_tree(node_array, size);
    print_tree_structured(root, size);


    TreeNode* found = bst_search(root, int_array[0]);
    printf("### TEST FUNCTION: check_bst_search(TreeNode* found, payload) ###\n");
    status = check_bst_search(found, int_array[0]);
    if (status == 1) printf("PASS"); else printf("FAIL");
    printf("\n");

    TreeNode* min = bst_min(root);
    printf("Found minimum payload = %d\n", min->payload);

    TreeNode* max = bst_max(root);
    printf("Found maximum payload = %d\n", max->payload);

    status = free_bst(root);
    printf("Result of free_bst = %d\n", status);

    return 0;
}

int check_bst_search(TreeNode* found, int payload)
{
    if (found->payload == payload) return 1;
    return -1;
}

int check_bst_build_tree(TreeNode* root, int* int_array, int size)
{
    //TODO:
    if (root == NULL || int_array == NULL || size == 0) return -1;
    return 1;
}

int check_bst_build_tree_nodes(TreeNode** node_array, int* int_array, int size)
{
    int i;
    for (i=0;i<size;i++) {
        if (node_array[i]->payload != int_array[i]) return -1;
    }
    return 1;
}