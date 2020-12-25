#include <iostream>
#include <vector>
#include <string>
#include <map>
/*
* leetcode 1079 活字印刷
* 你有一套活字字模 tiles，其中每个字模上都刻有一个字母 tiles[i]。返回你可以印出的非空字母序列的数目。
*
* 注意：本题中，每个活字字模只能使用一次。
*
* 
*
* 示例 1：
*
* 输入："AAB"
* 输出：8
* 解释：可能的序列为 "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA"。
*
*/
int dfsCount(std::vector<int>& ch_count) {
    int count = 0;
    for(int i = 0 ; i < ch_count.size() ; ++ i) {
        if(ch_count[i] == 0)
            continue;
        ++count;
        -- ch_count[i];
        count += dfsCount(ch_count);
        ++ ch_count[i];
    }

    return count;
}

int numTilePossiblities(std::string tiles) {
    std::vector<int> ch_count(26, 0);
    for(const auto tile : tiles) {
        ch_count[tile - 'A']++;
    }
    return dfsCount(ch_count);
}

int main(int argc, char *argv[]) {

    std::string str = "AAB";
    std::cout << numTilePossiblities(str) << std::endl;

    return 0;
}
