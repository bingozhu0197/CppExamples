#pragma once
#include <algorithm>
#include "for_each.hpp"

namespace Range
{
namespace
{
template <typename Function>
class fmapImpl
{
public:
    fmapImpl(Function p_fn) :
        m_fn(std::move(p_fn))
    {}

    template <typename Container>
    friend Container& operator | (Container& p_container, const fmapImpl& p_fmap)
    {
        std::for_each(std::begin(p_container), std::end(p_container), p_fmap.m_fn);
        return p_container;
    }

    template <typename Container>
    friend const Container& operator | (const Container& p_container, const fmapImpl& p_fmap)
    {
        std::for_each(std::begin(p_container), std::end(p_container), p_fmap.m_fn);
        return p_container;
    }

private:
    Function m_fn;
};
}

#if __cplusplus >= 201703L      // C++17

template <typename Function>
class fmap : public fmapImpl<Function>
{
    using fmapImpl<Function>::fmapImpl;
};

template <typename Function>
fmap(Function) -> fmap<Function>;

#else   // C++11/14

template <typename Function>
fmapImpl<Function> fmap(Function p_function)
{
    return fmapImpl<Function>(std::move(p_function));
}

#endif
}