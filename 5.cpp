#include <string>
#include <iostream>

using std::string;

// 暴力

bool valid(string str, int left, int right) {
    while(left < right) {
        if(str[left] != str[right]) {
            return false;
        }
        ++left;
        --right;
    }
    return false;
}

string longestPalindrome(string s) {
    int size = s.size();
    if(size < 2)
        return s;

    string res = s.substr(0, 1);

    return res;
}

int main(int argc, char *argv[]) {

    string str{"babad"};
    longestPalindrome(str);

    return 0;
}
