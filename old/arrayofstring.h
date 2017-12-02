#ifndef ARRAYOFSTRING_H
#define ARRAYOFSTRING_H 

#include <string.h>	/* size_t */

#define MAX_ARRAY_LENGTH 1024

struct ArrayOfStringData
{
	char elements[MAX_ARRAY_LENGTH];
	size_t length;
};

typedef
	struct ArrayOfStringData
	ArrayOfString;

void asInit(ArrayOfString *a);
void asAdd(ArrayOfString *a, char *element);
char *asGet(ArrayOfString *a, size_t elementIndex);
char *asPut(ArrayOfString *a, size_t elementIndex, char *element);
size_t asLength(ArrayOfString *a);

#endif
