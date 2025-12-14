#include "tree.h"

int main(void){
    srand(time(0));
    node* root = 0;
    node* new = 0;
    for(int i = 0; i < N; ++i){
        new = create(rand_i(1, 20));
        tree_insert(&root, new);
    }
    printf("Inorder_tree_walk:\n\n");
    inorder_tree_walk(root);
    printf("Preorder_tree_walk:\n\n");
    preorder_tree_walk(root);
    printf("Postorder_tree_walk:\n\n");
    postorder_tree_walk(root);
    node* found1 = tree_search(root, rand_i(1, 20));
    if(found1){
        printf("Tree_search found %p:\n", found1);
        printf("Wartość klucza: %d\n", found1 -> key);
        printf("Adres rodzica: %p\n", found1 -> parent);
        printf("Adres lewego syna: %p\n", found1 -> left);
        printf("Adres prawego syna: %p\n\n", found1 -> right);
    }
    node* found2 = iterative_tree_search(root, rand_i(1, 20));
    if(found2){
        printf("Iterative_tree_search found %p:\n", found2);
        printf("Wartość klucza: %d\n", found2 -> key);
        printf("Adres rodzica: %p\n", found2 -> parent);
        printf("Adres lewego syna: %p\n", found2 -> left);
        printf("Adres prawego syna: %p\n\n", found2 -> right);
    }
    node* min = tree_minimum(root);
    printf("Minimum drzewa %p:\n", min);
    printf("Wartość klucza: %d\n", min -> key);
    printf("Adres rodzica: %p\n", min -> parent);
    printf("Adres lewego syna: %p\n", min -> left);
    printf("Adres prawego syna: %p\n\n", min -> right);
    node* max = tree_maximum(root);
    printf("Maximum drzewa %p:\n", max);
    printf("Wartość klucza: %d\n", max -> key);
    printf("Adres rodzica: %p\n", max -> parent);
    printf("Adres lewego syna: %p\n", max -> left);
    printf("Adres prawego syna: %p\n\n", max -> right);
    node* suc = tree_successor(min);
    printf("Następnik minimum drzewa %p:\n", suc);
    printf("Wartość klucza: %d\n", suc -> key);
    printf("Adres rodzica: %p\n", suc -> parent);
    printf("Adres lewego syna: %p\n", suc -> left);
    printf("Adres prawego syna: %p\n\n", suc -> right);
    node* pre = tree_predecessor(max);
    printf("Poprzednik maximum drzewa %p:\n", pre);
    printf("Wartość klucza: %d\n", pre -> key);
    printf("Adres rodzica: %p\n", pre -> parent);
    printf("Adres lewego syna: %p\n", pre -> left);
    printf("Adres prawego syna: %p\n\n", pre -> right);
    for(int i = 0; i < N / 2; ++i){
        node* todelete = iterative_tree_search(root, rand_i(1,20));
        if(todelete){
            printf("Usuwam następujący element: %p\n", todelete);
            printf("Wartość klucza: %d\n", todelete -> key);
            printf("Adres rodzica: %p\n", todelete -> parent);
            printf("Adres lewego syna: %p\n", todelete -> left);
            printf("Adres prawego syna: %p\n\n", todelete -> right);
            tree_delete(&root, todelete);
        }
    }
    printf("Inorder_tree_walk:\n\n");
    inorder_tree_walk(root);
    free_tree(&root);
    return EXIT_SUCCESS;
}
