#pragma once

#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <functional>

using std::stack;
using std::queue;
using std::vector;

#define log(info) \
	std::cout << info << std::endl;
struct Data {
  private:
    int* data;
  public:
    Data(int val): data(new int(val)) {}
    Data(int* ptr): data(ptr) {}
    int* val() {
        return data;
    }
};
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void TreeLevelOrder(TreeNode* node);

class Tree {
    TreeNode* createTree(std::vector<Data>& v, int begin) {
        if(v.empty())
            return nullptr;
        if(v[begin].val() == nullptr)
            return nullptr;
        TreeNode* root = new TreeNode(*v[begin].val());
        int lnode = (begin << 1) + 1;
        int rnode = (begin << 1) + 2;

        if(lnode > v.size() - 1)
            root->left = nullptr;
        else
            root->left = createTree(v, lnode);

        if(rnode > v.size() - 1)
            root->right = nullptr;
        else
            root->right = createTree(v, rnode);
        return root;
    }


    void PrintTree(TreeNode* root, int h) {
        if(root == NULL) {
            return;
        }
        PrintTree(root->right, h + 1);
        for(int i = 0; i < h; i++)
            std::cout << " ";
        std::cout << root->val << std::endl;
        PrintTree(root->left, h + 1);
    }

    void dfsPreorder(TreeNode* root, std::vector<int>& v) {
        if(root == nullptr)
            return;
        v.push_back(root->val);
        dfsPreorder(root->left, v);
        dfsPreorder(root->right, v);
    }

    TreeNode* root;
  public:
    Tree(): root(nullptr) {}
    Tree(vector<Data>& v) {
        root = createTree(v, 0);
    }
    Tree(vector<Data>&& v) {
        root = createTree(v, 0);
    }
    TreeNode* getRoot() const {
        return root;
    }
    vector<int> PreOrder();
    vector<int> preOrder();
    vector<int> InOrder();
    vector<int> levelOrder();
    void levelPrint();
    void Print() {
        PrintTree(root, 0);
    }
};

vector<int> Tree::PreOrder() {
    vector<int> v;
    if(root == nullptr)
        return v;
    stack<TreeNode*> s;
    TreeNode* node = root;
    while(node || !s.empty()) {
        while(node) {
            v.push_back(node->val);
            s.push(node);
            node = node->left;
        }
        TreeNode* temp = s.top();
        s.pop();
        node = temp->right;
    }
    return v;

}

vector<int> Tree::preOrder() {
    vector<int> v;
    dfsPreorder(root, v);
    return v;
}

vector<int> Tree::InOrder() {
    vector<int> v;
    if(root == nullptr)
        return v;
    stack<TreeNode*> s;
    TreeNode* node = root;
    while(node || !s.empty()) {
        while(node) {
            s.push(node);
            node = node->left;
        }
        TreeNode* temp = s.top();
        s.pop();
        if(temp)
            v.push_back(temp->val);
        node = temp->right;
    }
    return v;

}

vector<int> Tree::levelOrder() {
    vector<int> v;
    if(root == nullptr)
        return v;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        v.push_back(node->val);
        q.pop();
        if(node->left != nullptr)
            q.push(node->left);
        if(node->right != nullptr)
            q.push(node->right);
    }
    return v;

}

void Tree::levelPrint() {
    if(root == nullptr)
        return;
    queue<TreeNode*> q;
    vector<vector<int>>vec;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        vector<int> v;
        while(size--) {
            TreeNode* node = q.front();
            q.pop();
            v.push_back(node->val);
            for(auto& children : {
                        node->left, node->right
                    }) {
                if(children)
                    q.push(children);
            }
        }
        vec.push_back(v);
    }

    int size = vec.size();
    while(size--) {
        int i = size + 1;
        while(i--) {
            std::cout << " ";
        }
        int cur = vec.size() - 1 - size;
        for(auto item : vec[cur]) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
}

void TreeLevelOrder(TreeNode* node) {
    if(!node)
        return ;
    queue<TreeNode*> q;
    q.push(node);
    while(!q.empty()) {
        TreeNode* n = q.front();
        q.pop();
        std::cout << n->val << "\t";
        for(auto item : {
                    n->left, n->right
                }) {
            if(item)
                q.push(item);
        }
    }
    std::cout << std::endl;
}
