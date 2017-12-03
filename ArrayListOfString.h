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
extern void alsFree(ArrayListOfString a);
extern void alsAdd(ArrayListOfString a, char *s);
extern size_t alsSize(ArrayListOfString a);
extern void alsClear(ArrayListOfString a);
extern bool alsIsEmpty(ArrayListOfString a);
extern char *alsGet(ArrayListOfString a, size_t index);
extern void alsSet(ArrayListOfString a, size_t index, char *s);
extern char *alsRemove(ArrayListOfString a, size_t index);

#endif
