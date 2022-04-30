#include "keywords.h"

    void keywords_count(std::string *line) {
    std::regex  const expression(R"###(\b(alignas|alignof|and_eq|and|asm|atomic_cancel|atomic_commit|atomic_noexcept|auto|bitand|bitor|bool|break|case|catch|char8_t|char16_t|char32_t|char|class|compl|concept|consteval|constexpr|constinit|const_cast|const|continue|co_await|co_return|co_yield|decltype|default|delete|double|do|dynamic_cast|else|enum|explicit|export|extern|false|float|for|friend|goto|if|inline|int|long|mutable|namespace|new|noexcept|not_eq|not|nullptr|operator|or_eq|or|private|protected|public|reflexpr|register|reinterpret_cast|requires|return|short|signed|sizeof|static_assert|static_cast|static|struct|switch|synchronized|template|this|thread_local|throw|true|try|typedef|typeid|typename|union|unsigned|using|virtual|void|volatile|wchar_t|while|xor_eq|xor)\b)###");
    std::sregex_iterator lineStart = std::sregex_iterator((*line).begin(), (*line).end(), expression);   
    std::sregex_iterator lineEnd = std::sregex_iterator();
    std::cout << "Keywords: " << std::distance(lineStart, lineEnd) << std::endl;
    }
