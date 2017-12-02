#ifndef STRINGBUILDER_H
#define STRINGBUILDER_H

#include <string.h>	/* size_t */

struct StringBuilderData
{
	char *characters;
	size_t length;
	size_t capacity;
};

typedef
	struct StringBuilderData *
	StringBuilder;

extern StringBuilder new_StringBuilder(const char *s);
extern void sbFree(StringBuilder s);
extern void sbAppend(StringBuilder s, const char *t);
extern void sbAppendChar(StringBuilder s, char c);
extern char *sbToString(StringBuilder s);
extern char sbCharAt(StringBuilder s, size_t index);
extern char *sbHarvest(StringBuilder sb);

#endif
