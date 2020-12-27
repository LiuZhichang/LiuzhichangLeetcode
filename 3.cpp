#include <iostream>
#include <string>
#include <unordered_map>

using std::unordered_map;
using std::string;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> window;
    int left = 0, right = 0;
    int len = 0;
    while(right < s.size()) {
        char ch = s[right++];
        ++window[ch];
        while(window[ch] > 1) {
            char ch = s[left++];
            --window[ch];
        }
        len = std::max(right - left, len);
    }
    return len;
}
int main(int argc, char *argv[]) {

    string s = "abcabcbb";
    int res = lengthOfLongestSubstring(s);
    std::cout << res << std::endl;

    return 0;
}
