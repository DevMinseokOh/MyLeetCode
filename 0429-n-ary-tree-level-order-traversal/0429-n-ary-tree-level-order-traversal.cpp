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
    queue<Node*> q;
    vector<vector<int>> result;

public:
    void checkTree(queue<Node*>& q) {
        vector<int> subResult;

        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            Node* node = q.front();
            q.pop();
            subResult.push_back(node->val);

            for (Node* node : node->children)
                q.push(node);
        }
        result.push_back(subResult);
    }
    vector<vector<int>> levelOrder(Node* root) {
        if (root != nullptr)
            q.push(root);

        while (!q.empty())
            checkTree(q);

        return result;
    }
};