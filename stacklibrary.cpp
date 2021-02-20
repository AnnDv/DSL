#include "stacklibrary.h"
#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<int> s; //creates an empty stack of integer s

void stacklibrary(string input){

    string push_command = "push()";
    string pop_command = "pop()";
    string empty_command = "empty()";
    string top_command = "top()";

    bool is_command = false;

// pop command
    if (input == pop_command)
        s.pop();
    else
        cout << "Error" << endl;

    char temp[256] = "";
    for (int i = 0; i < input.size(); i++) {
        while (input[i] = '('){
            temp[i] = input[i];
            i++;
        }
        continue;
    }

//push command
    char value[256] = "";
    if (temp == push_command)
        is_command = true;

    if (is_command){
        for(int i = 0, j = 0; i < input.size(); i++) {
            if (input[i] == '(') {
                i++;
                while (input[i] != ')') {
                    value[j] = input[i];
                    i++, j++;
                }
            }
            continue;
        }
        s.push((int)value[0] - 48);
    }

//top command
    if (input == top_command)
        s.top();
    else
        cout << "Error" << endl;

//empty command
    if (input == empty_command)
        s.empty();
    else
        cout << "Error" << endl;

}