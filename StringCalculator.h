#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>

class StringCalculator {
public:
    int add(const std::string& numbers);
private:
    void tokenize(const std::string& str, const std::string& delimiter, std::vector<int>& tokens);
};
