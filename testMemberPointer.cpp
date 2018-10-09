#include <iostream>
#include <memory>

class Foo
{
public:
    int a;
};

void assignFoo(std::unique_ptr<Foo> p_foo, int Foo::*p_value, int value)
{
    p_foo->*p_value = value;
    std::cout << "assign value is " << p_foo.get()->*p_value;
}

int main(int argc, char *argv[])
{
    std::cout << "Hello world" << std::endl;
    auto f = std::make_unique<Foo>();
    assignFoo(std::move(f), &Foo::a, 10);
    return 0;
}