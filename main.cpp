#include <iostream>
#include <string>
#include <fstream>
#include "stacklibrary.h"

using namespace std;

int main() {

    string input;
    string path = "/Users/anadvorac/Documents/FAF/anul 2/dsl/input.txt";
    string get_stack = "create_stack";

    fstream file;
    file.open(path);
    getline(file, input);
//    cout<<input;
    file.close();

    if (input == get_stack)
        stacklibrary(input);

    return 0;

}
