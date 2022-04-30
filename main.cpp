#include <iostream>
#include <fstream>
#include <sstream>
#include "keywords/keywords.h"
#include "variables/variables.h"
#include "functions/functions.h"


int main() {
std::ifstream code_file("input.txt");
std::stringstream buffer;
buffer << code_file.rdbuf();
std::string content = buffer.str();
keywords_count(&content);
variables_count(&content);
functions_count(&content);
}