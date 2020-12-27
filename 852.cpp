#include <iostream>
#include <vector>

using std::vector;

int peakIndexInMountainArray(vector<int>& arr) {
    //     int i = 0;
    //     while(arr[i] < arr[i+1])
    //         ++ i;
    //     return i;
    // }
    int low = 0, high = arr.size() - 1;

    while(low < high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] < arr[mid + 1])
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int main(int argc, char* argv[]) {




    return 0;
}
