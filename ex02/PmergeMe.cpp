#include "PmergeMe.hpp"

template<typename T>
Pmergeme<T>::Pmergeme() : _container(NULL) {};

template<typename T>
Pmergeme<T>::Pmergeme( const Pmergeme& copy ){
    *this = copy;
};
