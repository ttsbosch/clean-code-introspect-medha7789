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
    bool getCustomDelimiter(string& str, string& delimiter);
};
