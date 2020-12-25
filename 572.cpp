#include <iostream>
#include "Tree.h"


void dfs(TreeNode* s, TreeNode* t, bool res) {
    if(!s || !t)
        return;
    std::cout << s->val << " " << t->val << std::endl;
    if(s->val == t->val)
        res = true;
    else
        res = false;
    dfs(s->left, t->left, res);
    dfs(s->right, t->right, res);
}
bool isSubtree(TreeNode* s, TreeNode* t) {
    if(!t && !s)
        return true;
    stack<TreeNode*> st;
    while(s || !st.empty()) {
        while(s) {
            if(s->val == t->val) {
                bool res;
                dfs(s, t, res);
                return res;
            }
            st.push(s);
            s = s->left;
        }
        s = st.top()->right;
        st.pop();
    }


    return false;
}

int main(int argc, char* argv[]) {

    vector<Data> v1{3, 4, 5, 1, 2};
    vector<Data> v2{4, 1, 2};

    Tree t1(v1);
    Tree t2(v2);

    t1.Print();
    std::cout << "--------------" << std::endl;
    t2.Print();
    std::cout << "--------------" << std::endl;
    std::cout << isSubtree(t1.getRoot(), t2.getRoot()) << std::endl;;
    return 0;
}
