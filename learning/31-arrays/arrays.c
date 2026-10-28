#include <stdio.h>
#include <stdbool.h>

// Define reusable macros
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))
#define DEFINE_ARRAY_DELETE_FUNCTIONS(TYPE, NAME) \
TYPE delete##NAME(TYPE arr[], int pos, size_t *length) { \
    int deletedValue = arr[pos]; \
    for (int i=pos; i<*length - 1; i++) { \
        arr[i] = arr[i+1]; \
    } \
    (*length)--; \
    return deletedValue; \
} \

#define DEFINE_ARRAY_INSERT_FUNCTIONS(TYPE, NAME) \
void insert##NAME(TYPE arr[], int pos, TYPE val, size_t *length) { \
    for (int i=*length; i>pos; i--) { \
        arr[i] = arr[i-1]; \
    } \
    arr[pos] = val; \
    (*length)++; \
} \

// The compiler auto-generates: deleteInt() and deleteChar()
DEFINE_ARRAY_DELETE_FUNCTIONS(int, Int)
DEFINE_ARRAY_DELETE_FUNCTIONS(char, Char)

// The compiler auto-generates: insertInt() and insertChar()
DEFINE_ARRAY_INSERT_FUNCTIONS(int, Int)
DEFINE_ARRAY_INSERT_FUNCTIONS(char, Char)

/* 
// THE GENERIC COMPILE-TIME ROUTER
// The macro checks the data type of the array pointer and swaps the call out.
#define printArray(ARR, LENGTH) _Generic((ARR), \
    char*: printArrayChar,                      \
    const char*: printArrayChar,                \
    int*: printArrayInt,                        \
    const int*: printArrayInt                   \
)(ARR, LENGTH) // <- The actual arguments are passed into the matched function

*/

void printArrayInt(const int arr[], size_t length) {
    for (int i=0; i < length; i++) printf("%d->", arr[i]);
    printf("\n");
}

void printArrayChar(const char arr[], size_t length) {
    for (int i=0; i < length; i++) printf("%c->", arr[i]);
    printf("\n");
}

bool deleteCharacterByValue(char arr[], char value, size_t *length) {
    for (int i=0; i<=*length-1; i++) {
        if (arr[i] == value) {
            if (i < *length-1) {
                for (int j=i; j<*length-1; j++) {
                    arr[j] = arr[j+1];
                }
            }
            (*length)--;
            return true;
        }
    };
    return false;
}

int main() {
    int numbers[] = {10, 20, 30, 40, 50}; // dynamic array
    size_t numLength = ARRAY_LENGTH(numbers);
    printArrayInt(numbers, numLength);

    char grades[5] = {'A', 'B', 'C', 'D', 'E'}; //fixed array
    size_t charLength = ARRAY_LENGTH(grades);    
    printArrayChar(grades, charLength);

    // // insertion
    int valueToBeInserted = 25;
    int position1 = 2;
    insertInt(numbers, position1, valueToBeInserted, &numLength);
    printArrayInt(numbers, numLength);

    // // deletion by position
    int position2 = 3;
    int deletedValue = deleteInt(numbers, position2, &numLength);
    printf("The deleted value is: %d\n", deletedValue);
    printArrayInt(numbers, numLength);

    // // deletion by character
    char valueToBeDeleted = 'C';
    if (deleteCharacterByValue(grades, valueToBeDeleted, &charLength)) {
        printf("The deleted value is: %c\n", valueToBeDeleted);
    } else {
        printf("%c not found!\n", valueToBeDeleted);
    };
    printArrayChar(grades, charLength);

    

    printf(_Generic(grades));

    return 0;
}