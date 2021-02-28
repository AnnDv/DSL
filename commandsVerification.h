#ifndef DSL_COMMANDSVERIFICATION_H
#define DSL_COMMANDSVERIFICATION_H

#include <string>
#include <iostream>
using namespace std;


bool is_push_command(string input);
bool is_pop_command(string input);
bool is_top_command(string input);
bool is_empty_command(string input);

#endif
