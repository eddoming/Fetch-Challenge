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
    std::cout << "Fetch Read JSON version 0.2" << std::endl;
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
    std::string itemDescription;
    std::string itemPrice;
    int countItems;
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
                if (localString.substr(2, 5).compare("items") == 0)
                {
                    localString = localString.substr(5 + 4);
                    pos = localString.find('[');
                    if (pos != std::string::npos)
                    {
                        pos = localString.find('{');
                        if (pos != std::string::npos)
                        {
                            localStep = 4;
                            localString = localString.substr(pos + 1);
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
            }
            else
            {
                exitFlag = true;
            }
            break;
        case 4:
            if (localString.at(0) == '\"')
            {
                if (localString.substr(1, 16).compare("shortDescription") == 0)
                {
                    countItems += 1;
                    localString = localString.substr(16 + 5);
                    pos = localString.find("\"");
                    if (pos != std::string::npos)
                    {
                        itemDescription = localString.substr(0, pos);
                        std::cout << itemDescription << std::endl;
                        localString = localString.substr(pos + 1);
                        if (Fetch::TrimmedLength(itemDescription) == true)
                        {
                            localStep = 5;
                        }
                        else
                        {
                            pos = localString.find('}');
                            if (pos != std::string::npos)
                            {
                                localString = localString.substr(pos);
                                localStep = 6;
                            }
                            else
                            {
                                exitFlag = true;
                            }
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
            }
            else
            {
                exitFlag = true;
            }
            break;
        case 5:
            if (localString.at(0) == ',')
            {
                if (localString.substr(2, 5).compare("price") == 0)
                {
                    localString = localString.substr(5 + 6);
                    pos = localString.find("\"");
                    if (pos != std::string::npos)
                    {
                        itemPrice = localString.substr(0, pos);
                        std::cout << itemPrice << std::endl;
                        localString = localString.substr(pos + 1);
                        currentTotalAmountOfPoints += Fetch::TrimmedLengthPoints(itemPrice);
                        localStep = 6;
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
        case 6:
            if (localString.substr(0, 3).compare("},{") == 0)
            {
                localStep = 4;
                localString = localString.substr(3);
            }
            else
            {
                if (localString.substr(0, 3).compare("}],") == 0)
                {
                    localStep = 7;
                    localString = localString.substr(2);
                }
                else
                {
                    exitFlag = true;
                }
            }
            break;
        case 7:
            exitFlag = true;
            break;
        }
    }
}