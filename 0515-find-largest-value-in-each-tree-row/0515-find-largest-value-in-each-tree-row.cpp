/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void checkValues(vector<int>& res, queue<TreeNode*>& myQ) {
        int sizeQ = myQ.size();
        int biggerNum = INT_MIN;

        for (int i = 0; i < sizeQ; i++) {
            TreeNode* node = myQ.front();
            myQ.pop();
            if (biggerNum < node->val) {
                biggerNum = node->val;
            }

            if (node->left != nullptr)
                myQ.push(node->left);
            if (node->right != nullptr)
                myQ.push(node->right);
        }
        res.push_back(biggerNum);

        if (!myQ.empty())
            checkValues(res, myQ);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (root != nullptr) {
            queue<TreeNode*> myQ;
            myQ.push(root);
            checkValues(res, myQ);
        }
        return res;
    }
};