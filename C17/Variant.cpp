#include <iostream>
#include <string>
#include <variant>

template<typename... Functors>
struct Ovld: Functors... {
    using Functors::operator()...;  //derive op() from all functors
};

//deduce template arguments from initializers
template<typename... Functors> Ovld(Functors...) -> Ovld<Functors...>;


int main() 
{
    // S(int) a;
    auto overloadFunctions = Ovld{[](int){
        std::cout << "this is int" <<  '\n';
    },
    [](std::string){
        std::cout << "this is string" << '\n';
    }};


   std::variant<int, std::string> vec = 1;
    std::visit(overloadFunctions, vec);
    return 0;
}
