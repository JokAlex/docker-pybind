#pragma once


#include <vector>
#include <map>
#include <functional>


class DoubleListOperator final
{
    using ContainerType = std::vector<double>;

public:
    DoubleListOperator() = default;
    DoubleListOperator(const ContainerType& data): data(data) {}

    ContainerType::iterator begin() noexcept {return data.begin();}
    ContainerType::iterator end() noexcept {return data.end();}

    void map(const std::function<double(double)>& func);
    double reduce(double init, const std::function<double(double, double)>& func) const;

private:
    ContainerType data;
};
