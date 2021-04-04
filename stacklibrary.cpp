#include "stacklibrary.h"
#include "commandsVerification.h"
#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<int> s; //creates an empty stack of integer s

enum stackCommands {push_command, pop_command, empty_command, top_command};

void stacklibrary(string input) {
    int command;
    command = analyzeInput(input);

    switch (command) {
        case push_command:{
            char temp [256] = " ";
            for (int i = 0,j=0; i < input.length(); ++i) {
                if(input[i]=='('){
                    ++i;
                    while (input[i]!=')'){
                        temp[j] = input[i];
                        ++i;
                        ++j;
                    }
                }
            }
            int value = atoi(temp);
            cout<<"Value: ["<<value<<"]"<<endl;
            s.push(value);
            break;
        }
        case pop_command:{
            s.pop();
        }
        case empty_command:{
            s.empty();
        }
        case top_command:{
            s.top();
        }
    }
}