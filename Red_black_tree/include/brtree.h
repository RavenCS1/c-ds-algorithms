#ifndef BRTREE_H
#define BRTREE_H

#include <stdio.h>
#include <stdlib.h>

#define NUMOFEL(X) (sizeof(X)/sizeof(*X))

typedef enum color {BLACK, RED} color;

typedef struct leaf{
    int value;
    color color;
    struct leaf* parent;
    struct leaf* left;
    struct leaf* right;
} leaf;

typedef struct holder{
    struct leaf* root;
    struct leaf* guard;
    int numberofel;
} holder;

leaf* allocate_leaf(int);
holder* allocate_holder(void);
void free_tree(holder*, leaf*);
void free_holder(holder**);
void inorder_tree_walk(holder*, leaf*);
void preorder_tree_walk(holder*, leaf*);
void postorder_tree_walk(holder*, leaf*);
void print_leaf(holder* tree, leaf*); //debugging hook nr. 1
void print_holder(holder*); //debugging hook nr. 2
leaf* tree_search(holder*, leaf*, int);
leaf* iterative_tree_search(holder*, leaf*, int);
leaf* tree_minimum(holder*, leaf*);
leaf* tree_maximum(holder*, leaf*);
leaf* tree_successor(holder*, leaf*);
leaf* tree_predecessor(holder*, leaf*);
void right_rotate(holder*, leaf*);
void left_rotate(holder*, leaf*);
void rb_insert(holder*, leaf*);
void rb_insert_fixup(holder*, leaf*);
void rb_transplant(holder*, leaf*, leaf*);
void rb_delete(holder*, leaf*);
void rb_delete_fixup(holder*, leaf*);

#endif
