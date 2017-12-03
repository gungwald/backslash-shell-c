#include <string.h>
#include <ctype.h>	/* tolower */
#include <gc.h>

#include "String.h"

String sFreeIfEmpty(String s)
{
	if (strlen(s) == 0) {
		GC_FREE(s);
		return NULL;
	}
	else {
		return s;
	}
}

/**
 * s is modified, unlike in Javer.
 */
String sReplace(String s, char find, char replace)
{
}

/**
 * s is modified, unlike in Javer.
 */
String sToLowerCase(String s)
{
	size_t len = strlen(s);
	for (size_t i = 0; i < len; i++) {
		s[i] = tolower(s[i]);
	}
	return s;
}
