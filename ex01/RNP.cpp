#include "RNP.hpp"

RNP::RNP() : _stack() {}
RNP::~RNP(){}
RNP::RNP( const RNP& copy ){*this = copy;}
RNP& RNP::operator=( const RNP& other )
{
    _stack = other._stack;
    return *this;
}

void    RNP::setStr(std::string str)
{
    _str = str;
}
char    RNP::getC( int i ) const
{
    return _str[i];
}
size_t    RNP::getSize() const
{
    return _str.size();
}
int         RNP::getTop() const
{
    return _stack.top();
}
std::stack<int> RNP::getStack()
{
    return _stack;
}


void    RNP::addNodeInStack( const char c )
{
    int nb = c - '0';
    _stack.push(nb);
}

int RNP::ft_calcul_polonish()
{
    if (getStack().size() < 2)
        return 1;
    int tmp = _stack.top();
    _stack.pop();
    int tmp2 = _stack.top();
    _stack.pop();

    int res = 0;
    if (opera == '+')
        res = tmp2 + tmp;
    else if (opera == '-')
        res = tmp2 - tmp;
    else if (opera == '*')
        res = tmp * tmp2;   
    else if (opera == '/')
    {
        if (tmp == 0)
        {
            std::cout << "oooh\n";
            return 2;
        }
        res = tmp2/ tmp;
    }
    else
        return 3;
    _stack.push(res);
    return 0;
}

