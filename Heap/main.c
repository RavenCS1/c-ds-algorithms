#include "heap.h"

jmp_buf env;

void handler(void){
    longjmp(env, 1);
}

int main(void){
    srand(time(0));
    int n;
    if(setjmp(env))
        printf("Rozmiar powinien być > 0!\n");
    do{
        printf("Podaj rozmiar kopca, który chcesz stworzyć (> 0): ");
        scanf("%d", &n);
        if(n <= 0)
            handler();
    } while(n <= 0);
    heap* holder = create_heap(n);
    printf("\n\nZaraz po wylosowaniu:\n\n");
    print_heap(holder);
    build_min_heap(holder);
    printf("Zbudowany kopiec:\n\n");
    print_heap(holder);
    int min = heap_extract_min(holder);
    printf("Min = %d\n\nPo usunięciu min:\n\n", min);
    print_heap(holder);
    heap_decrease_key(holder, holder -> heap_size - 1, min, holder -> tab[holder -> heap_size - 1], false);
    printf("Po zmniejszeniu klucza ostatniego elementu kopca:\n\n");
    print_heap(holder);
    min_heap_insert(holder, 0);
    min_heap_insert(holder, -1);
    printf("Po wstawieniu dwóch elementów o kluczach mniejszych:\n\n");
    print_heap(holder);
    heapsort(holder);
    printf("Po posortowaniu heapsortem:\n\n");
    print_heap(holder);
    odwr(holder);
    printf("Po obróceniu tabeli:\n\n");
    print_heap(holder);
    free_heap(&holder);
    return 0;
}



