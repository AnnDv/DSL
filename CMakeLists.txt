cmake_minimum_required(VERSION 3.17)
project(dsl)

set(CMAKE_CXX_STANDARD 14)

add_executable(dsl main.cpp stacklibrary.cpp stacklibrary.h commandsVerification.cpp commandsVerification.h entryDictionary.cpp entryDictionary.h Tokenizer.cpp Tokenizer.h ErrorHandler.cpp ErrorHandler.h parser.cpp parser.h)