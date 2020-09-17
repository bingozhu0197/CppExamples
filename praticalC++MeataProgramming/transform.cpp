#include <memory>

template<template<class...> class MetaFunction>
struct lambda
{

template<typename ...Args> 
struct apply
{
using type = typename MetaFunction<Args...>::type;
};
};

template<typename List, typename F> struct transform;

template<template<class...> class List, typename ...Elems, typename F>
struct transform<List<Elems...>, F>
{
template<typename T>    
using call = typename F::template apply<T>::type;
    
using type = List< call<Elems>... >;
};

int main()
{
 using no_pointers = transform<std::tuple<int*,float**, double>
, lambda<std::remove_pointer>
>::type;
    
    static_assert(std::is_same_v<no_pointers, std::tuple<int, float*, double>>);
    
    return 0;
}
