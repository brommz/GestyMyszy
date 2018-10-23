#include "Exception.h"

Exception::Exception(const std::string& arg)
    : std::runtime_error(arg)
{
}

Exception::~Exception() throw()
{
}
