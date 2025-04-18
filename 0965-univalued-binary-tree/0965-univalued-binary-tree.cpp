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
    int n = 0;

public:
    bool checkTree(TreeNode* root) {
        bool result = true;
        if (root != nullptr) {
            if (n != root->val) {
                result = false;
            } else
                result = checkTree(root->left) && checkTree(root->right);
        }
        return result;
    }
    bool isUnivalTree(TreeNode* root) {
        bool result = true;
        if (root != nullptr) {
            n = root->val;
            result = checkTree(root->left) && checkTree(root->right);
        }
        return result;
    }
};