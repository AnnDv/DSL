#ifndef DSL_PARSER_H
#define DSL_PARSER_H
#include<iostream>

using namespace std;

enum token {
    TT_SEP, // ;
    TT_KEY, //KEYWORD
    TT_VALUE, //VALUE
    TT_OUT, //OUTPUT
    TT_LEFTPARENT, // (
    TT_RIGHTPARENT, // )
    TT_IGN, //TBIGNORED
};
bool parser(vector <token> vecOfElements);

int isKeyword(char buffer[]);

#endif //DSL_PARSER_H
