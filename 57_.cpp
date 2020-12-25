#include <iostream>
#include <vector>
using std::vector;
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    int begin = newInterval[0];
    int end = newInterval[1];
    bool flag = false;
    for(int i = 0 ; i < intervals.size() ; ++ i) {
        int l = intervals[i][0];
        int r = intervals[i][1];
        if(l > end) {
            if(!flag) {
                res.push_back({begin, end});
                flag = true;
            }
            res.push_back(intervals[i]);
        } else if(r < begin) {
            res.push_back(intervals[i]);
        } else {
            begin = std::min(begin, l);
            end = std::max(end, r);
        }
    }
    if(!flag)
        res.push_back({begin, end});
    return res;
}
int main(int argc, char* argv[]) {
    vector<vector<int>> v{
        {1, 5},
        {8, 10}
    };
    vector<int> v1{
        6, 8
    };
    vector<vector<int>> v3 = insert(v, v1);
    std::cout << " ------------------- " << std::endl;
    for(auto& item : v3) {
        std::cout << item[0] << " " << item[1] << std::endl;
    }
    return 0;
}
