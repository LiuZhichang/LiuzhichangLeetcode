#include <iostream>
#include <string>
#include <unordered_map>

using std::unordered_map;
using std::string;

bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> need, window;

    int left = 0, right = 0;
    int valid = 0;

    for(char& ch : s1)
        ++need[ch];

    while(right < s2.size()) {
        char ch = s2[right];
        ++right;

        if(need.count(ch)) {
            ++window[ch];
            if(window[ch] == need[ch])
                ++valid;
        }

        while(right - left == s1.size()) {

            if(valid == need.size())
                return true;

            char ch = s2[left];
            --left;

            if(need.count(ch)) {
                if(window[ch] == need[ch])
                    --valid;
                --window[ch];
            }
        }
    }
    return false;
}


int main(int argc, char* argv[]) {



    return 0;
}
