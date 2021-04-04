#include "entryDictionary.h"
#include <iostream>
#include <string>

using namespace std;

bool entryCheck(string input) {
    string parameter = "stack";
    char p[100] = "";
    for(int i = 7, j = 0; i < input.size(); ++i) {
        if (input[i] == '(')
            break;
        else {
            p[j] = input[i];
            j++;
        }
    }
    if (p == parameter)
        return true;
    else {
        cout << "Invalid parameter!" << endl;
    }
}

bool checkCreateCommand(string input){
    string createCommand = "create";
    char temp[100] = "";
    for(int i = 0; i < input.length(); i++){
        if(input[i] != '_')
            temp[i] = input[i];
        else{
            break;
        }
    }
    if(temp == createCommand){
        if(entryCheck(input))
            return true;
        else {
            cout << "Invalid command!" << endl;
        }
    }
}

bool emptyBrackets(string input){
    if (input.find('(') + 1 == input.find(')')){
        if(checkCreateCommand(input))
            return true;
    }
    else{
        cout << "Unexpected value." << endl;
        exit(0);
    }
}
bool checkBrackets(string input){
    if(input.find('(') < input.size() and input.find(')') < input.size()) {
        if(emptyBrackets(input))
            return true;
        else{
            cout << "Expected brackets." << endl;
        }
    }
}

bool checkSemicolon(string input) {
    char end = ';';
    if(input.find(end) == input.size() - 1) {
        if(checkBrackets(input)){
            return true;
        }
        else{
            cout << "Semicolon is missing!" << endl;
            exit(0);
        }
    }
}

bool startCheck(string input) {
    char s = '_';
    if(input.find(s) < 20) {
        if(checkSemicolon(input)){
            return true;
        }
        else {
            cout << "Expected \'_\'" << endl;
        }
    }
}