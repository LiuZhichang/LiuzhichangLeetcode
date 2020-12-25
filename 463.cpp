#include <iostream>
#include <vector>

using std::vector;

int row;
int col;
int res;

int dfs(vector<vector<int>>& v, int r, int c) {
    if (!(0 <= r && r < v.size() && 0 <= c && c < v[0].size())) {
        return 1;
    }
    if (v[r][c] == 0) {
        return 1;
    }
    if (v[r][c] != 1) {
        return 0;
    }
    v[r][c] = -1;
    return dfs(v, r - 1, c)
           + dfs(v, r + 1, c)
           + dfs(v, r, c - 1)
           + dfs(v, r, c + 1);
}

int main(int argc, char* argv[]) {

    vector<vector<int>> v{
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };

    row = v.size() ;
    col = v[0].size() ;
    res = 0;

    std::cout << dfs(v, 0, 1);

    return 0;
}
