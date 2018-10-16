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
        if(current == NULL)
            return NULL;
        if(current->val == val)
            return current;
        TreeNode *left, *right;
        left = searchBST(current->left, val);
        if (left != NULL)
            return left;
        right = searchBST(current->right, val);
        if (right != NULL)
            return right; 
        return NULL;
    }
};
