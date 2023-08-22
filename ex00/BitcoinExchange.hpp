#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

class BitcoinExchange {

    private:
        std::map<std::string, float>    _data;
        std::string                     _date;

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange( const BitcoinExchange& copy );
        BitcoinExchange& operator=( const BitcoinExchange& other );

        void print();
        std::map<std::string, float> getData() const;
        void setData(std::string, float);
        void search(std::string str);
        int check_date(std::string str);


};

#endif // BITCOINEXCHANGE_HPP