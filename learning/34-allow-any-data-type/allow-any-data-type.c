#include <stdio.h>

/*
• data: A generic pointer (typically void*) that holds a memory address.
• (int*): A type cast that tells the compiler to treat data as a pointer to an integer instead of a generic or different type.
• *(int*): The dereference operator (*) goes to that memory address and reads the integer value stored there.
*/

typedef enum { TYPE_INT, TYPE_FLOAT, TYPE_CHAR } DataType;

void printValue(void* data, DataType type) {
    switch(type) {
        case TYPE_INT:
            printf("Integer: %d\n", *(int*)data); // Cast to int* and dereference
            break;
        case TYPE_FLOAT:
            printf("Float: %.2f\n", *(float*)data); // Cast to float* and dereference
            break;
        case TYPE_CHAR:
            printf("Char: %c\n", *(char*)data);   // Cast to char* and dereference
            break;
    }
}

int main() {
    int i = 42;
    float f = 3.14;
    char c = 'A';

    printValue(&i, TYPE_INT);
    printValue(&f, TYPE_FLOAT);
    printValue(&c, TYPE_CHAR);
    return 0;
}
