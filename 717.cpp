#include <iostream>
#include <vector>
using std::vector;
bool isOneBitCharacter(vector<int>& bits) {
    int f = -1;
    int s = -1;
    for(int i = 0 ; i < bits.size() ;) {
        std::cout << i << std::endl;
        f = bits[i];
        if(i + 1 < bits.size())
            s = bits[i + 1];
        i += 2;
    }
    if(f != -1 && s == -1)
        return true;
    return false;
}
int main(int arg, char** argv) {
    vector<int> ex{1, 0, 0};
    std::cout << isOneBitCharacter(ex) << std::endl;
    return 0;
}
