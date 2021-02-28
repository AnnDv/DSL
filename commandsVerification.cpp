#include "commandsVerification.h"
#include <string>
#include <iostream>

using namespace std;

bool is_push_command(string input){
    char end = ';';
    if(input.find(end) == input.size() - 1){
        bool are_brackets = false;
        bool is_value = false;

        if ((input.find('(') and input.find(')')) < input.size())
            are_brackets = true;

        if (are_brackets){
            if (input.find('(') < input.find(')') - 1)
                is_value = true;
        }
        if(are_brackets) {
            if (is_value) {
                return true;
            } else {
                cout << "Expected a value or incorrect closing" << endl;
                exit(0);
            }
        }
        else{
            cout << "Expected brackets" << endl;
            exit(0);
        }
    }
    else{
        cout << "Missing a ';' at the end" << endl;
        exit(0);
    }
}

bool is_pop_command(string input){
    char end = ';';
    if(input.find(end) == input.size() - 1){
        bool are_brackets = false;

        if ((input.find('(') and input.find(')')) < input.size())
            are_brackets = true;

        if(are_brackets) {
            return true;
        }
        else{
            cout << "Expected brackets" << endl;
            exit(0);
        }
    }
    else{
        cout << "Missing a ';' at the end" << endl;
        exit(0);
    }
}

bool is_top_command(string input){
    char end = ';';
    if(input.find(end) == input.size() - 1){
        bool are_brackets = false;

        if ((input.find('(') and input.find(')')) < input.size())
            are_brackets = true;

        if(are_brackets) {
            return true;
        }
        else{
            cout << "Expected brackets" << endl;
            exit(0);
        }
    }
    else{
        cout << "Missing a ';' at the end" << endl;
        exit(0);
    }
}

bool is_empty_command(string input){
    char end = ';';
    if(input.find(end) == input.size() - 1){
        bool are_brackets = false;

        if ((input.find('(') and input.find(')')) < input.size())
            are_brackets = true;

        if(are_brackets) {
            return true;
        }
        else{
            cout << "Expected brackets" << endl;
            exit(0);
        }
    }
    else{
        cout << "Missing a ';' at the end" << endl;
        exit(0);
    }
}

