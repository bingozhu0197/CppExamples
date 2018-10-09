#include <iostream>
#include "Log.hpp"

int main(int argc, char const *argv[])
{
    int n = 5;
    while(n --> 0)
    {
        Log << n;
    }
    return 0;
}
