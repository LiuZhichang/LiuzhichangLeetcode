#include <iostream>
#include <string>

int counter[26] = {};

std::string sortString(std::string s) {
    std::string res;
    for(char& ch : s) {
        ++ counter[ch - 'a'];
    }
    int n = s.size();
    while(n)  {
        for(int i = 0 ; i < 26 ; ++i) {
            if(counter[i]) {
                res.push_back( (i + 'a') );
                -- counter[i];
                -- n;
            }
        }
        for(int i = 25 ; i >= 0 ; --i ) {
            if(counter[i]) {
                res.push_back( (i + 'a') );
                -- counter[i];
                -- n;
            }
        }
    }
    return res;
}



int main(int argc, char* argv[]) {

    std::string s{"aaaabbbbcccc"};
    std::cout << sortString(s) << std::endl;

    return 0;
}
