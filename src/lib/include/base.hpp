#pragma once


#include <string>


class Base
{
public:
    virtual ~Base() = default;

    std::string greet() const {return "Hello from Base";}
    virtual std::string virtualMethod() const {return "Virtual method in Base";}
    static std::string staticMethod() {return "Static method";}
};
