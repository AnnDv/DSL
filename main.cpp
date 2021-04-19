#include <iostream>
#include <string>
#include <fstream>
#include "stacklibrary.h"
#include "entryDictionary.h"
#include "Tokenizer.h"

using namespace std;
using namespace parser;

int main() {

    string input;
    string path = "/Users/anadvorac/Documents/FAF/anul 2/dsl/input.txt";

    fstream file;
    file.open(path);
    getline(file, input);
    if (startCheck(input))
        while(true){
            getline(file, input);
            stacklibrary(input);
        }
//    cout<<input;
    file.close();

//    if (input == get_stack)
//        stacklibrary(input);

    return 0;

}
