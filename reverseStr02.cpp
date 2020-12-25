#include <iostream>
#include <string>

void reverse(std::string& str, int start, int end) {
    std::cout << start << " " << end << std::endl;
    for(int i = start, j = end ; i < j ; ++i, --j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
std::string reverseStr(std::string s, int k) {
    int index = 0;
    for(int i = 0 ; i < s.size() - 1 ; ++i) {
        int total = (s.size() - (i + 1));
        if((i + 1) % (k << 1) == 0) {
            std::cout << "index :" << i << std::endl;

            reverse(s, index, i - k);
            index = i + 1;
        }

        std::cout << total << std::endl;
        if(total < k) {
            reverse(s, index, s.size() - 1);
            break;
        } else if( total > k && total < (k << 1)) {
            reverse(s, index, index + k - 1);
            break;
        }
    }
    return s;
}

int main(int argc, char** argv) {

    std::string s{"abcdefg"};

    std::string str = reverseStr(s, 2);

    std::cout << str << std::endl;

    return 0;
}
