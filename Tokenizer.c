/*
 * Tokenizer.c
 *
 *  Created on: Nov 25, 2017
 *      Author: bill
 */

#include <string.h>		/* strlen */
#include <stdbool.h>
#include <ctype.h>		/* isspace */

#include <gc.h>

#include "StringBuilder.h"
#include "Tokenizer.h"

bool isTokenChar(char c);

Tokenizer new_Tokenizer(const String text)
{
    Tokenizer t = (Tokenizer) GC_MALLOC(sizeof(struct TokenizerData));
    t->text = text;
    t->index = 0;
    t->length = strlen(text);
    return t;
}

String tkGetToken(Tokenizer t)
{
    bool tokenStarted = false;
    bool tokenFinished = false;
    StringBuilder token = new_StringBuilder("");

    while (t->index < t->length && !tokenFinished) {
        char c = t->text[t->index];
        if (isTokenChar(c)) {
            sbAppendChar(token, c);
            tokenStarted = true;
            t->index++;
        }
        else if (tokenStarted) {
            tokenFinished = true;
        }
        else {
            t->index++;
        }
    }
    return sbHarvest(token);
}

bool isTokenChar(char c)
{
    return ! isspace(c);
}
