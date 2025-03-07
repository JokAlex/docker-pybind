#include "doublelistoperator.hpp"


#include <algorithm>
#include <numeric>


void DoubleListOperator::map(const std::function<double(double)>& function)
{
    std::transform(data.begin(), data.end(), data.begin(), function);
}


double DoubleListOperator::reduce(double init, const std::function<double(double, double)>& func) const
{
    return std::accumulate(data.begin(), data.end(), init, func);
}