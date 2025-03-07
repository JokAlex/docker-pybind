#pragma once


#include "base.hpp"


class Derived : public Base 
{
public:
    std::string virtualMethod() const override {return "Overridden method in Derived";}
};
