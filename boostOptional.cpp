#include <iostream>
#include <boost/optional.hpp>

struct Foo
{
	int a[100];
};

int main()
{
	std::cout << sizeof(boost::optional<Foo>) << std::endl;
	return 0;
}