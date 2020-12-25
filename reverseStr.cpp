#include <iostream>
#include <vector>
void reverse(std::vector<char>& s) {
    int n = s.size();
    for(int i = 0, j = n - 1; i < j ; i++, j --  ) {
        char item = s[i];
        s[i] = s[j];
        s[j] = item;
    }
}



int main(int argc, char* argv[]) {

    std::vector<char> s;
    s.push_back('h');
    s.push_back('e');
    s.push_back('l');
    s.push_back('l');
    s.push_back('o');

    reverse(s);
    for(const auto& item : s)
        std::cout << item << std::endl;




    return 0;
}
