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
  if (numbers.empty()) 
    return 0;
}
