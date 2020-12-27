#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> res;
    for(int i = 0 ; i < n ; ++i) {
        res.emplace_back(nums[i]);
        res.emplace_back(nums[n + i]);
    }
    return res;
}

int main(int argc, char* argv[]) {

    vector<int> v{2, 5, 1, 3, 4, 7};


    shuffle(v, 3);
    return 0;
}
