#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>

class StringCalculator {
public:
    int add(const std::string& numbers) {
        if (numbers.empty()) {
            return 0;
        }
        
        std::string delimiter = ",";
        std::string numbers_copy = numbers;
        
        // Check for custom delimiter
        if (numbers_copy.substr(0, 2) == "//") {
            size_t end_of_delimiter = numbers_copy.find("\n");
            if (end_of_delimiter != std::string::npos) {
                delimiter = numbers_copy.substr(2, end_of_delimiter - 2);
                numbers_copy = numbers_copy.substr(end_of_delimiter + 1);
            }
        }
        
        // Splitting numbers based on delimiter and newlines
        std::vector<int> nums;
        tokenize(numbers_copy, delimiter, nums);
        
        // Summing numbers, ignoring negatives and numbers > 1000
        int sum = 0;
        std::vector<int> negatives;
        for (int num : nums) {
            if (num < 0) {
                negatives.push_back(num);
            } else if (num <= 1000) {
                sum += num;
            }
        }
        
        // Throw exception for negatives
        if (!negatives.empty()) {
            std::stringstream ss;
            ss << "Negatives not allowed: ";
            for (size_t i = 0; i < negatives.size(); ++i) {
                if (i != 0) ss << ", ";
                ss << negatives[i];
            }
            throw std::runtime_error(ss.str());
        }
        
        return sum;
    }
    
private:
    void tokenize(const std::string& str, const std::string& delimiter, std::vector<int>& tokens) {
        size_t start = 0, end = 0;
        while ((end = str.find(delimiter, start)) != std::string::npos) {
            std::string token = str.substr(start, end - start);
            tokens.push_back(std::stoi(token));
            start = end + delimiter.length();
        }
        std::string last_token = str.substr(start);
        tokens.push_back(std::stoi(last_token));
    }
};

int main() {
    StringCalculator calc;
    
    try {
        std::cout << calc.add("") << std::endl;                      // Output: 0
        std::cout << calc.add("1") << std::endl;                     // Output: 1
        std::cout << calc.add("1,2") << std::endl;                   // Output: 3
        std::cout << calc.add("1\n2,3") << std::endl;                // Output: 6
        std::cout << calc.add("//;\n1;2") << std::endl;              // Output: 3
        std::cout << calc.add("//[***]\n12***3") << std::endl;       // Output: 6
        std::cout << calc.add("2,1001") << std::endl;                // Output: 2 (1001 is ignored)
        std::cout << calc.add("//[abc]\n1abc2") << std::endl;        // Output: 3
        
        std::cout << calc.add("1,2,3,4,5") << std::endl;              // Output: 15 (Sum of multiple numbers)
        std::cout << calc.add("1\n2\n3\n4\n5") << std::endl;         // Output: 15 (Newlines separating numbers)
        std::cout << calc.add("//[;]\n1;2;3;4;5") << std::endl;       // Output: 15 (Custom delimiter)
        
        // Uncomment the line below to test negative numbers exception handling:
        // std::cout << calc.add("1,-2,3,-4") << std::endl;           // Should throw exception
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}
