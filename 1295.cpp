#include <iostream>
#include <vector>

using std::vector;

bool valid(int num) {
    int cnt = 1;
    while(num /= 10)
        ++ cnt;
    return (cnt & 1) == 0;
}

int findNumbers(vector<int>& nums) {
    int res = 0;
    for(auto& num : nums)
        if(valid(num))
            ++ res;
    return res;
}


int main(int argc, char* argv[]) {


    std::cout << valid(21253) << std::endl;

    return 0;
}
