#include <iostream>
#include <string>

std::string reverseLeftWords(std::string s, int n) {
    std::string res;
    for(int i = n ; i < s.size() ;  ++i) {
        res.push_back(s[i]);
    }
    for(int i = 0 ; i < n ; ++ i) {
        res.push_back(s[i]);
    }
    std::cout << res << std::endl;
    return res;
}



int main(int argc, char* argv[]) {

    std::string s{"abcdefg"};
    reverseLeftWords(s, 2);

    return 0;
}
