#include <iostream>
#include <string>

void reverse(std::string& str, int begin, int end) {
    std::cout << "begin :" << begin << "\t"
              << "end :" << end << std::endl;
    for(int i = begin, j = end ; i < j ; ++i, -- j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

std::string reverseStr(std::string s, int k) {
    int total = s.size();
    int count = total / (k << 1);
    int residue = total % (k << 1);
    int residue_begin = total - residue;

    std::cout << "total :" << total << "\n"
              << "count :" << count << "\n"
              << "residue :" << residue << "\n"
              << "residue_begin: " << residue_begin << "\n"
              << "k :" << k << std::endl;
    if(count != 0) {
        int begin = 0;
        int end = begin + k;
        while(count) {
            reverse(s, begin, end - 1);
            begin = end + k;
            end = begin + k ;
            --count;
        }
    }
    if(residue != 0) {
        if(residue < k) {
            reverse(s, residue_begin, total - 1);
        } else if(residue < (k << 1) && residue >= k) {
            reverse(s, residue_begin, residue_begin + k - 1);
        }
    }

    return s;
}


int main(int argc, char* argv[]) {

    std::string s{"abcd"};
    std::string str = reverseStr(s, 3);
    std::cout << str << std::endl;

    return 0;
}
