#include <iostream>
#include <vector>

using std::vector;
vector<int> decompressRLElist(vector<int>& nums) {
    vector<int> res;
    for(int i = 0 ; i < nums.size() ;) {
        int freq = nums[i];
        int val = nums[i + 1];
        while(freq > 0) {
            res.emplace_back(val);
            --freq;
        }
        i += 2;
    }
    return res;
}


int main(int argc, char* argv[]) {

    vector<int> nums{1, 2, 3, 4};

    auto res = decompressRLElist(nums);
    for(int num : res )
        std::cout << num << " ";
    std::cout << std::endl;
    return 0;
}
