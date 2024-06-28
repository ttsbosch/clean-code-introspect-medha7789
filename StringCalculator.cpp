#include "StringCalculator.h"
void StringCalculator::tokenize(const std::string& str, const std::string& delimiter, std::vector<int>& tokens) 
{
        size_t start = 0, end = 0;
        while ((end = str.find(delimiter, start)) != std::string::npos) 
        {
            std::string token = str.substr(start, end - start);
            int tokenTemp = std::stoi(token);
            if(tokenTemp<0)
            {
                string errorMessage = std::string("negatives not allowed ");
                throw std::runtime_error(errorMessage);
            }
            else
            {    
                tokens.push_back(tokenTemp);
                start = end + delimiter.length();
            }
        }
        std::string last_token = str.substr(start);
        tokens.push_back(std::stoi(last_token));
}
int StringCalculator::add(const std::string& numbers)
{
        string delimiter = ",";
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
bool StringCalculator::getCustomDelimiter(std::string& str,string& delimiter)
{
        if (str.substr(0, 2) == "//") 
        {
            size_t end_of_delimiter = str.find("\n");
            if (end_of_delimiter != std::string::npos) 
            {
                delimiter = str.substr(2, end_of_delimiter - 2);
                str = str.substr(end_of_delimiter + 1);
            }
            return true;
        }
        else
        {
                return false;
        }
}
