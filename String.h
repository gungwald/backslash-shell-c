#ifndef BACKSLASH_SHELL_STRING_H
#define BACKSLASH_SHELL_STRING_H

typedef
    char *
    String;

extern String sFreeIfEmpty(String s);
extern String sReplace(String s, char find, char replace);
extern String sToLowerCase(String s);

#endif
