#ifndef NODE_H
#define NODE_H

#define min(a, b) ((a) < (b) ? (a) : (b))

#define max(a, b) ((a) > (b) ? (a) : (b))

// Node struct
typedef struct Node {
    struct Node* l;     // pointer to left struct Node
    struct Node* r;     // pointer to right struct Node
    int payload;        // some int payload
} Node;

// functions(methods) definitions for struct Node
// implementations are found in Node.c
Node* build_node(int payload);
int insert_node_left(Node* parent, Node* node);
int insert_node_right(Node* parent, Node* node);
void free_tree(Node* root);
void print_tree(Node* root);
void print_tree_structured(Node *root, int size);

// bst functions
void bst_insertion(Node* parent, Node* node);
void bst_traversal(Node* root, Node* node);
void bst_deletion(Node* root, Node* parent, Node* to_delete); // TODO: need to do some research on this
void bst_search(Node* root, Node* to_find);
int bst_min(Node* root);
Node* bst_min_ptr(Node* root);
void bst_build_tree(Node** node_array, const unsigned int size);
int bst_height(Node* root);

#endif