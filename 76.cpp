#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

string minWindow(string s, string t) {
    unordered_map<char, int> need, window;
    int left = 0, right = 0;
    int begin = 0;
    int valid = 0;
    int len = INT32_MAX;
    for(auto ch : t)
        need[ch]++;
    while(right < s.size()) {
        char ch = s[right];
        ++right;
        if(need.count(ch)) {
            window[ch]++;
            if(window[ch] == need[ch])
                ++valid;
        }

        while(valid == need.size()) {
            if(right - left < len) {
                begin = left;
                len = right - left;
            }
            char ch = s[left];
            ++left;
            if(need.count(ch)) {
                if(window[ch] == need[ch])
                    --valid;
                --window[ch];
            }
        }
    }
    return len == INT32_MAX ? " " : s.substr(begin, len);
}

int main(int argc, char** argv) {

    string s = "ADOBECODEBANC", t = "ABC";

    string res = minWindow(s, t);

    std::cout << res << std::endl;

    return 0;
}
