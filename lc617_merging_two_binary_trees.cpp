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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        
        if(t1 && t2){
            struct TreeNode root((t1->val) + (t2->val));
            root.left = mergeTrees(t1->left, t2->left);
            root.right = mergeTrees(t1->right, t2->right);
            cout << "At t1 + t2 " << root.val <<endl;
            return &root;
        }
        
        else if(!t1 && t2) {
            struct TreeNode root(t2->val);
            root.left = mergeTrees(NULL, t2->left);
            root.right = mergeTrees(NULL, t2->right);
            cout<< "At t2 " << root.val <<endl;
            return &root;
        }
        
        else if(t1 && !t2) {
            struct TreeNode root(t1->val);
            root.left = mergeTrees(t1->left, NULL);
            root.right = mergeTrees(t1->right, NULL);
            cout<< "At t1 " << root.val <<endl;
            return &root;
        }
        
        else {
            return NULL;
        } 
        
    }
};
