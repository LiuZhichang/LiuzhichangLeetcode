#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using std::vector;

int sumOddLengthSubarrays(vector<int>& arr) {
    int sum = 0;
    for(int i = 0 ; i < arr.size() ; ++i) {
        sum += arr[i];
        int tmp = arr[i];
        for(int j = i + 1 ; j < arr.size() ; ++j) {
            tmp += arr[j];
            if(((j - i) & 1) == 0)
                sum += tmp;
        }
    }
    std::cout << sum << std::endl;
    return sum;
}

int sumOddLengthSubarrays2(vector<int>& arr) {

    vector<int> presum = {0};
    for(int e : arr) presum.push_back(presum.back() + e);

    int res = 0;
    for(int i = 0; i < arr.size(); i ++)
        for(int sz = 1; i + sz - 1 < arr.size(); sz += 2)
            res += presum[i + sz] - presum[i];

    return res;
}

int main(int argc, char* argv[]) {

    vector<int> arr{1, 4, 2, 5, 3};

    sumOddLengthSubarrays(arr);

    return 0;
}
