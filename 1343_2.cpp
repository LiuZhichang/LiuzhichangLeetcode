#include <iostream>
#include <vector>
int maxSumSub(std::vector<int>& arr, int k, int threshold) {
    int maxSum = 0;
    int target = k * threshold;
    int res = 0;
    for(int i = 0 ; i < k ; i++) {
        maxSum += arr[i];
    }
    if(maxSum >= target)
        res ++;
    for(int i = k ; i < arr.size() ; i++) {
        maxSum += arr[i] - arr[i - k];
        if(maxSum >= target)
            res ++;
        if(k + 1 < arr.size())
            std::cout <<  maxSum << " ";
    }
    return res;
}

int main(int argc, char** argv) {
    std::vector<int> v{11, 13, 17, 23, 29, 31, 7, 5, 2, 3};
    std::cout << maxSumSub(v, 3, 5) << std::endl;

    return 0;
}
