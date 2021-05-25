/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "X,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream s(data);
        return deserialize_util(s);
    }
    
private:
    
    TreeNode* deserialize_util(stringstream& s) {
        string str;
        getline(s, str, ',');
        if (str == "X") return NULL;
        else {
            TreeNode* node = new TreeNode(stoi(str));
            node->left = deserialize_util(s);
            node->right = deserialize_util(s);
            return node;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));