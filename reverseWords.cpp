#include <iostream>
#include <string>

void reverse(std::string& str, int begin, int end) {
    while(begin < end) {
        std::swap(str[begin++], str[end--]);
    }
}

std::string reverseWords(std::string s) {
    int begin = 0;
    int end = 0;
    int size = s.size();
    for(int i = 0 ; i < size; i++) {
        if(s[i] == ' ') {
            end = i - 1;
            reverse(s, begin, end);
            begin = i + 1;
        }
    }
    reverse(s, begin, size - 1);
    return s;
}

int main(int argc, char** argv) {

    std::string s{"Let's take LeetCode contest"};
    std::string res = reverseWords(s);
    std::cout << res << std::endl;
    return 0;
}
