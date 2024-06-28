#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>
using namespace std;

class StringCalculator {
public:
    int add(const std::string& numbers);
private:
    void tokenize(const string& str, const string& delimiter, vector<int>& tokens);
    void getCustomDelimiter(string& str, string& delimiter);
    int calculateTokenSum(std::vector<int>& tokens);
    int ValidatedTokenValue(int val);
    void ExceptionHandlingForNegativeToken(int token);
    void NegativeTokenHandle(std::vector<int>& tokens, string& strToken);
    void replaceNewlineWithDelimiter(std::string& str,const std::string& delimiter);
};
