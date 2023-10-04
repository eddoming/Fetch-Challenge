#include "Fetch.h"

Fetch::Fetch(void)
{
}

Fetch::~Fetch(void)
{
}

int Fetch::AlphaNumeric(std::string Retailer)
{
    const char *localChar = Retailer.c_str();
    int i = 0;
    int returnResult = 0;
    int length = Retailer.length();

    while (i <= length)
    {
        if (std::isalnum(localChar[i]))
        {
            returnResult += 1;
            i += 1;
        }
        else
        {
            i += 1;
        }
    }
    //std::cout << "One point for every alphanumeric character in the retailer name: +" << returnResult << std::endl;
    return returnResult;
}

int Fetch::TotalRoundAnd25(std::string Total)
{
    int returnResult = 0;
    int intOperations;
    double doubleTotal = stod(Total);
    int intTotal = stoi(Total);

    if (doubleTotal - intTotal == 0)
    {
        returnResult += 50;
        //std::cout << "The total is a round dollar amount with no cents: +50" << std::endl;
    }

    intOperations = ((doubleTotal * 100) / 25);
    if ((intOperations * 25) - (doubleTotal * 100) == 0)
    {
        returnResult += 25;
        //std::cout << "The total is a multiple of 0.25: +25" << std::endl;
    }

    return returnResult;
}

int Fetch::TimePurchase(std::string Time)
{
    int returnResult = 0;
    size_t pos = 0;
    std::string localString;
    std::string hourStr;
    int hour;
    std::string minStr;
    int min;

    pos = Time.find(":");
    if (pos != std::string::npos)
    {
        hourStr = Time.substr(0, pos);
        hour = stoi(hourStr);
        minStr = Time.substr(pos + 1);
        min = stoi(minStr);
        if ((hour >= 14) && (hour < 16))
        {
            if (min > 0)
            {
                returnResult = 10;
                //std::cout << "The time of purchase is after 2:00pm and before 4:00pm: +10" << std::endl;
            }
        } 
    }
    return returnResult;
}

int Fetch::OddDay(std::string Date)
{
    int returnResult = 0;
    std::string monthStr;
    std::string dayStr;
    std::string yearStr;
    int day;
    double dayOperation;
    size_t pos = 0;
    std::string localMessage;

    pos = Date.find("-");
    if (pos != std::string::npos)
    {
        yearStr = Date.substr(0, pos);
        localMessage = Date.substr(pos + 1);
        pos = localMessage.find("-");
        if (pos != std::string::npos)
        {
            monthStr = localMessage.substr(0, pos);
            dayStr = localMessage.substr(pos + 1);
            day = stoi(dayStr);
            dayOperation = (day / 2) * 2;
            if (dayOperation - day != 0 )
            {
                returnResult = 6;
                //std::cout << "The day in the purchase date is odd: +6" << std::endl;
            }
        }
    }

    return returnResult;
}

bool Fetch::TrimmedLength(std::string ItemDescription)
{
    bool returnResult = false;
    bool exitFlag = false;
    int lengthInt;
    double lengthDouble;

    while (exitFlag == false)
    {
        if (ItemDescription.at(0) == ' ')
        {
            ItemDescription = ItemDescription.substr(1);
        }
        else
        {
            if (ItemDescription.at(ItemDescription.length() - 1) == ' ')
            {
                ItemDescription = ItemDescription.substr(0, ItemDescription.length() - 1);
            }
            else
            {
                exitFlag = true;
            }
        }
    }

    lengthInt = (int)ItemDescription.length() / 3;
    lengthDouble = (double)ItemDescription.length() / 3;

    if ((lengthInt - lengthDouble) == 0)
    {
        returnResult = true;
    }
    else
    {
        returnResult = false;
    }

    return returnResult;
}

int Fetch::TrimmedLengthPoints(std::string ItemPrice)
{
    int returnResult = 0;
    double price = stod(ItemPrice);

    returnResult = ceil(price * 0.2);
    //std::cout << "Item description is a multiple of 3, multiply the price by 0.2 and round up to the nearest integer: +" << returnResult << std::endl;
    return returnResult;
}

int Fetch::ItemsEven(int CountItems)
{
    int operationDivision;
    operationDivision = CountItems / 2;
    operationDivision *= 5; 
    //std::cout << "5 points for every two items on the receipt: +" << operationDivision << std::endl;
	return operationDivision;
}