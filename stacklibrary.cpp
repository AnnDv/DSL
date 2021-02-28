#include "stacklibrary.h"
#include "commandsVerification.h"
#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<int> s; //creates an empty stack of integer s

void stacklibrary(string input) {

    string push_command = "push()";
    string pop_command = "pop()";
    string empty_command = "empty()";
    string top_command = "top()";

    char temp[200] = "";

    // push and pop commands
    if (input[0] == 'p') {
//        bool is_command_push = false;
//        bool is_command_pop = false;
        char temp_push[256] = "";
        char value[256] = "";

        for (int i = 0; i < input.size(); i++) {
            while (input[i] != '(') {
                temp_push[i] = input[i];
            }
            continue;
        }
        if (input == push_command){
            for (int i = 0, j = 0; i < input.size(); i++) {
                if (input[i] == '(') {
                    i++;
                    while (input[i] != ')') {
                        value[j] = input[i];
                        i++;
                        j++;
                    }
                }
            }
            s.push((int) value[0] - 48);
        }
        else if(input == pop_command)
            s.pop();

        if (is_pop_command(input)) {
            string command = "pop";
            for (int i = 0; i < input.size(); i++) {
                if (input[i] == '(')
                    break;
                else
                    temp[i] = input[i];
            }
            if (temp == command) {
                return;
            } else {
                cout << "Invalid command";
                exit(0);
            }
        }
        if(is_push_command(input)){
            string command = "push";
            for (int i = 0; i < input.size(); i++) {
                if (input[i] == '(')
                    break;
                else
                    temp[i] = input[i];
            }
            if (temp == command) {
                return;
            } else {
                cout << "Invalid command";
                exit(0);
            }
        }
    }

//top command
    if (input[0] == 't' && is_top_command(input)) {
        string command = "top";
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '(')
                break;
            else
                temp[i] = input[i];
        }
        if (temp == command) {
            cout << s.top();
            return;
        } else {
            cout << "Invalid command";
            exit(0);
        }
    }

//empty command
    if (input[0] == 'e') {
        if (is_empty_command(input)) {
            string command = "empty";
            for (int i = 0; i < input.size(); i++) {
                if (input[i] == '(')
                    break;
                else
                    temp[i] = input[i];
            }
            if (temp == command) {
                cout << s.empty();
                return;
            } else {
                cout << "Invalid command";
                exit(0);
            }
        }
    }
}