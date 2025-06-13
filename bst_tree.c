// creating a BST non self-balancing

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

// operations to implement:
// insertions, searching, deletion, traversal, minimum value, maximum valu

void bst_build_tree(Node** node_array, const unsigned int size)
{
    int i = 0;

    Node* root = node_array[i];               // get root node & inc 'i' after
    Node* node;                                 // node to pass to insertion

    for (i = 1; i < size; i++) {
        node = node_array[i];

        bst_insertion(root, node);              // insert node
    }
}

// left_node=smaller, right_node=larger
// traverse tree to find insertion position and insert
void bst_insertion(Node* root, Node* node)
{
    if (node->payload <= root->payload) {
        if (root->l == NULL) {
            root->l = node;
        }
        else {
            bst_insertion(root->l, node);
        }
    }
    else {
        if (root->r == NULL) {
            root->r = node;
        }
        else {
            bst_insertion(root->r, node);
        }
    }
}

void bst_search(Node* root, Node* to_find)
{
    if (root == NULL || to_find == NULL) return;

    if (root->payload == to_find->payload) {
        printf("Found %d in BST\n", to_find->payload);
        return;
    }
    else if (to_find->payload < root->payload) {
        bst_search(root->l, to_find);
    }
    else {
        bst_search(root->r, to_find);
    }
}

int bst_min(Node* root)
{
    int ret;                                     // returned payload
    int min_res = 999;                           // minimum between current payload and returned payload (should be init to INF)

    if (root == NULL) {
        return min_res;
    }

    if (root->l != NULL) {
        // search left subtree (min will be here)
        ret = bst_min(root->l);
    }
    else {
        // then root is smallest
        ret = root->payload;
    }

    min_res = min(min_res, ret);

    return min_res;
}

int bst_max(Node* root)
{
    int ret;
    int max_res = -1;

    if (root == NULL) {
        return max_res;
    }

    if (root->r != NULL) {
        ret = bst_max(root->r);
    }
    else {
        ret = root->payload;
    }

    max_res = max(max_res, ret);

    return max_res;
}


// seems to be working, the bst_min function can be changed to mimic this
// there is no need to calculate the min in each function call as done in bst_min
// If NULL returned, then initial root argument was NULL.
// Else returns pointer to the Node w/ minimum payload.
Node* bst_min_ptr(Node* root)
{
    Node* ret = NULL;

    if (root == NULL) {
        return ret;
    }

    if (root->l != NULL) {
        ret = bst_min_ptr(root->l);
    }
    else {
        ret = root;
    }

    return ret;
}

int bst_height(Node* root)
{
    if (root == NULL) {
        return -1;
    }

    if (root->l != NULL) {
        return bst_height(root->l) + 1;
    }

    if (root->r != NULL) {
        return bst_height(root->r) + 1;
    }

    return 0;
}




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