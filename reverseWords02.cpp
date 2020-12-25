#include <iostream>
#include <string>
#include <vector>

void reverse(std::string& str) {
    int i = 0;
    int j = str.size() - 1;
    while(i < j) {
        std::swap(str[i++], str[j--]);
    }
}
std::string reverseWords(std::string s) {
    std::string res;
    std::string temp;
    bool keep = true;
    int i = 0;
    while(i < s.size()) {
        if(s[i] != ' ') {
            temp.push_back(s[i]);
            ++ i;
            keep = true;
        }
        while(s[i] == ' ') {
            keep = false;
            ++ i;
        }
        if(!keep || i == s.size()) {
            temp += res;
            res = temp;
            temp = "";
        }
    }
    std::cout << res << std::endl;
    return res;
}

int main(int argc, char** argv) {
    std::string s{"the  sky is blue."};
    reverseWords(s);
    return 0;
}
