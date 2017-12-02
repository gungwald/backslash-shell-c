/*
 * tokenizer.h
 *
 *  Created on: Nov 25, 2017
 *      Author: bill
 */

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "String.h"

struct TokenizerData
{
    String text;
    size_t index;
    size_t length;
};

typedef
    struct TokenizerData *
    Tokenizer;

extern Tokenizer new_Tokenizer(const String s);
extern String tkGetToken(Tokenizer t);
extern void tkFree(Tokenizer t);

#endif /* TOKENIZER_H */
