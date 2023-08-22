#ifndef PMERGEME_HPP
# define  PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sys/time.h>
#include <unistd.h>
#include <cstdlib>

template<typename T>
class Pmergeme {

    private:
        T*       _container;
        typename T::iterator _it;

    public:
        Pmergeme();
        Pmergeme( int ac ) {_container = new T[ac];};
        Pmergeme( const Pmergeme& copy );
        Pmergeme& operator=( const Pmergeme& other );
        ~Pmergeme() {delete [] _container;};

        T&    getContainer() const {return *_container;};
        void setContainer(int ac, char **av);

        void    printContainer();

        class NegativeNumber : public std::exception {
            public:
            const char* what() const throw(){
                return "Error: Negative number in arguments";
            }
        };

};

template<typename T>
Pmergeme<T>& Pmergeme<T>::operator=( const Pmergeme& other )
{
    if (this != &other)
    {
        _container->clear();
        for (_it = _container->begin(); _it != _container->end(); _it++)
            _container->push_back(*_it);
    }
    return *this;
}

template<typename T>
void    Pmergeme<T>::setContainer(int ac, char **av)
{
    _container->clear();
    for (int i = 0; i < ac; i++)
    {
        long value = atol(av[i]);
        if (value < 0 || value > 2147483647)
            throw NegativeNumber();
        // std::cout << value << std::endl;
        _container->push_back(value);
    }
}

template<typename T>
void    Pmergeme<T>::printContainer()
{
    for (_it = _container->begin(); _it != _container->end(); _it++)
        std::cout << *_it << " ";
    std::cout << std::endl;
};


# endif // PMERGEME_HPP

