#include <stdio.h>

// Macro to select the correct printf format string based on the argument type
#define PRINTF_FORMAT(X) _Generic((X), \
    _Bool: "%d\n", \
    char: "%c\n", \
    signed char: "%hhd\n", \
    unsigned char: "%hhu\n", \
    int: "%d\n", \
    unsigned int: "%u\n", \
    long: "%ld\n", \
    unsigned long: "%lu\n", \
    long long: "%lld\n", \
    unsigned long long: "%llu\n", \
    float: "%f\n", \
    double: "%f\n", \
    long double: "%Lf\n", \
    char*: "%s\n", \
    const char*: "%s\n", \
    void*: "%p\n", \
    default: "Unknown type\n" \
)

// The smart print macro
#define print(X) printf(PRINTF_FORMAT(X), (X))

int main(void) {
    int i = 42;
    double d = 3.14159;
    char* str = "Hello, C11 Generics!";
    
    // The exact same macro handles all different types automatically
    print(i);     // Compiles to: printf("%d\n", i);
    print(d);     // Compiles to: printf("%f\n", d);
    print(str);   // Compiles to: printf("%s\n", str);
    print('A');   // Compiles to: printf("%d\n", 'A'); (Note: char literals are ints in C)
    
    return 0;
}

