#include <iostream>

struct Test
{
    Test(int p_val) : val(p_val)
    {
        std::cout << "Test c-tor: " << p_val;
    }

    int val;
};

class Foo
{
public:
    Foo(): m_a(0)
    {
        std::cout << "a:" << m_a.val << " b:" << m_b << std::endl;
        m_b = 3;
    }
private:
    Test m_a{9};
    int m_b = 10;
};

int main(int argc, char const *argv[])
{
    Foo l_f;
    return 0;
}
