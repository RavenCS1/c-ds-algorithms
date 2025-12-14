#include "huffman.h"

int parent(int i){
    return (i - 1) / 2;
}

int left(int i){
    return 2 * i + 1;
}

int right(int i){
    return 2 * i + 2;
}

void swap(leaf* a, leaf* b){
    leaf tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

void min_heapify(heap* holder, int i){
    int l = left(i);
    int r = right(i);
    int smallest;
    if((l < holder -> heap_size) && (holder -> tab[l].counter < holder -> tab[i].counter))
        smallest = l;
    else
        smallest = i;
    if((r < holder -> heap_size) && (holder -> tab[r].counter < holder -> tab[smallest].counter))
        smallest = r;
    if(smallest != i){
       swap(&(holder -> tab[i]), &(holder -> tab[smallest]));
       min_heapify(holder, smallest);
    }
    return;
}

void build_min_heap(heap* holder){
    holder -> heap_size = holder -> length;
    for(int i = holder -> length / 2 - 1; i >= 0; i--)
        min_heapify(holder, i);
    return;
}

leaf* heap_extract_min(heap* holder){
    leaf* tmp = 0;
    if(holder -> heap_size < 1){
        printf("Błąd - kopiec jest pusty!\n");
        tmp = malloc(sizeof(*tmp));
        if(!tmp){
            printf("Nie udało się zamallocowac pustego liścia!\n");
            exit(EXIT_FAILURE);
        }
        *tmp = (leaf){0, 0, 0, '.'};
        return tmp;
    }
    leaf min = holder -> tab[0];
    tmp = malloc(sizeof(*tmp));
    if(!tmp){
        printf("Nie udało się zamallocować liścia!\n");
        exit(EXIT_FAILURE);
    }
    *tmp = min;
    holder -> tab[0] = holder -> tab[holder -> heap_size - 1];
    holder -> heap_size -= 1;
    min_heapify(holder, 0);
    return tmp;
}

void heap_decrease_key(heap* holder, int i, leaf* key, leaf old, bool changed){
    if(key -> counter > holder -> tab[i].counter){
        printf("Nowy klucz jest większy niż klucz aktualny!\n\n");
        if(!changed)
            holder -> tab[holder -> heap_size - 1] = old;
        else{
            holder -> length -= 1;
            holder -> heap_size -= 1;
            holder -> tab = realloc(holder -> tab, (holder -> heap_size) * sizeof(leaf));
        }
        return;
    }
    holder -> tab[i] = *key;
    while(i > 0 && holder -> tab[parent(i)].counter > holder -> tab[i].counter){
        swap(&(holder -> tab[i]), &(holder -> tab[parent(i)]));
        i = parent(i);
    }
    return;
}

void min_heap_insert(heap* holder, leaf* key){
    holder -> heap_size += 1;
    bool changed = false;
    if(holder -> heap_size > holder -> length){
        changed = true;
        holder -> tab = realloc(holder -> tab, (holder -> heap_size) * sizeof(leaf));
        if(!(holder -> tab)){
            printf("Nie udało się powiększyć kopca!\n");
            exit(EXIT_FAILURE);
        }
        holder -> length = holder -> heap_size;
    }
    leaf old;
    if(!changed)
        old = holder -> tab[holder -> heap_size - 1];
    else{
        old.left = old.right = 0;
        old.counter = 0;
        old.sign = '.';
    }
    holder -> tab[holder -> heap_size - 1] = (leaf){0, 0, INT_MAX, '.'};
    heap_decrease_key(holder, holder -> heap_size - 1, key, old, changed);
    return;
}

void print_heap(heap* holder){
    printf("Length: %d\n", holder -> length);
    printf("Heap_size: %d\n\n", holder -> heap_size);
    printf("Whole table:\n");
    for(int i = 0; i < holder -> length; ++i){
        printf("\ntab[%d]:\n", i);
        if(holder -> tab[i].sign != '\n')
            printf("Litera: %c\n", holder -> tab[i].sign);
        else
            printf("Litera: \\n\n");
        printf("Liczba wystąpień: %d\n", holder -> tab[i].counter);
    }
    printf("\nHeap only:\n");
    for(int i = 0; i < holder -> heap_size; ++i){
        printf("\ntab[%d]:\n", i);
        if(holder -> tab[i].sign != '\n')
            printf("Litera: %c\n", holder -> tab[i].sign);
        else
            printf("Litera: \\n\n");
        printf("Liczba wystąpień: %d\n", holder -> tab[i].counter);
    }
    printf("\n");
    return;
}

void free_heap(heap** holder_adress){
    printf("Zwalniam kopiec!\n\n");
    free((*holder_adress) -> tab);
    free(*holder_adress);
    *holder_adress = 0;
    return;
}

heap* create_heap(int n, leaf* tab){
    heap* holder = malloc(sizeof(*holder));
    if(!holder){
        printf("Nie udało się zamallocować pamięci na informacje o kopcu!\n");
        exit(EXIT_FAILURE);
    }
    holder -> length = n;
    holder -> heap_size = n;
    holder -> tab = tab;
    return holder;
}

void treewalk(leaf* node, int depth, char* buffer, char* tabsign, char** tabcodes, int* ptridx){
    if(!node) return;
    if(!(node -> left) && !(node -> right)){
        buffer[depth] = '\0';
        tabsign[*ptridx] = node -> sign;
        strcpy(tabcodes[*ptridx], buffer);
        (*ptridx)++;
    }
    else{
        if(node -> left){
            buffer[depth] = '0';
            treewalk(node -> left, depth + 1, buffer , tabsign, tabcodes, ptridx);
        }
        if(node -> right){
            buffer[depth] = '1';
            treewalk(node -> right, depth + 1, buffer , tabsign, tabcodes, ptridx);
        }
    }
}

void write_bit(FILE* file, unsigned char bit, unsigned char* buf, int* bit_count){
    *buf = (*buf << 1) | (bit & 1);
    (*bit_count)++;
    if(*bit_count == 8){
        fwrite(buf, 1, 1, file);
        *bit_count = 0;
        *buf = 0;
    }
}

void free_tree(leaf* root){
    if(!root) return;
    free_tree(root -> left);
    free_tree(root -> right);
    free(root);
}

void decode(leaf* root, char* coded, char* decoded){
    FILE* fcoded = fopen(coded, "rb");
    if(!fcoded){
        printf("Nie udało się otworzyć pliku binarnego do dekodowania!\n");
        exit(EXIT_FAILURE);
    }
    FILE* fdecoded = fopen(decoded, "w");
    if(!fdecoded){
        printf("Nie udało się otworzyć pliku tekstowego do dekodowania!\n");
        fclose(fcoded);
        exit(EXIT_FAILURE);
        return;
    }
    int input_length = 0;
    fread(&input_length, sizeof(int), 1, fcoded);
    int decoded_count = 0;
    leaf* current = root;
    int byte;
    while(decoded_count < input_length && (byte = getc(fcoded)) != EOF){
        for(int bit_pos = 7; bit_pos >= 0; bit_pos--){
            int bit = (byte >> bit_pos) & 1;
            if(!bit)
                current = current->left;
            else
                current = current->right;

            if(!current){
                printf("Błąd dekodowania\n");
                fclose(fcoded);
                fclose(fdecoded);
                return;
            }

            if(!(current -> left) && !(current -> right)){
                fputc(current -> sign, fdecoded);
                current = root;
                decoded_count++;
                if(decoded_count == input_length)
                    break;
            }
        }
    }
    fclose(fcoded);
    fclose(fdecoded);
}
