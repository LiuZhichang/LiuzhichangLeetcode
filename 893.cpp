#include <iostream>
#include <vector>
#include <string>
#include <set>
int numSpecialEquivGroups(std::vector<std::string>& A) {
    int res = 0;
    std::set<std::string> counter;
    for(auto& str : A) {
        counter.insert(str);
    }
    for(auto& str : A) {
        std::cout << str << ":" << std::endl;
        std::string temp = str;
        for(int i = 0; i < str.size() ; ++i) {
            if(i + 2 < str.size()) {
                std::swap(temp[i], temp[i + 2]);
                if(counter.count(str)) {
                    std::cout << "\t" << str << std::endl;
                    ++ res;
                }
            } else {
                break;
            }
        }
    }

    return res;
}

int main(int argc, char** argv) {
    std::vector<std::string> A {"abcd", "cdab", "cbad", "xyzz", "zzxy", "zzyx"};
    std:: cout << numSpecialEquivGroups(A) << std::endl;

    return 0;
}
