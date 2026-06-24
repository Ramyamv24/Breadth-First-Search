#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};

        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> curr;

            for (int i = 0; i < size; i++) {
                Node* t = q.front();
                q.pop();

                curr.push_back(t->val);

                for (auto r : t->children)
                    q.push(r);
            }

            res.push_back(curr);
        }

        return res;
    }
};

int main() {
    

    Node* root = new Node(1);

    Node* node3 = new Node(3);
    Node* node2 = new Node(2);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);

    node3->children = {node5, node6};
    root->children = {node3, node2, node4};

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    cout << "Level Order Traversal:\n";
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}