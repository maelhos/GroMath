#include "utils.h"

std::string parseStrSpecialChars(std::string s){
    static const std::map<std::string, std::string> specialReplace = {
        {"\\\\", "\\"},
        {"\\'", "'"},
        {"\\\"", "\""},
        {"\\n", "\n"},
        {"\\r", "\r"},
        {"\\t", "\t"}
    };
    for (auto &&[first, second] : specialReplace)
        while (s.find(first) != std::string::npos)
            s.replace(s.find(first), first.length(), second);
    return s;
}