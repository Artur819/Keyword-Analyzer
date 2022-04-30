#include "variables.h"

void variables_count(std::string *line) {
std::regex const expression(R"###(((\w+\b::\b)?\w+\s+)+(\w+)(,|\w|\s)?(=)?(.+)?;)###", std::regex::icase);
auto lineStart = std::sregex_iterator((*line).begin(), (*line).end(), expression);            
auto lineEnd = std::sregex_iterator();
std::cout << "Variables: " << std::distance(lineStart, lineEnd) << std::endl;
}