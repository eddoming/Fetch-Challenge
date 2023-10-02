#ifndef _FETCH_H
#define _FETCH_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <string>

class Fetch
{
public:
    Fetch(void);
    ~Fetch(void);
    int AlphaNumeric(std::string Retailer);
    int TotalRoundAnd25(std::string Total);
    int TimePurchase(std::string Time);
    int OddDay(std::string Date);

private:
    int Test;
};

#endif