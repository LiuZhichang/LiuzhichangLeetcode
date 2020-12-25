#include <cstdlib>
#include <iostream>
#include "Tree.h"
#include <string>
using std::string;
class Codec {
  public:
    void resolver(string& s, vector<int>& v) {
        int data = 0;
        char flag = '|';
        string temp = "";
        for(int i = 0 ; i < s.size() ; i++) {
            if(s[i] != flag)
                temp += s[i];
            else {
                if(temp != "") {
                    if(temp == " ") {
                        v.push_back(-1);
                    } else {
                        v.push_back(std::stoi(temp));
                    }
                }
                temp = "";
            }
        }
    }
    TreeNode* createTree(vector<int>& v, int idx) {
        if(v[idx] == -1)
            return nullptr;
        TreeNode* root = new TreeNode(v[idx]);
        int l = (idx << 1) + 1;
        int r = (idx << 1) + 2;
        root->left = (l > v.size() - 1) ? nullptr : createTree(v, l);
        root->right = (r > v.size() - 1) ? nullptr : createTree(v, r);
        return root;
    }
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "";
        string res;
        queue<TreeNode*> q;
        q.push(root);
        string flag = "|";
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            if(!node) {
                res += flag + " ";
            } else {
                res += flag + std::to_string(node->val);
                for(auto item : {
                            node->left, node->right
                        })
                    q.push(item);
            }
        }
        res += flag;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty() || data == "")
            return nullptr;
        vector<int> v;
        resolver(data, v);
        return createTree(v, 0);
    }
};
int main(int argc, char* argv[]) {

    Tree t(vector<Data> {5, 3, 6, 2, 4, nullptr, nullptr, 1});
    Codec c;
    string res =  c.serialize(t.getRoot());
    std::cout << res << std::endl;
    TreeLevelOrder(c.deserialize(res));
    return 0;
}
