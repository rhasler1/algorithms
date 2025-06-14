#ifndef TREENODE_H
#define TREENODE_H

// TreeNode struct
typedef struct TreeNode {
    struct TreeNode* l;             // pointer to left struct TreeNode
    struct TreeNode* r;             // pointer to right struct TreeNode
    int payload;                    // some int payload
} TreeNode;

// TreeNode specific functions
/* allocate memory for TreeNode & assign payload */
TreeNode* build_node(int payload);
/* return -1 if either arg TreeNode is NULL, -2 if left child already exists, 1 on success */
int insert_left(TreeNode* parent, TreeNode* node);
/* return -1 if either arg TreeNode is NULL, -2 if right child already exists, 1 on success */
int insert_right(TreeNode* parent, TreeNode* node);
/* returns -1 if arg TreeNode is NULL, 1 on success */
int free_node(TreeNode* node);


// common functions across Tree implementations
//TODO: determine all common functions: e.g., min, max,...
void print_tree_structured(TreeNode *root, int size);


#endif