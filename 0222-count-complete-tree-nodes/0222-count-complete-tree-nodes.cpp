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
    void checkTree(int& result, TreeNode* root) {
        if (root->left != nullptr) {
            result++;
            checkTree(result, root->left);
        }
        if (root->right != nullptr) {
            result++;
            checkTree(result, root->right);
        }
    }
    int countNodes(TreeNode* root) {
        int result = 0;
        if (root != nullptr) {
            result++;
            checkTree(result, root);
        }
        return result;
    }
};