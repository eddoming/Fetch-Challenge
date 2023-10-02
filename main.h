#ifndef _MAIN_H
#define _MAIN_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Fetch.h"

class MainCore: public Fetch
{
public:
    MainCore(void);
    ~MainCore(void);
    bool StartAnalysis(void);
    bool ReadTestJSON(void);
    void AnalyzeJSON(std::string JSON);

private:
    int MainTest;
    std::vector<std::string> ListOfJSON;
    int TotalAmountPoints;
};

#endif