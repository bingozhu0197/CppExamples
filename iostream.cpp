#include <iostream>
#include <String>
#include "Log.hpp"
//#define Log std::cout << __FUNCTION__ << "() " 

class OverrideInOutStream
{
public:
    friend std::ostream& operator << (std::ostream& p_os, const OverrideInOutStream& p_overrideInOutStream);
    friend std::istream& operator >> (std::istream& p_is,  OverrideInOutStream& p_overrideInOutStream);    
    void operator << (const std::string& p_input)
    {
        m_value = p_input;
    }

private:
    std::string m_value{"Member Initialized"};
};

std::ostream& operator <<(std::ostream& p_os, const OverrideInOutStream& p_overrideInOutStream)
{
    return p_os << p_overrideInOutStream.m_value;
}

std::istream& operator >>(std::istream& p_is, OverrideInOutStream& p_overrideInOutStream)
{
    return p_is >> p_overrideInOutStream.m_value;
}

void testInputOutputOverride()
{
    OverrideInOutStream l_io;
    Log << l_io;
    LogStream()<< "hwllo";
    //Log << l_io;

    l_io << "input with input stream";
    //Log << l_io;
}

int main(int argc, char const *argv[])
{
    std::cout << "Hello, great first step" << std::endl;

    testInputOutputOverride();
    return 0;
}
