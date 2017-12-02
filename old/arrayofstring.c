#include <stdio.h>

#include "arrayofstring.h"

void asInit(ArrayOfString *a)
{
    a->length = 0;
}

void asAdd(ArrayOfString *a, char *element)
{
    if (a->length < MAX_ARRAY_LENGTH) {
        a->elements[a->length++] = element;
    }
    else {
        fprintf(stderr, "ArrayIndexOutOfBoundsException: %d\n", MAX_ARRAY_LENGTH);
    }
}

char *asGet(ArrayOfString *a, size_t elementIndex)
{
    char *element = NULL;

    if (elementIndex >= a->length) {
        fprintf(stderr, "ArrayIndexOutOfBoundsException: %d\n", elementIndex);
    }
    else {
        element = a->elements[elementIndex];
    }
    return element;
}

void asPut(ArrayOfString *a, size_t elementIndex, char *element)
{
    if (elementIndex < a->length) {
        a->elements[elementIndex] = element;
    }
    else if (elementIndex == a->length && a->length < MAX_ARRAY_LENGTH) {
        a->elements[elementIndex] = element;
        a->length++;
    }
    else {
        fprintf(stderr, "ArrayIndexOutOfBoundsException: %d\n", elementIndex);
    }
}

size_t asLength(ArrayOfString *a)
{
    return a->length;
}

