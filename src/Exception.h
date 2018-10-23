#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdexcept>
#include <string>

class Exception : public std::runtime_error
{
public:
    explicit Exception(const std::string& arg);

    virtual ~Exception() throw();

protected:

private:
};

#endif // EXCEPTION_H
