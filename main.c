/*
 ============================================================================
 Name        : BackslashShellC.c
 Author      : Bill Chatfield
 Version     :
 Copyright   : GPL2
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>	/* getcwd */

#include <gc.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "String.h"
#include "ArrayListOfString.h"
#include "StringBuilder.h"
#include "Tokenizer.h"

#define MAX_PATH_LEN 2047
#define MAX_DRIVE_LEN 4

static String buildPrompt();
static ArrayListOfString parse(String line);
static int eval(ArrayListOfString args);
static String getCurrentDirectory();

static bool running = false;
static char drive[MAX_DRIVE_LEN + 1];
static int errorLevel;

int main(int argc, char *argv[])
{
    GC_INIT();
    strcpy(drive, "C:");
    running = true;

    while (running) {
        String line = readline(buildPrompt());
        errorLevel = eval(parse(line));
        free(line);
    }
    return errorLevel;
}

String getCurrentDirectory()
{
    size_t bufferSize = 64;
    char *cwd = (char *) GC_MALLOC(sizeof(char) * bufferSize);

    while (getcwd(cwd, bufferSize) == NULL) {
        bufferSize *= 2;
        GC_FREE(cwd);
        cwd = (char *) GC_MALLOC(sizeof(char) * bufferSize);
    }
    return cwd;
}

String buildPrompt()
{
    StringBuilder prompt = new_StringBuilder(drive);
    sbAppend(prompt, getCurrentDirectory());
    sbAppendChar(prompt, '>');
    return sbToString(prompt);
}

ArrayListOfString parse(String line)
{
    ArrayListOfString args = new_ArrayListOfString();
    Tokenizer tk = new_Tokenizer(line);
    String token;
    while ((token = tkGetToken(tk)) != NULL) {
        alosAdd(args, token);
    }
    return args;
}

int eval(ArrayListOfString args)
{
    return 0;
}
