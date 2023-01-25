// Problem link: https://leetcode.com/problems/delete-leaves-with-a-given-value/description/

class Solution {
public:

    bool solve(TreeNode *root, int target) {
        int l = true, r = true;

        if(!root->left && !root->right) {   // redundant if block - if it is removed, runtime increases
            if(root->val == target)
                return false;
            else
                return true;
        }

        if(!root->left)
            l = false;
        else
            l = solve(root->left, target);

        if(!root->right)    
            r = false;
        else 
            r = solve(root->right, target);

        if(!l && !r) {
            root->left = root->right = NULL;
            if(root->val == target)
                return false;
        }

        else if(!l)
            root->left = NULL;
        else if(!r)
            root->right = NULL;
        
        return true;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        solve(root, target);

        if(!root->left && !root->right && root->val == target)
            return NULL;

        return root;
    }
};
