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
    bool checkTree(TreeNode* p, TreeNode* q) {
        bool result = true;
        if (p != nullptr && q != nullptr) {
            if (p->val != q->val)
                result = false;
            else
                result = (checkTree(p->left, q->left) &&
                          checkTree(p->right, q->right));
        } else if ((p != nullptr && q == nullptr) ||
                   (p == nullptr && q != nullptr))
            result = false;

        return result;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) { return checkTree(p, q); }
};