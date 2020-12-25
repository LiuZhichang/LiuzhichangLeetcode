#include <cctype>
#include <iostream>
#include <string>

bool isAlpha(char ch) {
    return ( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ) ? true : false;
}

std::string reverseOnlyLetters(std::string s) {
    int size = s.size();
    for(int i = 0, j  = size - 1 ; i < j ;) {
        bool flag = true;;
        if(!isAlpha(s[i])) {
            ++i;
            flag = false;
        }
        if(!isAlpha(s[j])) {
            --j;
            flag = false;
        }

        if(flag) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            ++ i;
            -- j;
        }
    }
    return s;
}

int main(int argc, char** argv) {

    std::string s{"7_28]"};
    std::cout << s << std::endl;
    std::string str = reverseOnlyLetters(s);
    std::cout << str << std::endl;
    return 0;
}
