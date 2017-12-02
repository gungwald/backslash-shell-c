#ifndef ARRAYLISTOFSTRING_H
#define ARRAYLISTOFSTRING_H

#include <string.h>
#include <stdbool.h>

struct ArrayListOfStringData
{
	size_t capacity;
	size_t size;
	char **elements;
};

typedef
	struct ArrayListOfStringData *
	ArrayListOfString;

extern ArrayListOfString new_ArrayListOfString();
extern void alosFree(ArrayListOfString a);
extern void alosAdd(ArrayListOfString a, char *s);
extern size_t alosSize(ArrayListOfString a);
extern void alosClear(ArrayListOfString a);
extern bool alosIsEmpty(ArrayListOfString a);
extern char *alosGet(ArrayListOfString a, size_t index);
extern void alosSet(ArrayListOfString a, size_t index, char *s);
extern char *alosRemove(ArrayListOfString a, size_t index);

#endif
