#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#include <setjmp.h>
#include <stdbool.h>

typedef struct heap{
    int length;
    int heap_size;
    int* tab;
} heap;

int parent(int);
int left(int);
int right(int);
void swap(int*, int*);
void min_heapify(heap*, int);
void build_min_heap(heap*);
void heapsort(heap*);
void odwr(heap*);
int heap_minimum(heap*);
int heap_extract_min(heap*);
void heap_decrease_key(heap*, int, int, int, bool);
void min_heap_insert(heap*, int);
void print_heap(heap*);
void free_heap(heap**);
int rand_i(int, int);
heap* create_heap(int);

#endif
