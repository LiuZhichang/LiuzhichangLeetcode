#include <iostream>
#include <string>

bool isornot(char c) {
    return (c == 'a' || c == 'A' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'e' || c == 'E') ;
}

std::string reverseVowels0(std::string s) {
    int i = 0, j = s.length() - 1;
    while (i < j) {
        if (! isornot(s[i])) {
            i ++;
            continue;
        }
        if (! isornot(s[j])) {
            j --;
            continue;
        }
        std::swap (s[i++], s[j--]);
    }
    return s;
}

bool isVowels(char ch) {
    return (ch == 'a' || ch == 'A' ||
            ch == 'e' || ch == 'E' ||
            ch == 'i' || ch == 'I' ||
            ch == 'o' || ch == 'O' ||
            ch == 'u' || ch == 'U');
}

std::string reverseVowels(std::string s) {
    int begin = 0;
    int end = s.size() - 1;
    while(begin < end) {
        if(! isVowels(s[begin])) {
            ++ begin;
            continue;
        }
        if(! isVowels(s[end])) {
            -- end;
            continue;
        }
        std::swap(s[begin++], s[end++]);
    }
    return s;
}
int main(int argc, char** argv) {
    std::string s{".,"};
    std::string res = reverseVowels(s);
    std::cout << res << std::endl;
    return 0;
}
