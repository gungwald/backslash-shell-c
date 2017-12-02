#include <stdio.h>	/* perror */
#include <stdlib.h>	/* EXIT_FAILURE */
#include <gc.h>
#include "StringBuilder.h"

#define DEFAULT_INITIAL_CAPACITY 64

static void ensureCapacity(StringBuilder s, size_t length);

StringBuilder new_StringBuilder(const char *s)
{
    StringBuilder sb = (StringBuilder) GC_MALLOC(sizeof(struct StringBuilderData));

    if (sb == NULL) {
        perror("GC_MALLOC");
        exit(EXIT_FAILURE);
    }
    else {
        if (s == NULL) {
            sb->length = 0;
        }
        else {
            sb->length = strlen(s);
        }

        if (sb->length == 0) {
            sb->capacity = DEFAULT_INITIAL_CAPACITY;
        }
        else {
            sb->capacity = sb->length + 1;
        }

        sb->characters = (char *) GC_MALLOC(sizeof(char) * sb->capacity);
        if (sb->length > 0) {
            strcpy(sb->characters, s);
        }
    }
    return sb;
}

void ensureCapacity(StringBuilder s, size_t length)
{
    size_t requiredCapacity = length + 1;
    while (s->capacity < requiredCapacity) {
        s->capacity *= 2;
    }
    s->characters = (char *) GC_REALLOC(s->characters, sizeof(char) * requiredCapacity);
}


void sbFree(StringBuilder s)
{
    GC_FREE(s->characters);
    GC_FREE(s);
}

void sbAppend(StringBuilder s, const char *t)
{
    size_t combinedLength = s->length + strlen(t);
    ensureCapacity(s, combinedLength);
    strcat(s->characters, t);
    s->length = combinedLength;
}

void sbAppendChar(StringBuilder s, char c)
{
    size_t combinedLength = s->length + 1;
    ensureCapacity(s, combinedLength);
    s->characters[combinedLength - 1] = c;
    s->characters[combinedLength] = '\0';
    s->length = combinedLength;
}

char *sbToString(StringBuilder s)
{
    return s->characters;
}

char sbCharAt(StringBuilder s, size_t index)
{
    char c;
    if (index < s->length) {
        c = s->characters[index];
    }
    return c;
}

char *sbHarvest(StringBuilder sb)
{
    char *s = sb->characters;
    GC_FREE(sb);
    return s;
}

