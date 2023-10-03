#ifndef _FETCH_H
#define _FETCH_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <string>
#include <cmath>
#include <algorithm>

class Fetch
{
public:
    Fetch(void);
    ~Fetch(void);
    int AlphaNumeric(std::string Retailer);
    int TotalRoundAnd25(std::string Total);
    int TimePurchase(std::string Time);
    int OddDay(std::string Date);
    bool TrimmedLength(std::string ItemDescription);
    int TrimmedLengthPoints(std::string ItemPrice);
    int ItemsEven(int CountItems);

private:
    int Test;
};

#endif