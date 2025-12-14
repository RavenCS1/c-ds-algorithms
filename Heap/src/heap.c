#include "heap.h"

int parent(int i){
    return (i - 1) / 2;
}

int left(int i){
    return 2 * i + 1;
}

int right(int i){
    return 2 * i + 2;
}

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

void min_heapify(heap* holder, int i){
    int l = left(i);
    int r = right(i);
    int smallest;
    if((l < holder -> heap_size) && (holder -> tab[l] < holder -> tab[i]))
        smallest = l;
    else
        smallest = i;
    if((r < holder -> heap_size) && (holder -> tab[r] < holder -> tab[smallest]))
        smallest = r;
    if(smallest != i){
       swap(&(holder -> tab[i]), &(holder -> tab[smallest]));
       min_heapify(holder, smallest);
    }
    return;
}

void build_min_heap(heap* holder){
    holder -> heap_size = holder -> length;
    for(int i = holder -> length / 2 - 1; i >= 0; --i)
        min_heapify(holder, i);
    return;
}

void heapsort(heap* holder){
    build_min_heap(holder);
    for(int i = (holder -> length) - 1; i >= 1; --i){
        swap(&(holder -> tab[0]), &(holder -> tab[i]));
        holder -> heap_size -= 1;
        min_heapify(holder, 0);
    }
    holder -> heap_size = holder -> length;
    return; 
}
void odwr(heap* holder){
    for (int i = 0; i < holder -> length / 2; ++i)
        swap(&(holder -> tab[i]), &(holder -> tab[holder -> length - 1 - i]));
}

int heap_minimum(heap* holder){
    return holder -> tab[0];
}

int heap_extract_min(heap* holder){
    if(holder -> heap_size < 1){
        printf("Błąd - kopiec jest pusty!\n");
        return -1;
    }
    int min = holder -> tab[0];
    holder -> tab[0] = holder -> tab[holder -> heap_size - 1];
    holder -> heap_size -= 1;
    min_heapify(holder, 0);
    return min;
}

void heap_decrease_key(heap* holder, int i, int key, int old, bool changed){
    if(key > holder -> tab[i]){
        printf("Nowy klucz jest większy niż klucz aktualny!\n\n");
        if(!changed)
            holder -> tab[holder -> heap_size - 1] = old;
        else{
            holder -> length -= 1;
            holder -> heap_size -= 1;
            holder -> tab = realloc(holder -> tab, (holder -> heap_size) * sizeof(int));
        }
        return;
    }
    holder -> tab[i] = key;
    while(i > 0 && holder -> tab[parent(i)] > holder -> tab[i]){
        swap(&(holder -> tab[i]), &(holder -> tab[parent(i)]));
        i = parent(i);
    }
    return;
}

void min_heap_insert(heap* holder, int key){
    holder -> heap_size += 1;
    bool changed = false;
    if(holder -> heap_size > holder -> length){
        changed = true;
        holder -> tab = realloc(holder -> tab, (holder -> heap_size) * sizeof(int));
        if(!(holder -> tab)){
            printf("Nie udało się powiększyć kopca!\n");
            exit(EXIT_FAILURE);
        }
        holder -> length = holder -> heap_size;
    }
    int old;
    if(!changed)
        old = holder -> tab[holder -> heap_size - 1];
    else
        old = -1;
    holder -> tab[holder -> heap_size - 1] = INT_MAX; 
    heap_decrease_key(holder, holder -> heap_size - 1, key, old, changed);
    return;
}

void print_heap(heap* holder){
    printf("Length: %d\n", holder -> length);
    printf("Heap_size: %d\n\n", holder -> heap_size);
    printf("Whole table:\n");
    for(int i = 0; i < holder -> length; ++i)
        printf("tab[%d] = %d\n", i, holder -> tab[i]);
    printf("\nHeap only:\n");
    for(int i = 0; i < holder -> heap_size; ++i)
        printf("tab[%d] = %d\n", i, holder -> tab[i]);
    printf("\n");
    return;
}

void free_heap(heap** holder_adress){
    printf("Zwalniam kopiec!\n");
    free((*holder_adress) -> tab);
    free(*holder_adress);
    *holder_adress = 0;
    return;
}

int rand_i(int a, int b){
    return (a + rand() % (b - a + 1));
}

heap* create_heap(int n){
    heap* holder = malloc(sizeof(heap));
    if(!holder){
        printf("Nie udało się zamallocować pamięci na informacje o kopcu!\n");
        exit(EXIT_FAILURE);
    }
    holder -> length = n;
    holder -> heap_size = n;
    holder -> tab = malloc(n * sizeof(int));
    if(!(holder -> tab)){
        printf("Nie udało się zamallocować kopca!\n");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < n; ++i)
        holder -> tab[i] = rand_i(1, n);
    return holder;
}

