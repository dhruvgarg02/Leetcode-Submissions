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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        
        else if(root->val > key) root->left = deleteNode(root->left, key);
        else if(root->val < key) root->right = deleteNode(root->right, key);
        else {
            if (!root->left and !root->right) return NULL;
            else if (!root->left and root->right) return root->right;
            else if (!root->right and root->left) return root->left;
            else {
                root->val = findMax(root->left, INT_MIN);
                root->left = deleteNode(root->left, root->val);
                return root;
            }
        }
        return root;
    }

private:
    int findMax(TreeNode* root, int maximum) {
        while(root) {
            maximum = max(maximum, root->val);
            root = root->right;
        }
        return maximum;
    }
};