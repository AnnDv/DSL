#include "Tokenizer.h"
#include <iostream>
#include <stdexcept>

namespace parser{

    using namespace std;

    vector<Token> Tokenizer::parse(const string &inProgram) {
        vector<Token> tokens;
        Token currentToken;

        currentToken.mLineNumber = 1;

        for (char currCh : inProgram) {
            switch (currCh) {
                case '(':
                case ')':
                case ';':
                    if (currentToken.mType != STRING_LITERAL) {
                        endToken(currentToken, tokens);
                        currentToken.mType = OPERATOR;
                        currentToken.mText.append(1, currCh);
                        endToken(currentToken, tokens);
                    }
                    else {
                        currentToken.mText.append(1, currCh);
                    }
                    break;

                case '\n':
                    endToken(currentToken, tokens);
                    ++currentToken.mLineNumber;
                    break;

                default:
                    if (currentToken.mType == WHITESPACE || currentToken.mType == INTEGER_LITERAL
                        || currentToken.mType == STRING_LITERAL) {
                        endToken(currentToken, tokens);
                        currentToken.mType = IDENTIFIER;
                        currentToken.mText.append(1, currCh);
                    } else {
                        currentToken.mText.append(1, currCh);
                    }
                    break;
            }
        }
        endToken(currentToken, tokens);
        return tokens;
    }

    void Tokenizer::endToken(Token &token, vector<Token> &tokens) {
        if (token.mType != WHITESPACE) {
            tokens.push_back(token);
        }
        token.mType = WHITESPACE;
        token.mText.erase();
    }

    void Token::debugPrint() const {
        cout << "Token(" << tokenTypeStrings[mType] << mLineNumber << ")" << endl;
    }

}