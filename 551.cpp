#include <iostream>
#include <string>
using std::string;
bool checkRecord(string s) {
    if(s.empty())
        return false;
    int a_count = 0;
    int l_consecutive_count = 0;
    for(auto ch : s) {
        if(ch == 'A')
            ++ a_count;
        l_consecutive_count = (ch == 'L') ? (l_consecutive_count + 1) : 0;
        if(a_count > 1 && l_consecutive_count > 2)
            return false;
    }
    return true;
}

int main(int argc, char* argv[]) {

    string s{"LALLPLLL"};

    checkRecord(s);

    return 0;
}
