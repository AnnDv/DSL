#include "commandsVerification.h"
#include <string>
#include <iostream>

using namespace std;

bool semicolonCheck(string input) {
    char end = ';';
    if(input.find(end) == input.size() - 1)
        return true;
    else{
        cout << "Expected \';\'" << endl;
    }
}

bool bracketsCheck(string input){
    if (input.find('(') < input.size() and input.find(')') < input.size())
        return true;
    else
        return false;
}

bool bracketsWriting(string input) {
    bool are_empty_brackets = false;
    bool brackets = bracketsCheck(input);
    if (brackets){
        if (input.find('(') + 1 == input.find(')'))
            are_empty_brackets = true;
    }
    if(brackets) {
        if (are_empty_brackets) {
            return true;
        } else {
            cout << "Unexpected value in brackets" << endl;
        }
    }
    else{
        cout << "Expected brackets" << endl;
    }
}

int pushCommand(string input) {
    char temp[100] = "";
    string push_command = "push";
    for(int i = 0; i < input.size(); ++i){
        if(input[i] == '('){
            break;
        }
        else
            temp[i] = input[i];
    }
    if(temp == push_command) {
        return 6;

    }
    else {
        cout << "Invalid command" << endl;
    }
}
//
int popCommand(string input) {
    char temp[100] = "";
    string pop_command = "pop";
    for(int i = 0; i < input.size(); ++i){
        if(input[i] == '('){
            break;
        }
        else
            temp[i] = input[i];
    }
    if(temp == pop_command) {
        if(semicolonCheck(input) and bracketsCheck(input)){
            return 5;
        }
    }
    else {
        cout << "Invalid command" << endl;
    }
}

bool map(string input, string command){
    if(semicolonCheck(input)){
        if(bracketsWriting(input)){
            char temp[100] = "";
            for(int i = 0; i < input.size(); i++){
                if(input[i] == '(')
                    break;
                else
                    temp[i] = input[i];
            }
            if(temp == command){
                return true;
            }
            else{
                cout << "Invalid command" << endl;
                exit(0);
            }
        }
    }
}

bool pushCom(string input){
    if(semicolonCheck(input)){
        bool brackets = bracketsCheck(input);
        bool contains_value = false;

        if (brackets){
            if (input.find('(') < input.find(')') - 1)
                contains_value = true;
        }
        if(brackets) {
            if (contains_value) {
                return true;
            } else {
                cout << "Expected value in brackets" << endl;
                exit(0);
            }
        }
        else{
            cout << "Expected brackets" << endl;
            exit(0);
        }
    }
    else{
        cout << "Expected \';\'" << endl;
        exit(0);
    }
}

int analyzeInput(string input){
    if(input[0] == 't'){
        if(map(input, "top"))
            return 1;
    }
    else if(input[0] == 'e'){
        if(map(input, "empty"))
            return 3;
    }
    else if(input[0] == 'p'){

        int push = pushCommand(input);
        int pop = popCommand(input);
        if(push == 5 or pop == 5)
            return 5;

        else if(push == 6 or pop == 6){
            if(pushCom(input)){
                return 6;
            }
        }
    }
    else{
        cout << "Invalid command" << endl;
    }
}
