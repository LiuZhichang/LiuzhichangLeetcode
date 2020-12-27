#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    vector <int> r;
    for (unsigned i = 0; i < nums.size(); ++i) {
        r.insert(r.begin() + index[i], nums[i]);
    }
    return r;

}


int main(int argc, char* argv[]) {
    vector<int> nums{0, 1, 2, 3, 4};
    vector<int> index{0, 1, 2, 2, 1};
    auto res = createTargetArray(nums, index);

    for(auto num : res)
        std::cout << num << "\t";
    std::cout << std::endl;

    return 0;
}
