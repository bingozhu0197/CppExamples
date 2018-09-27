#include <iostream>

class Foo
{
public:
    Foo(): m_a(0){
        std::cout << "a:" << m_a << " b:" << m_b << std::endl;
        m_b = 3;
    }
private:
    int m_a{9};
    int m_b = 10;
};

int main(int argc, char const *argv[])
{
    Foo l_f;
    return 0;
}
