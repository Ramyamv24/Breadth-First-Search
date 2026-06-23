#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (i == 0) { // first node at this level
                    ans.push_back(node->val);
                }

                if (node->right) q.push(node->right);
                if (node->left) q.push(node->left);
            }
        }

        return ans;
    }
};

int main() {
    

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution sol;
    vector<int> result = sol.rightSideView(root);

    cout << "Right Side View: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}