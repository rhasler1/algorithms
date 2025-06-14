// function file for struct TreeNode (found in ../include/tree_node.h)

#include "tree_node.h"
#include <stdio.h>
#include <stdlib.h>

TreeNode* build_node(int payload)
{
    //printf("received payload: %d\n", payload);

    TreeNode* node = malloc(sizeof(TreeNode));

    if (node) {
        node->l = NULL;
        node->r = NULL;
        node->payload = payload;
    }
    
    return node;
}

/* return -1 if either arg TreeNode is NULL, -2 if left child already exists, 1 on success */
int insert_left(TreeNode* parent, TreeNode* node)
{
    if (parent == NULL || node == NULL)     return -1;
    if (parent->l != NULL)                  return -2;

    parent->l = node;

    return 1;
}

/* return -1 if either arg TreeNode is NULL, -2 if right child already exists, 1 on success */
int insert_right(TreeNode* parent, TreeNode* node)
{
    if (parent == NULL || node == NULL)     return -1;
    if (parent->r != NULL)                  return -2;

    parent->r = node;

    return 1;
}

/* returns -1 if arg TreeNode is NULL, 1 on success */
int free_node(TreeNode* node) {
    if (node == NULL) return -1;

    free(node);

    return 1;
}

//TODO: this should be common across all tree implementations of TreeNode.
// 
void print_tree_structured(TreeNode *root, int size)
{
    int x_pos[size];                        // store x pos of Node
    int x = 0;

    int y_pos[size];                        // store y pos of Node
    int y = 0;

    TreeNode* node_array[size];                 // storing Nodes by level
    node_array[0] = root;                   // store the root
    x_pos[0] = x;                           // store x position of root
    y_pos[0] = y;                           // store y position of root

    TreeNode* node = NULL;                      // pointer to current Node

    int dequeue = 0;                        // dequeue index into Array
    int enqueue = 0;                        // enqueue index into Array (Not actually enqueue/dequeue, just calculating index, see while loop)

    // by-level traversal: l2print
    while (dequeue < size) {
        node = node_array[dequeue];
        x = x_pos[dequeue];
        y = y_pos[dequeue];

        if (node->l != NULL) {
            node_array[++enqueue] = node->l;
            x_pos[enqueue] = x - 1;
            y_pos[enqueue] = y + 1;
        }
        
        if (node->r != NULL) {
            node_array[++enqueue] = node->r;
            x_pos[enqueue] = x + 1;
            y_pos[enqueue] = y + 1;
        }

        dequeue++;
    }

    printf("\n### DATA STRUCTURES AFTER BY-LEVEL TRAVERSAL ###\n\n");
    for (int i = 0; i < size; i++) {
        printf("payload=%d, y_pos=%d, x_pos=%d\n", node_array[i]->payload, y_pos[i], x_pos[i]);
    }

    // get frequency of y_pos to determine max width: doing this in an attempt to center the root Node
    int frequency_array[size];
    for (int i = 0; i < size; i++) frequency_array[i] = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (y_pos[i] == y_pos[j]) {
                frequency_array[i] = frequency_array[i] + 1;
            }
        }
    }

    // determine max width
    int most_frequent = frequency_array[0];
    for (int i = 0; i < size; i++) {
        most_frequent = max(most_frequent, frequency_array[i]);
    }
    //printf("\n### THE WIDTH OF THE TREE IS = %d ###\n\n", most_frequent);

    printf("\n### PRINTING TREE ###\n\n");
    int matrix_width = most_frequent * 2;
    int mid_point = matrix_width / 2;
    int num_spaces = mid_point;
    int depth = 0;

    for (int i = 0; i < size; i++) {
        if (i == 0) {
            // root special case
            printf("%*s[%2d]", mid_point, " ", node_array[i]->payload);
        }
        else if (depth != y_pos[i]) {
            // y_pos changed
            printf("\n");

            depth = y_pos[i];

            num_spaces = mid_point + x_pos[i];

            printf("%*s[%2d]", num_spaces, " ", node_array[i]->payload);
        }
        else {
            // y_pos did not change
            num_spaces = y_pos[i] - y_pos[i-1];

            printf("%*s[%2d]", num_spaces, " ", node_array[i]->payload);

        }
    }

    printf("\n");
}