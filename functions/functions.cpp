#include "functions.h"

void functions_count(std::string *file) {
    std::regex  const expression(R"###(\w+\s+\w+(\s?)+\((\s?|[\s\S]?|(\w|,)+)+\))###", std::regex::icase);
    std::regex const functionNameExpression(R"###(\w+[^(,)]+\()###", std::regex::icase);
    std::regex const function_argument(R"###(\w+[,)\n\r])###");
    auto fileStart = std::sregex_iterator((*file).begin(), (*file).end(), expression);
    auto fileEnd = std::sregex_iterator();

    std::string functions = "Function arguments: \n";
    for (auto i = fileStart; i != fileEnd; ++i) {
        std::smatch functionMatch = *i;
        std::string functionMatchStr = functionMatch.str();
    
        auto nameStart = std::sregex_iterator(functionMatchStr.begin(), functionMatchStr.end(), functionNameExpression);    
        auto nameEnd = std::sregex_iterator();
        auto argsStart = std::sregex_iterator(functionMatchStr.begin(), functionMatchStr.end(), function_argument);
        auto argsEnd = std::sregex_iterator();
        std::smatch nameMatch = *nameStart;
        std::string funcName = nameMatch.str() + ")";
        functions +=  "function :" + funcName + " " + std::to_string(std::distance(argsStart, argsEnd)) +" arguments \n";
    }
        std::cout << "Functions: " << std::distance(fileStart, fileEnd) << std::endl;
        std::cout  << std::endl << functions << std::endl;


    
}
