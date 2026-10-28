#include <stdio.h>

#define PRINT_TYPE(x) printf("Type: %s\n", _Generic((x), \
    int*: "pointer to int (or int array decaying to pointer)", \
    char*: "pointer to char (or string)", \
    double*: "pointer to double", \
    default: "Other/Unknown type" \
)) 

#define PRINT_TYPE2(x) printf("Type: %s\n", _Generic(&(x), \
    int(*)[5]: "int[5] array", \
    int*: "pointer to int", \
    int**: "pointer to pointer to int", \
    char(*)[20]: "char[20] array", \
    char**: "pointer to pointer to char", \
    char*: "pointer to char", \
    double**: "pointer to pointer to double", \
    double*: "pointer to double", \
    default: "Other/Unknown type" \
))

int main() {
    int my_int_array[5] = {1, 2, 3, 4, 5};
    char my_str[20] = "Hello";
    int *ptr = my_int_array;

    PRINT_TYPE(my_int_array); 
    PRINT_TYPE(my_str);
    PRINT_TYPE(ptr);
    PRINT_TYPE(*ptr);
    printf("\n");
    PRINT_TYPE2(my_int_array); 
    PRINT_TYPE2(my_str);
    PRINT_TYPE2(ptr);
    PRINT_TYPE2(*ptr);

    return 0;
}


