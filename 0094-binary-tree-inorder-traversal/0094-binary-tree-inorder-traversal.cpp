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
    void checkTree(vector<int>& result, TreeNode* root) {
        if (root->left != nullptr)
            checkTree(result, root->left);

        result.push_back(root->val);

        if (root->right != nullptr)
            checkTree(result, root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root != nullptr) {
            checkTree(result, root);
        }

        return result;
    }
};