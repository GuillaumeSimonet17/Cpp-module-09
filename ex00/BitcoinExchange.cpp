#include "BitcoinExchange.hpp"
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {

};
BitcoinExchange::~BitcoinExchange(){};
BitcoinExchange::BitcoinExchange( const BitcoinExchange& copy ){
    *this = copy;
};
BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& other ){
    _data = other.getData();
    return *this;
}
std::map<std::string, float> BitcoinExchange::getData() const{
    return _data;
}
void BitcoinExchange::setData(std::string s, float f){
    _data.insert(std::make_pair(s, f));
}
void BitcoinExchange::print()
{
    for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); it++){
        std::cout << it->first << " " << it->second << std::endl;
    }
}

int    BitcoinExchange::check_date(std::string str)
{
    std::string year = str.substr(0, str.find('-'));
    std::string month = str.substr(year.size()+1, str.find('-')-2);
    std::string day = str.substr(year.size() + month.size() + 2 , 2);
    int m = atoi(month.c_str());
    if (m < 1 || m > 12)
    {
        std::cout << "Error: bad input => " << year << '-' << month << '-' << day << std::endl;
        return 1;
    }
    else {
        int d = atoi(day.c_str());
        if (d < 1 || d > 31)
        {
            std::cout << "Error: bad input => " << year << '-' << month << '-' << day << std::endl;
            return 1;
        }
    }
    return 0;
}

void BitcoinExchange::search(std::string str)
{
    std::string date = str.substr(0, str.find('|')-1);
    std::string val = str.substr(str.find('|')+2, str.size());
    float   value = atof(val.c_str());
    if (check_date(date))
        return ;
    std::map<std::string, float>::iterator it;
    it = _data.upper_bound(date);
    it--;
    if ( it == _data.begin())
        it++;
    float res = it->second * value;
    std::cout << date << " => " << value << " = " << res << std::endl;
}
