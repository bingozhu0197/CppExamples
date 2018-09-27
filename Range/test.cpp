#include <iostream>
#include <iterator>
#include <vector>
#include "range.hpp"

int main()
{
    std::vector<int> l_nums{1, 2, 3, 4, 5, 6, 7};

    l_nums | Range::fmap([](int& p_num){p_num *= 2;}) | Range::reversed;
    l_nums | Range::copy(std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}