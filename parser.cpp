#include "parser.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<vector>

using namespace std;

bool parser(vector <token> vecOfElements) {
    bool fileError = false;
    int openParanthese = 0;
    for (std::vector<int>::size_type i = 0; i != vecOfElements.size(); i++) {

        if (vecOfElements[vecOfElements.size() - 1] != TT_SEP) {
            cout << "\nSemicolon expected at the end";
            break;
        }

        switch (vecOfElements[i]) {
            case TT_VALUE:
                if ( vecOfElements[i + 1] == TT_VALUE) {
                    fileError = true;
                    cout << "\nVALUE error at ~ " << i + 1;
                }
                break;
            case TT_SEP:
                if (i == 0) {
                    fileError = true;
                    cout << "\nSEP error ~ " << i + 1;
                }
                break;
            case TT_LEFTPARENT:
                openParanthese++;
                break;
            case TT_RIGHTPARENT:
                if (openParanthese == 0) {
                    fileError = true;
                    cout << "\nPARANTHESE error" << i + 1;
                }
                else {
                    openParanthese--;
                }
                break;
            default:
                cout << "unexpected token" << i;
                fileError = true;
                break;
        }
        if (fileError == true) {
            return false;
        }
    }
    if (openParanthese != 0) {
        cout << "\nopen PARANTHESE error";
        return false;
    }
    return true;
}

int isKeyword(char buffer[]) {
    char keywords[][] = { "create", "draw", "stack", "push", "pop", "top", "empty"};
    int i, flag = 0;

    for (i = 0; i < 32; ++i) {
        if (strcmp(keywords[i], buffer) == 0) {
            flag = 1;
            break;
        }
    }
    return flag;
}