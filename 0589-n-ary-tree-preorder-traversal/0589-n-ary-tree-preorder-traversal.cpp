/*
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
*/

class Solution {
    vector<int> result;

public:
    void checkTree(Node* root) {
        result.push_back(root->val);

        for (Node* p : root->children)
            checkTree(p);
    }
    vector<int> preorder(Node* root) {
        if (root != nullptr)
            checkTree(root);
        return result;
    }
};