#include "printmap.hpp"


#include <iostream>


void printMap(const std::map<std::string, int>& namedValues)
{
    std::cout << "{\n";
    for (auto&& [name, value]: namedValues)
    {
        std::cout << "\t'" << name << "': " << value << ",\n";
    }
    std::cout << "}\n";
}
