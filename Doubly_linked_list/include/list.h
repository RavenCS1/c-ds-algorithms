#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct tnode{       
	int value;
    struct tnode *next;
    struct tnode *prev;
} node;

int rand_i(int, int);
node* create(int);
void print_list_next(node*);
void print_list_prev(node*);
node* add_first(node*, node*);
node* add_last(node*, node*);
node* pull_all_elements(node**, int);
node* pull_one_element(node**, int);
void add_sort(node**, node*);
void sort_divided(node**);
void sort_notdivided(node**);
void sort(node**);
void free_list(node**);

#endif
