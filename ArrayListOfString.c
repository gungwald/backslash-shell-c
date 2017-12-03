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

void alsFree(ArrayListOfString a)
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

void alsAdd(ArrayListOfString a, char *s)
{
    ensureCapacity(a, a->size + 1);
    a->elements[a->size] = s;
    (a->size)++;
}

size_t alsSize(ArrayListOfString a)
{
    return a->size;
}

void alsClear(ArrayListOfString a)
{
    for (size_t i = 0; i < a->size; i++) {
        if (a->elements[i] != NULL) {
            GC_FREE(a->elements[i]);
        }
    }
    a->size = 0;
}

bool alsIsEmpty(ArrayListOfString a)
{
    return a->size == 0;
}

char *alsGet(ArrayListOfString a, size_t index)
{
    return a->elements[index];
}

void alsSet(ArrayListOfString a, size_t index, char *s)
{
    a->elements[index] = s;
}

char *alsRemove(ArrayListOfString a, size_t index)
{
    char *element = a->elements[index];
    for (size_t i = index + 1; i < a->size; i++) {
        a->elements[i - 1] = a->elements[i];
    }
    (a->size)--;
    return element;
}

