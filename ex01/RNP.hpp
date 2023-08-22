#ifndef RNP_HPP
# define RNP_HPP

#include <iostream>
#include <stack>
#include <cstdlib>

class RNP {

    private:
        std::stack<int> _stack;
        std::string _str;

    public:
        RNP();
        ~RNP();
        RNP( const RNP& copy );
        RNP& operator=( const RNP& other );

        void    setStr(std::string str);
        char    getC( int n ) const;
        size_t  getSize() const;
        void    addNodeInStack( const char c );
        int    ft_calcul_polonish();
        int     getTop() const;
        std::stack<int> getStack();
        char        opera;



};


# endif // RNP_HPP