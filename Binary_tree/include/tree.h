#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 6

typedef struct tnode{
    int key;
    struct tnode* parent;
    struct tnode* left;
    struct tnode* right;
} node;

int rand_i(int a, int b);
void inorder_tree_walk(node* x);
void preorder_tree_walk(node* x);
void postorder_tree_walk(node* x);
node* tree_search(node* x, int k);
node* iterative_tree_search(node* x, int k);
node* tree_minimum(node* x);
node* tree_maximum(node* x);
node* tree_successor(node* x);
node* tree_predecessor(node* x);
node* create(int k);
void tree_insert(node** root, node* z);
void transplant(node** root, node* u, node* v);
void tree_delete(node** root, node* z);
void free_tree(node** root);

#endif
