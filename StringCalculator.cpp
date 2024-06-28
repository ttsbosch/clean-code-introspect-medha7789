#include "StringCalculator.h"
void StringCalculator::tokenize(const std::string& str, const std::string& delimiter, std::vector<int>& tokens) 
{
        size_t start = 0, end = 0;
        while ((end = str.find(delimiter, start)) != std::string::npos) 
        {
                std::string token = str.substr(start, end - start);
                int tokenTemp = std::stoi(token);
                if(token<0)
                {
                       ExceptionHandlingForNegativeToken(tokenTemp);
                }
                else
                {
                        tokens.push_back(tokenTemp);
                        start = end + delimiter.length();
                }
        }
        std::string last_token = str.substr(start);
        int last_tokenTemp = std::stoi(last_token);
        if(last_tokenTemp<0)
                ExceptionHandlingForNegativeToken(last_tokenTemp);
        tokens.push_back(last_tokenTemp);
}
void StringCalculator::ExceptionHandlingForNegativeToken(int token)
{
    string errorMessage = std::string("negatives not allowed : ");
    errorMessage+= to_string(token);
    throw std::runtime_error(errorMessage);
}
int StringCalculator::add(const std::string& numbers)
{
        string delimiter = ",";
        getCustomDelimiter(numbers,delimiter);
        std::vector<int> tokens;
        if ( (numbers.empty()) || (numbers=="0"))
        {
                return 0;
        }
        else
        {
                tokenize(numbers,delimiter,tokens);
                int tokenSum = calculateTokenSum(tokens);
                return tokenSum;
        }       
}
int StringCalculator::calculateTokenSum(std::vector<int>& tokens)
{
        int tokenSum = 0;
        for(int i=0;i<tokens.size();i++)
        {
              tokenSum+= ValidatedTokenValue(tokens[i]);
        }
        return tokenSum;
}
int StringCalculator::ValidatedTokenValue(int val)
{
     int retVal = val;
     std::vector<int> negatives;
     if (val < 0) 
     {
             retVal = 0;
             negatives.push_back(val);
     }
     else if (val > 1000) 
     {
             retVal= 0;
     }
     return retVal;
}
void StringCalculator::getCustomDelimiter(const std::string& str,string& delimiter)
{
    string tempstr = str;
    if (tempstr.substr(0, 2) == "//") 
    {
        size_t end_of_delimiter = tempstr.find("\n");
        if (end_of_delimiter != std::string::npos) 
        {
            delimiter = tempstr.substr(2, end_of_delimiter - 2);
            tempstr = tempstr.substr(end_of_delimiter + 1);
        }
    }
}
