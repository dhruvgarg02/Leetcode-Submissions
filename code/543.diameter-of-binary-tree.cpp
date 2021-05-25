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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        pair<int, int> res = diameter(root);
        return max(res.first, res.second) - 1;
    }
    
private:
    pair<int, int> diameter (TreeNode* root) {
        if (root == NULL) return make_pair(0,0);
        pair<int, int> left = diameter(root->left);
        pair<int, int> right = diameter(root->right);
        
        int path_len = max(left.second, right.second);
        if (left.first + right.first + 1 > path_len) path_len = left.first + right.first + 1;
        
        return make_pair(max(left.first, right.first) + 1, path_len);
    }    
};