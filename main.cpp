#include "main.h"

int main()
{
    MainCore *MainCorePtr;
    MainCorePtr = new MainCore();
    if (MainCorePtr == nullptr)
    {
        std::cout << "Error: MainCore" << std::endl;
    }
    return 0;
}

MainCore::MainCore(void)
{
    std::cout << "Fetch Read JSON version 0.1" << std::endl;
    StartAnalysis();
}

MainCore::~MainCore(void)
{
}

bool MainCore::StartAnalysis(void)
{
    std::string localMessage;
    bool exitFlag = false;
    int i;
    localMessage = "Fetch example";
    std::cout << localMessage << std::endl;
    if (ReadTestJSON() == true)
    {
        while (exitFlag == false)
        {
            if (i < (int)ListOfJSON.size())
            {
                AnalyzeJSON(ListOfJSON[i]);
                ++i;
            }
            else
            {
                exitFlag = true;
            }
        }
    }
    else
    {
        localMessage = "Error: Read JSON format";
        std::cout << localMessage << std::endl;
    }
    return true;
}
bool MainCore::ReadTestJSON(void)
{
    bool returnResult = false;
    std::fstream localfstream;
    std::string localJSONRead;

    localfstream.open("readFile.txt", std::fstream::in);
    if (localfstream.is_open() == true)
    {
        if (getline(localfstream,localJSONRead))
        {
            returnResult = true;
            //std::cout << localJSONRead << std::endl;
            ListOfJSON.push_back(localJSONRead);
        }
        else
        {
            std::cout << "Empty" << std::endl;
        }
    }
    else
    {
        std::cout << "File for JSON is not open" << std::endl;
    }
    localfstream.close();

    return returnResult;
}

void MainCore::AnalyzeJSON(std::string JSON)
{
    int localStep = 0;
    std::string localString;
    size_t pos = 0;
    std::string retailerData;
    std::string purchaseDate;
    std::string purchaseTime;
    int currentTotalAmountOfPoints = 0;
    bool exitFlag = false;

    while (exitFlag == false)
    {
        switch (localStep)
        {
        case 0:
            if (JSON.at(0) == '{')
            {
                if (JSON.substr(2, 8).compare("retailer") == 0)
                {
                    localString = JSON.substr(8 + 6);
                    pos = localString.find("\"");
                    if (pos != std::string::npos)
                    {
                        retailerData = localString.substr(0, pos);
                        localString = localString.substr(pos + 1);
                        currentTotalAmountOfPoints += Fetch::AlphaNumeric(retailerData);
                        localStep = 1;
                    }
                    else
                    {
                        exitFlag = true;
                    }
                }
                else
                {
                    exitFlag = true;
                }
            }
            else
            {
                exitFlag = true;
            }
            break;
        case 1:
            if (localString.at(0) == ',')
            {
                if (localString.substr(2, 12).compare("purchaseDate") == 0)
                {
                    localString = localString.substr(12 + 6);
                    pos = localString.find("\"");
                    if (pos != std::string::npos)
                    {
                        purchaseDate = localString.substr(0, pos);
                        localString = localString.substr(pos + 1);
                        currentTotalAmountOfPoints += Fetch::OddDay(purchaseDate);
                        localStep = 2;
                    }
                    else
                    {
                        exitFlag = true;
                    }
                }
                else
                {
                    exitFlag = true;
                }
            }
            else
            {
                exitFlag = true;
            }
            break;
        case 2:
            if (localString.at(0) == ',')
            {
                if (localString.substr(2, 12).compare("purchaseTime") == 0)
                {
                    localString = localString.substr(12 + 6);
                    pos = localString.find("\"");
                    if (pos != std::string::npos)
                    {
                        purchaseTime = localString.substr(0, pos);
                        localString = localString.substr(pos + 1);
                        currentTotalAmountOfPoints += Fetch::TimePurchase(purchaseTime);
                        localStep = 3;
                    }
                    else
                    {
                        exitFlag = true;
                    }
                }
                else
                {
                    exitFlag = true;
                }
            }
            else
            {
                exitFlag = true;
            }
            break;
        case 3:
            if (localString.at(0) == ',')
            {
                if (localString.substr(2, 12).compare("purchaseTime") == 0)
                {
                    localString = localString.substr(12 + 6);
                    pos = localString.find("\"");
                    if (pos != std::string::npos)
                    {
                        purchaseTime = localString.substr(0, pos);
                        localString = localString.substr(pos + 1);
                        currentTotalAmountOfPoints += Fetch::TimePurchase(purchaseTime);
                        localStep = 3;
                    }
                    else
                    {
                        exitFlag = true;
                    }
                }
                else
                {
                    exitFlag = true;
                }
            }
            else
            {
                exitFlag = true;
            }
            break;
        case 4:
            exitFlag = true;
        }
    }
}