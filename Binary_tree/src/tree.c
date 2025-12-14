#include "tree.h"
#include <complex.h>

int rand_i(int a, int b){
    return (a + rand() % (b - a + 1));
}

void inorder_tree_walk(node* x){
    if(x){
        inorder_tree_walk(x -> left);
        printf("Adres: %p\n", x);
        printf("Wartość klucza: %d\n", x -> key);
        printf("Adres rodzica: %p\n", x -> parent);
        printf("Adres lewego syna: %p\n", x -> left);
        printf("Adres prawego syna: %p\n\n", x -> right);
        inorder_tree_walk(x -> right);
    }
}

void preorder_tree_walk(node* x){
    if(x){
        printf("Adres: %p\n", x);
        printf("Wartość klucza: %d\n", x -> key);
        printf("Adres rodzica: %p\n", x -> parent);
        printf("Adres lewego syna: %p\n", x -> left);
        printf("Adres prawego syna: %p\n\n", x -> right);
        preorder_tree_walk(x -> left);
        preorder_tree_walk(x -> right);
    }
}

void postorder_tree_walk(node* x){
    if(x){
        postorder_tree_walk(x -> left);
        postorder_tree_walk(x -> right);
        printf("Adres: %p\n", x);
        printf("Wartość klucza: %d\n", x -> key);
        printf("Adres rodzica: %p\n", x -> parent);
        printf("Adres lewego syna: %p\n", x -> left);
        printf("Adres prawego syna: %p\n\n", x -> right);
    }
}

node* tree_search(node* x, int k){
    if(x || k == x -> key)
        return x;
    if(k < x -> key)
        return tree_search(x -> left, k);
    else
        return tree_search(x -> right, k);
}


node* iterative_tree_search(node* x, int k){
    while(x && k != x -> key){
        if(k < x -> key)
            x = x -> left;
        else
            x = x -> right;
   }
   return x;
}

node* tree_minimum(node* x){
    while(x -> left)
        x = x -> left;
    return x;
}

node* tree_maximum(node* x){
    while(x -> right)
        x = x -> right;
    return x;
}

node* tree_successor(node* x){
    if(x -> right) 
        return tree_minimum(x -> right);
    node* y = x -> parent;
    while(y && x == y -> right){
        x = y;
        y = y -> parent;
    }
    return y;
}

node* tree_predecessor(node* x){
    if(x -> left)
        return tree_maximum(x -> left);
    node* y = x -> parent;
    while(y && x == y -> left){
        x = y;
        y = y -> parent;
    }
    return y;
}


node* create(int k){
    node* new = malloc(sizeof(node));
    if(!new){
        printf("Za mało pamięci na stercie!\n");
        return 0;
    }
    new -> key = k;
    new -> parent = new -> left = new -> right = 0;
    return new;
}

void tree_insert(node** root, node* z){
    node* y = 0;
    node* x = *root;
    while(x){
        y = x;
        if(z -> key < x -> key)
            x = x -> left;
        else
            x = x -> right;
    }
    z -> parent = y;
    if(!y)
        *root = z;
    else if(z -> key < y -> key)
        y -> left = z;
    else
        y -> right = z;
    return;
}

void transplant(node** root, node* u, node* v){
    if(!(u -> parent))
        *root = v;
    else if(u == u -> parent -> left)
        u -> parent -> left = v;
    else
        u -> parent -> right = v;
   if(v)
        v -> parent = u -> parent;
    return;
}

void tree_delete(node** root, node* z){
    if(!(z -> left))
        transplant(root, z, z -> right);
    else if(!(z -> right))
        transplant(root, z, z -> left);
    else{
        node* y = tree_minimum(z -> right);
        if(y -> parent != z){
            transplant(root, y, y -> right);
            y -> right = z -> right;
            y -> right -> parent = y;
        }
        transplant(root, z, y);
        y -> left = z -> left;
        y -> left -> parent = y;
    }
    z -> left = z -> right = z -> parent = 0;
    free(z);
    return;
}

void free_tree(node** root){ 
    node* x = *root;
    node* min = 0;
    node* max = 0;
    while(((min = tree_minimum(x)) != x) && min){
        printf("Zwalniam następujący element: %p\n", min);
        printf("Wartość klucza: %d\n", min -> key);
        printf("Adres rodzica: %p\n", min -> parent);
        printf("Adres lewego syna: %p\n", min -> left);
        printf("Adres prawego syna: %p\n\n", min -> right);
        min -> parent -> left = min -> right;
        if(min -> right)
            min -> right -> parent = min -> parent;
        min -> left = min -> right = min -> parent = 0;
        free(min);
    }
    while(((max = tree_maximum(x)) != x) && max){
        printf("Zwalniam następujący element: %p\n", max);
        printf("Wartość klucza: %d\n", max -> key);
        printf("Adres rodzica: %p\n", max -> parent);
        printf("Adres lewego syna: %p\n", max -> left);
        printf("Adres prawego syna: %p\n\n", max -> right);
        max -> parent -> right = max -> left;
        if(max -> left)
            max -> left -> parent = max -> parent;
        max -> left = max -> right = max -> parent = 0;
        free(max);
    }
    printf("Zwalniam następujący element: %p\n", x);
    printf("Wartość klucza: %d\n", x -> key);
    printf("Adres rodzica: %p\n", x -> parent);
    printf("Adres lewego syna: %p\n", x -> left);
    printf("Adres prawego syna: %p\n", x -> right);
    x -> left = x -> right = 0;
    free(x);
    *root = 0;
    return;
}
