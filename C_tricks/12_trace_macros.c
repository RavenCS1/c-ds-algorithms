#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRACE_ON 1
#define STRINGIFY(X) #X
#define STRGY(X) STRINGIFY(X)

#define TRACE_PRINT6(F, ...) \
    do{                      \
        if(TRACE_ON)         \
            fprintf(stderr, "%s:" STRGY(__LINE__) ": " F "\n", __func__, __VA_ARGS__); \
    }while(false)

#define TRACE_FIRST(...) TRACE_FIRST0(__VA_ARGS__, 0)
#define TRACE_FIRST0(_0, ...) _0

#define TRACE_LAST(...) TRACE_LAST0(__VA_ARGS__, 0)
#define TRACE_LAST0(_0, ...) __VA_ARGS__


#define TRACE_PRINT8(...) \
    TRACE_PRINT6(TRACE_FIRST(__VA_ARGS__) "%.0d", \
    TRACE_LAST(__VA_ARGS__))

int main(void){
    int first = 42;
    int second = 97;
    TRACE_PRINT8("a collection: %d, %d", first, second);
    TRACE_PRINT8("another string");
    printf("%p: %s\n", NULL, "print of NULL");
    return EXIT_SUCCESS;
}
