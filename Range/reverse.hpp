#pragma once
#include <algorithm>

namespace Range
{
namespace
{
class reverse
{
    template <typename Container>
    friend Container& operator | (Container& p_container, const reverse& p_reverse)
    {
        std::reverse(std::begin(p_container), std::end(p_container));
        return p_container;
    }
};
}

reverse reversed;
}