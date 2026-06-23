#include <iostream>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        queue<Node*> q;
        q.push(root);

        while (size(q)) {
            Node* rNode = nullptr;

            for (int i = size(q); i; i--) {
                auto cur = q.front();
                q.pop();

                cur->next = rNode;
                rNode = cur;

                if (cur->right) {
                    q.push(cur->right);
                    q.push(cur->left);
                }
            }
        }
        return root;
    }
};

int main() {
    

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution obj;
    root = obj.connect(root);

    // Print next pointers level by level
    Node* levelStart = root;

    while (levelStart) {
        Node* curr = levelStart;

        while (curr) {
            cout << curr->val << " -> ";
            if (curr->next)
                cout << curr->next->val << "  ";
            else
                cout << "NULL  ";

            curr = curr->next;
        }
        cout << endl;

        levelStart = levelStart->left;
    }

    return 0;
}