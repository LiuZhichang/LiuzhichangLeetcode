#include <iostream>
#include <string>

char translator(std::string& str) {
    char res;
    if(str.size() > 1) {

    } else {
        res = str[0] + 48;
    }
    return res;
}

std::string freqAlphabets(std::string s) {
    std::string ans;
    for (int i = 0; i < s.size(); ++i) {
        if (i + 2 < s.size() && s[i + 2] == '#') {
            ans += char((s[i] - '0') * 10 + (s[i + 1] - '1') + 'a');
            i += 2;
        } else {
            ans += char(s[i] - '1' + 'a');
        }
    }
    return ans;
}


int main(int argc, char** argv) {

    std::string s{"10#11#12"};
    std::cout << freqAlphabets(s) << std::endl;

    return 0;
}
