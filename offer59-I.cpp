#include <cstdint>
#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    int left = 0, right = 0;
    int begin = 0;
    while(right < nums.size()) {
        while(right - left == k - 1) {
            int max = *std::max_element(nums.begin() + left, nums.begin() + right + 1);
            res.push_back(max);
            ++left;
        }
        ++ right;
    }

    return res;
}


int main(int argc, char* argv[]) {

    std::vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};

    auto res = maxSlidingWindow(nums, 3);
    for(int num : res)
        std::cout << num << '\t';
    std::cout << std::endl;
    return 0;
}
