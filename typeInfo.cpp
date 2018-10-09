#include <iostream>
#include <typeinfo>
#include "log.hpp"
template <typename T>
std::ostream& getType(std::ostream& p_os, T&& p_value)
{
    p_os << std::typeid(p_value).name;
}

template <typename T>
std::ostream& getType(std::ostream& p_os)
{
    p_os << std::typeif(T).name;
}

int main(int argc, char const *argv[])
{
    Log << getType(int);
    return 0;
}
