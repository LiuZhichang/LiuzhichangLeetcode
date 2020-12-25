#include <iostream>
#include <string>
#include <stack>
#include <queue>
void reverse(std::string& str, int begin, int end) {
    while(begin < end) {
        std::swap(str[begin++], str[end--]);
    }
}
//std::string reverseParentheses(std::string s) {
//    std::queue<int> lp;
//    std::stack<int> rp;
//    std::string res;
//    for(int i = 0 ; i < s.size() ; i ++) {
//        if(s[i] == '(') {
//            lp.push(i + 1);
//        } else if(s[i] == ')') {
//            rp.push(i - 1);
//        }
//    }
//    while(!lp.empty()) {
//        reverse(s, lp.front(), rp.top());
//        lp.pop();
//        rp.pop();
//    }
//    for(auto& ch : s) {
//        if(ch == '(' || ch == ')')
//            continue;
//        res += ch;
//    }
//    return res;
//}

std::string reverseParentheses(std::string s) {
    std::string res;
    std::stack<std::string> stack;

    for(char& ch : s) {
        if(ch == '(') {
            stack.push(res);
            res = "";
        } else if(ch == ')') {
            reverse(res, 0, res.size() - 1);
            res = stack.top() + res;
            stack.pop();
        } else {
            res.push_back(ch);
        }
    }

    return res;

}

int main(int argc, char** argv) {
    std::string s{"(ed(et(oc))el)"};
    std::string res = reverseParentheses(s);
    std::cout << res << std::endl;
    return 0;
}
