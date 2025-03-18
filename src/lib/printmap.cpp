#include "printmap.hpp"


#include <iostream>


void printMap(const std::map<std::string, int>& namedValues, std::ostream& stream)
{
    stream << "{\n";
    for (auto&& [name, value]: namedValues)
    {
        stream << "\t'" << name << "': " << value << ",\n";
    }
    stream << "}\n";
}
