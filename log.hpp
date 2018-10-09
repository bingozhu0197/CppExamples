#include <iostream>
#include <sstream>

//This version will automatically add "endline" after string
class LogStream
{
public:
    template <typename T>
    LogStream& operator << (const T& p_value)
    {
         std::cout << p_value;
        return *this;
    }

    ~LogStream()
    {
        std::cout << std::endl;
    }
};

#define Log  LogStream()



//simplest version to add function name
//#define Log std::cout << __FUNCTION__ << "() " 