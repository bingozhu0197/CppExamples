#include <typeinfo>       // operator typeid
#include <iostream>

template <typename T>
void printTypeName(T)
{
  std::cout << "type is: " << typeid(T).name() << '\n';
}