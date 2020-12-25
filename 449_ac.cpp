#include <iostream>
#include "Tree.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;
class Codec {
    TreeNode* rebuildTree(stringstream &ss) {
        string tmp;
        ss >> tmp;
        if(tmp == "#")
            return nullptr;

        TreeNode* node = new TreeNode(stoi(tmp));
        node->left = rebuildTree(ss);
        node->right = rebuildTree(ss);

        return node;
    }

  public:
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return "#";

        return std::to_string(root->val) + ' ' + serialize(root->left) + ' ' + serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return rebuildTree(ss);
    }
};

int main(int argc, char* argv[]) {

    Codec c;
    Tree t(vector<Data> {2, 1, 3});
    std::cout << c.serialize(t.getRoot()) << std::endl;

    return 0;
}
