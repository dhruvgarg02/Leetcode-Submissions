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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = inorder.size();
        return helper(preorder, inorder, 0, len-1, 0, len-1);
    }

private:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
        if (inStart > inEnd) return NULL;
        
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);
        
        int rootIndex;
        for (rootIndex = inStart; rootIndex <= inEnd; rootIndex++)
            if (inorder[rootIndex] == rootVal) break;
        
        int leftTreeSize = rootIndex - inStart;
        int rightTreeSize = inEnd - rootIndex;
        
        root->left = helper(preorder, inorder, preStart + 1, preStart + leftTreeSize, inStart, rootIndex-1);
        root->right = helper(preorder, inorder, preEnd - rightTreeSize + 1, preEnd, rootIndex + 1, inEnd);
        
        return root;
    }
};