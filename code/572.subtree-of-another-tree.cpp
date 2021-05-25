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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s) return false;
        else if (isSame(s, t)) return true;
        else return (isSubtree(s->left, t) or isSubtree(s->right, t));
    }
    
private:
    bool isSame(TreeNode* s, TreeNode* t) {
        if (!s or !t) return (!s and !t);
        if (s->val == t->val) return (isSame(s->left, t->left) and isSame(s->right, t->right));
        return false;
    }
};