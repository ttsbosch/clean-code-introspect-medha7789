#include "StringCalculator.h"
void StringCalculator::tokenize(const std::string& str, const std::string& delimiter, std::vector<int>& tokens) 
{
        size_t start = 0, end = 0;
        while ((end = str.find(delimiter, start)) != std::string::npos) 
        {
            std::string token = str.substr(start, end - start);
            tokens.push_back(std::stoi(token));
            start = end + delimiter.length();
        }
        std::string last_token = str.substr(start);
        tokens.push_back(std::stoi(last_token));
}
int StringCalculator::add(const std::string& numbers)
{
        if ( numbers.empty() )
        {
                return 0;
        }
        else
        {
                
        }       
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
