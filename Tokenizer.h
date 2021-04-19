#pragma once
#include <vector>
#include <string>

namespace parser {
    using namespace std;

    enum tokenType {
        WHITESPACE,
        IDENTIFIER,
        STRING_LITERAL,
        INTEGER_LITERAL,
        OPERATOR
    };

    static const char tokenTypeStrings[] = {
            "WHITESPACE",
            "IDENTIFIER",
            "STRING_LITERAL",
            "INTEGER_LITERAL",
            "OPERATOR"
    };

    class Token {
    public:
        enum tokenType mType{WHITESPACE};
        string mText;
        size_t mLineNumber{0};

        void debugPrint() const;
    };

    class Tokenizer{
    public:
        vector<Token> parse(const string &inProgram);

    private:
        void endToken(Token &token, vector<Token> &tokens);
    };
}

