/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode *current = root;
        
        if(!current)
            return NULL;
        
        while (current->val != val) {
            if (val < current->val) 
                current = current->left;
            else if (val > current->val)
                current = current->right;
            if(!current)
                break;
        }
        
        return current;   
    }
};
