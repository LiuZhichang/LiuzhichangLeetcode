#include <iostream>
#include <string>
#include <sstream>
std::string reverseWords(std::string s) {
    std::istringstream ss(s);
    std::string res, temp;
    while(ss >> temp) {
        res = temp + ' ' + res;
    }
    return res.substr(0, res.size() - 1);
}



int main(int argc, char* argv[]) {

    std::string s{"  hello world!  "};
    std::string res = reverseWords(s);
    std::cout << res << std::endl;
    return 0;
}
