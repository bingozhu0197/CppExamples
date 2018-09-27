#pragma once
#include <algorithm>

namespace Range
{
template <class Container, class Function>
Function for_each(Container& p_containter, Function fn)
{
    return std::for_each(std::begin(p_containter), std::end(p_containter), fn);
}

template <class Container, class Function>
Function for_each(const Container& p_containter, Function fn)
{
    return std::for_each(std::begin(p_containter), std::end(p_containter), fn);
}
}