#include <gc.h>

#include "ArrayListOfString.h"

#define INITIAL_CAPACITY 16

static void ensureCapacity(ArrayListOfString a, size_t size);

ArrayListOfString new_ArrayListOfString()
{
    ArrayListOfString a = (ArrayListOfString) GC_MALLOC(sizeof(struct ArrayListOfStringData));
    a->capacity = INITIAL_CAPACITY;
    a->size = 0;
    a->elements = (char **) GC_MALLOC(sizeof(char *) * a->capacity);
    return a;
}

void alosFree(ArrayListOfString a)
{
    for (size_t i = 0; i < a->size; i++) {
        if (a->elements[i] != NULL) {
            GC_FREE(a->elements[i]);
        }
    }
    GC_FREE(a->elements);
    GC_FREE(a);
}

void ensureCapacity(ArrayListOfString a, size_t size)
{
    while (a->capacity < size) {
        a->capacity *= 2;
    }
    a->elements = (char **) GC_REALLOC(a->elements, sizeof(char *) * a->capacity);
}

void alosAdd(ArrayListOfString a, char *s)
{
    ensureCapacity(a, a->size + 1);
    a->elements[a->size] = s;
    (a->size)++;
}

size_t alosSize(ArrayListOfString a)
{
    return a->size;
}

void alosClear(ArrayListOfString a)
{
    for (size_t i = 0; i < a->size; i++) {
        if (a->elements[i] != NULL) {
            GC_FREE(a->elements[i]);
        }
    }
    a->size = 0;
}

bool alosIsEmpty(ArrayListOfString a)
{
    return a->size == 0;
}

char *alosGet(ArrayListOfString a, size_t index)
{
    return a->elements[index];
}

void alosSet(ArrayListOfString a, size_t index, char *s)
{
    a->elements[index] = s;
}

char *alosRemove(ArrayListOfString a, size_t index)
{
    char *element = a->elements[index];
    for (size_t i = index + 1; i < a->size; i++) {
        a->elements[i - 1] = a->elements[i];
    }
    (a->size)--;
    return element;
}

