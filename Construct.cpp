#include <iostream>
#include "log.hpp"

struct Test
{
    Test(int p_val) : value(p_val)
    {
        Log << "Test c-tor: " << p_val;
    }

    int value;
};

class Foo
{
public:
    //Testing initilaze list and default initilization only initialized once.
    Foo(): m_a(0)
    {
        Log << "a:" << m_a.value << ", b:" <<  m_b.value;
    }
private:
    Test m_a{9};
    Test m_b = 10;
};

int main(int argc, char const *argv[])
{
    Foo l_f;
    return 0;
}
