#include <iostream>
#include <vector>
using std::vector;
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    int begin = newInterval[0];
    int end = newInterval[1];

    vector<int> v(2);
    for(int i = 0 ; i < intervals.size() ; i++) {

        if(begin > intervals[i][1]) {
            res.push_back(intervals[i]);
            continue;
        } else if(end < intervals[i][0]) {
            res.push_back(intervals[i]);
            continue;
        }
        if(begin >= intervals[i][0] && begin <= intervals[i][1]) {
            v[0] = intervals[i][0];
        }
        if(end < intervals[i][0]) {
            v[1] = end;
        } else if(end > intervals[i][1]) {
            v[1] = end;
        } else if(end < intervals[i][1]) {
            v[1] = intervals[i][1];
        } else {
            v[1] = intervals[i][1];
        }

        if(v.size() == 2) {
            res.push_back(v);
            v.clear();
        }
    }
    return res;
}

int main(int argc, char* argv[]) {

    vector<vector<int>> v{
        {1, 2},
        {3, 5},
        {6, 7},
        {8, 10}
    };
    vector<int> v1{4, 8};
    vector<vector<int>> v2 = insert(v, v1);
    for(auto item : v2) {
        std::cout << item[0] << " " << item[1] << std::endl;
    }

    return 0;
}
