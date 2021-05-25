/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return false;
        return helper(root->left, LONG_MIN, root->val) and helper(root->right, root->val, LONG_MAX);
    }

private:
    bool helper(TreeNode* root, long min, long max) {
        if (!root) return true;
        else if(root->val <= min or root->val >= max) return false;
        else return (helper(root->left, min, root->val) and helper(root->right, root->val, max));
    }
};