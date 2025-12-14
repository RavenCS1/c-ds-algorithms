#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

typedef struct leaf{
    struct leaf* left;
    struct leaf* right;
    int counter;
    char sign;
} leaf;

typedef struct heap{
    int length;
    int heap_size;
    leaf* tab;
} heap;

int parent(int);
int left(int);
int right(int);
void swap(leaf*, leaf*);
void min_heapify(heap*, int);
void build_min_heap(heap*);
leaf* heap_extract_min(heap*);
void heap_decrease_key(heap*, int, leaf*, leaf, bool);
void min_heap_insert(heap*, leaf*);
void print_heap(heap*);
void free_heap(heap**);
heap* create_heap(int, leaf*);
void treewalk(leaf*, int , char* , char* , char** , int*);
void write_bit(FILE* file, unsigned char bit, unsigned char* buf, int* bit_count);
void free_tree(leaf* node);
void decode(leaf* root, char* coded, char* decoded);

#endif
