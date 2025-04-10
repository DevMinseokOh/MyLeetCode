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
        if(root->left != nullptr)
            checkTree(result, root->left);
        if(root->right != nullptr)
            checkTree(result, root->right);

        result.push_back(root->val);

    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root != nullptr)
            checkTree(result, root);
        return result;
    }
};