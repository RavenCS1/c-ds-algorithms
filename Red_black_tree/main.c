#include "brtree.h"

int main(void){
    holder* tree = allocate_holder();
    leaf* tmp = 0;
    int ival[] = {10, 5, 1, 15, 20, 18, 25, 30, 2, 8, 6, 12, 14, 7, 3, 4};
    
    for(int i = 0; i < NUMOFEL(ival); ++i){
        tmp = allocate_leaf(ival[i]);
        if(tree -> root != 0) rb_insert(tree, tmp);
        else{
            tree -> root = tmp;
            tree -> root -> color = BLACK;
            tree -> root -> parent = tree -> guard;
            tree -> root -> left = tree -> root -> right = tree -> guard;
            tree -> numberofel += 1;
        }
    }
    printf("Inorder_tree_walk:\n");
    inorder_tree_walk(tree, tree -> root);
    printf("Preorder_tree_walk:\n");
    preorder_tree_walk(tree, tree -> root);
    printf("Postorder_tree_walk:\n");
    postorder_tree_walk(tree, tree -> root);
    
    leaf* result1 = tree_search(tree, tree -> root, 30);
    leaf* result2 = iterative_tree_search(tree, tree -> root, 11);
    if(result1 != tree -> guard){printf("Search 30:\n"); print_leaf(tree, result1);}
    if(result2 != tree -> guard){printf("Search 11:\n"); print_leaf(tree, result2);}

    leaf* min = tree_minimum(tree, tree -> root);
    leaf* max = tree_maximum(tree, tree -> root);
    if(min != tree -> guard){printf("Tree_min:\n"); print_leaf(tree, min);}
    if(max != tree -> guard){printf("Tree_max:\n"); print_leaf(tree, max);}
    
    leaf* successor = tree_successor(tree, min);
    leaf* predecessor = tree_predecessor(tree, max);
    if(successor != tree -> guard){printf("Successor of min:\n"); print_leaf(tree, successor);}
    if(predecessor != tree -> guard){printf("Predecessor of max:\n"); print_leaf(tree, predecessor);}

    int dval1[] = {4, 7, 14, 18, 25, 30};
    int dval2[] = {6, 8, 12};
    int dval3[] = {5, 10, 15};
    
    leaf* delete = 0;
    for(int i = 0; i < NUMOFEL(dval1); ++i){
        delete = iterative_tree_search(tree, tree -> root, dval1[i]);
        rb_delete(tree, delete);
    }
    printf("Inorder_tree_walk:\n");
    inorder_tree_walk(tree, tree -> root);

    for(int i = 0; i < NUMOFEL(dval2); ++i){
        delete = iterative_tree_search(tree, tree -> root, dval2[i]);
        rb_delete(tree, delete);
    }
    printf("Inorder_tree_walk:\n");
    inorder_tree_walk(tree, tree -> root);
    
    for(int i = 0; i < NUMOFEL(dval3); ++i){
        delete = iterative_tree_search(tree, tree -> root, dval3[i]);
        rb_delete(tree, delete);
    }
    printf("Inorder_tree_walk:\n");
    inorder_tree_walk(tree, tree -> root);
    
    free_tree(tree, tree -> root);
    free_holder(&tree);
    return EXIT_SUCCESS;
}
