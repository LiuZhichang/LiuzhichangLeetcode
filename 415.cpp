#include <cstdlib>
#include <iostream>
#include <string>
using std::string;
string addStrings(string num1, string num2) {
    string res;
    int n1_size = num1.size();
    int n2_size = num2.size();
    int deliver = 0;
    // if(n1_size == 1 && n2_size == 1) {
    //     int sum = (num1[0] - '0') + (num2[0] - '0');
    //     int uint = sum % 10;
    //     deliver = sum / 10;
    //     return res;
    // }
    string complement(std::abs(n1_size - n2_size), '0');
    if(n1_size > n2_size) {
        num2 = complement + num2;
        n2_size = n1_size;
    } else if (n1_size < n2_size) {
        num1 = complement + num1;
        n1_size = n2_size;
    }
    for(int i = n1_size - 1 ; i >= 0 ; i--) {
        int sum = (num1[i] - '0') + (num2[i] - '0') + deliver;
        int uint = sum % 10;
        res = std::to_string(uint) + res;

        std::cout << sum << " " << deliver << " " << uint << std::endl;
        deliver = sum / 10;
    }
    if(deliver)
        res = std::to_string(deliver) + res;
    return res;
}

int main(int argc, char* argv[]) {

    int val1 = 19;
    int val2 = 1;
    std::cout << addStrings(std::to_string(val1), std::to_string(val2)) << std::endl;
    std::cout << val1 + val2 << std::endl;
    return 0;
}
