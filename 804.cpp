#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
std::string password[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

int uniquePassword(std::vector<std::string>& words) {
    int res = 0;
    std::set<std::string> count;
    std::string str;
    for(auto& word : words) {
        std::string temp ;
        for(char& ch : word) {
            temp += password[ch % 97];
        }
        count.insert(temp);
    }
    return count.size();
}

int main(int argc, char** argv) {

    std::vector<std::string> words{"zocd", "gjkl", "hzqk", "hzgq", "gjkl"};
    std::cout << uniquePassword(words) << std::endl;

    return 0;
}
