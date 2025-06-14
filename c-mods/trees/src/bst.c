// binary search tree: non-self balancing
// all functions implemented using recursion
// see ../sorting/ for non-recursive sorting structures

#include "tree_node.h"
#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* returns node array */
TreeNode** bst_build_tree_nodes(int* int_array, const unsigned int size)
{
    if (size == 0) return NULL;

    TreeNode** node_array = malloc(sizeof(TreeNode*) * size);

    int i;
    for (i = 0; i < size; i++) {
        node_array[i] = build_node(int_array[i]);;
    }

    return node_array;
}

/* return TreeNode* to NULL on empty node_array, TreeNode* to root on success */
TreeNode* bst_build_tree(TreeNode** node_array, const unsigned int size)
{
    TreeNode* root = NULL;
    TreeNode* node = NULL;

    if (size == 0) return root;
    
    int i = 0;
    root = node_array[i];

    for (i = 1; i < size; i++) {
        node = node_array[i];

        bst_insert(root, node);
    }

    return root;
}

/* insert TreeNode in Tree */
void bst_insert(TreeNode* root, TreeNode* node)
{
    if (node->payload <= root->payload) {
        if (root->l == NULL) {
            insert_left(root, node);            // ignoring return value for now, impl debug?
        }
        else {
            bst_insert(root->l, node);
        }
    }
    else {
        if (root->r == NULL) {
            insert_right(root, node);         // ignoring return value for now, impl debug?
        }
        else {
            bst_insert(root->r, node);
        }
    }
}

/* returns NULL if node cannot be found, pointer to Node in tree on success */
TreeNode* bst_search(TreeNode* root, const int payload)
{
    if (root == NULL) return NULL;

    if (root->payload == payload) {
        return root;
    }
    
    if (payload < root->payload) {
        return bst_search(root->l, payload);
    }

    return bst_search(root->r, payload);
}

/* returns pointer to TreeNode with minimum payload on success */
TreeNode* bst_min(TreeNode* root)
{
    if (root == NULL) return NULL;

    TreeNode* min_node = root;

    if (root->l != NULL) {
        min_node = bst_min(root->l);
    }

    return min_node;
}

/* returns pointer to TreeNode with maximum payload on success */
TreeNode* bst_max(TreeNode* root)
{
    if (root == NULL) return NULL;

    TreeNode* max_node = root;

    if (root->r != NULL) {
        max_node = bst_max(root->r);
    }

    return max_node;
}

/* free the bst */
int free_bst(TreeNode* root)
{
    if (root == NULL) return -1;

    if (root->l != NULL) {
        free_bst(root->l);
    }

    if (root->r != NULL) {
        free_bst(root->r);
    }

    return free_node(root);
}

/*
This code snippet is from my original exploration of BST in C.
TODO:
    1. change Node->TreeNode
    2. return type should be...? maybe pointer to deleted node... pass free responsibility to caller

// Note: Inorder successor is needed only when the right child is not empty.
// In this particular case, the inorder successor can be obtained by finding the minimum value in the right child of the node.
// working for one case so far:
//      [0]
//           [2]
//       [1]     [3]
//
void bst_deletion(Node* root, Node* parent, Node* to_delete)
{
    if (root == NULL || to_delete == NULL) return;

    if      (to_delete->payload < root->payload)    bst_deletion(root->l, root, to_delete);
    else if (to_delete->payload > root->payload)    bst_deletion(root->r, root, to_delete);
    else {
        // found Node to delete
        // creating temporary pointer
        Node* temp = NULL;

        // two child case
        if      (to_delete->l != NULL && to_delete->r != NULL) {

            // find minimum of to_delete's right child
            temp = bst_min_ptr(to_delete->r);
            if (temp == NULL) return; // something went wrong

            // at this point we want to replace to_delete with temp.
            // we need the parent of to_delete
            temp->l = to_delete->l;

            if (temp != to_delete->r)  temp->r = to_delete->r;


        }
        // one child case
        else if (to_delete->l != NULL) {
            temp = to_delete->l;
        }
        // one child case
        else if (to_delete->r != NULL) {
            temp = to_delete->r;
        }
        else {
            // leaf node case
            temp = NULL;
        }

        // set parent left or right node to temp
        if      (parent->l == to_delete) {
            parent->l = temp;
        }
        else if (parent->r == to_delete) {
            parent->r = temp;
        }
    }
}
*/