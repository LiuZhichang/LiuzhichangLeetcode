#include <iostream>
#include <vector>

using std::vector;

class Solution {
  public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        int i = 0, j = 0, k = 0;
        double res = 0.0;

        vector<int> nums(size);

        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] < nums2[j])
                nums[k++] = nums1[i++];
            else
                nums[k++] = nums2[j++];
        }

        if(i < nums1.size())
            while(i < nums1.size())
                nums[k++] = nums1[i++];

        if(j < nums2.size())
            while(j < nums2.size())
                nums[k++] = nums2[j++];

        int idx = (size >> 1);
        res = (size & 1) ? nums[idx] : ((nums[idx - 1] + nums[idx]) / 2.0);

        return res;
    }
};
