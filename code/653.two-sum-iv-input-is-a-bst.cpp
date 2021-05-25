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
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        inorder = traverse(root, inorder);
        for (auto i = inorder.begin(); i != inorder.end(); i++) cout<<*i<<" ";
        int l = 0, r = inorder.size() - 1;
        while(r > l) {
            if (inorder[l] + inorder[r] == k) return true;
            if (inorder[l] + inorder[r] > k) r--;
            if (inorder[l] + inorder[r] < k) l++;
        }
        return false;
    }

private:
    vector<int> traverse (TreeNode* root, vector<int>& inorder) {
        if (!root) return inorder;

        if (left) traverse(root->left, inorder);
        inorder.push_back(root->val);
        if (right) traverse(root->right, inorder);
        return inorder;
    }
};