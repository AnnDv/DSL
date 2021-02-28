#include "entryDictionary.h"
#include <iostream>
#include <string>

using namespace std;

bool entry(string input){
    char start = '_';
    if (input.find(start) < 20) {
        bool is_end = false, is_parameter = false, is_create_command = false;
        bool are_brackets = false;
        string create_command = "create";
        string stack_parameter = "stack";

        if (input.size() - 1 == input.find(';'))
            is_end = true;

        if ((input.find('(') and input.find(')')) < input.size())
            are_brackets = true;

        char temp[100] = "";
        for(int i = 0; i < input.size(); i++) {
            if (input[i] != '_')
                temp[i] = input[i];
            else
                break;
        }
        if (temp == create_command)
            is_create_command = true;

        char parse[100] = "";
        for (int i = input.find('_') + 1, j = 0; i <= input.size(); ++i) {
            if (input[i] == '(')
                break;

            else {
                parse[j] = input[i];
                j++;
            }
        }
        if (parse == stack_parameter)
            is_parameter = true;

        if (is_end) {
            if (are_brackets) {
                if (is_create_command) {
                    if (is_parameter)
                        return true;
                    else{
                        cout << "Invalid parameter" << endl;
                        exit(0);
                    }
                }
                else{
                    cout << "Invalid command" << endl;
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
}
