#ifndef BST_H
#define BST_H

#include "tree_node.h"

/* returns node array */
TreeNode** bst_build_tree_nodes(int* int_array, const unsigned int size);

/* return TreeNode* to NULL on empty node_array, TreeNode* to root on success */
TreeNode* bst_build_tree(TreeNode** node_array, const unsigned int size);

/* insert TreeNode in Tree */
void bst_insert(TreeNode* root, TreeNode* node);

/* returns NULL if node cannot be found, pointer to Node in tree on success */
TreeNode* bst_search(TreeNode* root, const int payload);

/* returns pointer to TreeNode with minimum payload on success */
TreeNode* bst_min(TreeNode* root);

/* returns pointer to TreeNode with maximum payload on success */
TreeNode* bst_max(TreeNode* root);

/* free the bst */
int free_bst(TreeNode* root);

#endif