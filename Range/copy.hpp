#pragma once
#include <algorithm>

namespace Range
{
namespace
{
template <typename Iterator>
class CopyImpl
{
public:
    CopyImpl(Iterator p_iter) :
        m_iter(p_iter)
    {}

    template <typename Container>
    friend void operator | (const Container& p_container, const CopyImpl& p_impl)
    {
        std::copy(std::begin(p_container), std::end(p_container), p_impl.m_iter);
    }

private:
    Iterator m_iter;
};
}

#if __cplusplus >= 201703L      // C++17
template <typename Iterator>
class copy : public CopyImpl<Iterator>
{
    using CopyImpl<Iterator>::CopyImpl;
};

template <typename Iterator>
copy(Iterator) -> copy<Iterator>;

#else   // C++11/14

template <typename Iterator>
CopyImpl<Iterator> copy(Iterator p_iter)
{
    return CopyImpl<Iterator>(p_iter);
}

#endif
}