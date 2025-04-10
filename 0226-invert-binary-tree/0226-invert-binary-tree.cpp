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
    void invert(TreeNode* n) {
        if (n->left != nullptr && n->right != nullptr) {
            TreeNode* temp = n->left;
            n->left = n->right;
            n->right = temp;

            invert(n->left);
            invert(n->right);
        } else if (n->left != nullptr && n->right == nullptr) {
            n->right = n->left;
            n->left = nullptr;
            invert(n->right);
        } else if (n->left == nullptr && n->right != nullptr) {
            n->left = n->right;
            n->right = nullptr;
            invert(n->left);
        }
    }
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* result = root;
        if (root != nullptr)
            invert(root);
        return result;
    }
};