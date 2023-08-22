#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> 

bool    ft_checkdate(std::string s)
{
    int i;

    for (i = 0; i < 4; i++)
    {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    if (s[i] != '-')
        return false;
    else    i++;
    int j = i;
    for (i = i; i < j+2; i++)
    {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    if (s[i] != '-')
        return false;
    else    i++;
    j = i;
    for (i = i; i < j+2; i++)
    {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    if (s[i] != ' ')
            return false;
    else    i++;
    if (s[i] != '|')
        return false;
    else    i++;
    if (s[i] != ' ')
            return false;
    else    i++;
    if (s[i] < '0' || s[i] > '9')
        return false;
    return true;
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    (void)av;
    std::string     str;
    std::fstream   file("data.csv");
    BitcoinExchange* btc = new BitcoinExchange();

    if (file.is_open())
    {
        getline(file, str);
        if (str != "date,exchange_rate")
        {
            std::cout << "data.csv invalid" << std::endl;
            return 1;
        }
        while (getline(file, str))
            btc->setData(str.substr(0, str.find(',')), atof((str.substr(str.find(',') + 1, str.size())).c_str()));
        // btc->print();
    }
    float val;
    std::fstream input(av[1]);
    if (input.is_open())
    {
        getline(input, str);
        if (str != "date | value")
        {
            std::cout << av[1] << " invalid" << std::endl;
            return 1;
        }
        while (getline(input, str))
        {
            if (ft_checkdate(str) == false)
                std::cout << "Error: bad input => " << str << std::endl;
            else
            {
                val = atof((str.substr(str.find('|') + 2, str.size())).c_str());
                if (val < 0)
                    std::cout << "Error: not a positive number." << std::endl;
                else if  (val > 1000)
                    std::cout << "Error: number too large." << std::endl;
                else
                    btc->search(str);
            }
        }
    }
    else
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    delete btc;
    return 0;
}