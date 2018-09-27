#include <iostream>
#include <sstream>

class LogStream
{
public:
    friend std::istream& operator >> (std::istream& p_is,  LogStream& p_log)
    {
        return p_is >> p_log.m_logBuffer;
    }

    ~LogStream()
    {
        std::cout << m_logBuffer << std::endl;
    }
private:
    std::stringstream m_logBuffer;
};

#define Log std::cout << __FUNCTION__ << "() " 