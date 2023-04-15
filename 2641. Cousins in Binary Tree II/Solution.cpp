// Problem link: https://leetcode.com/problems/cousins-in-binary-tree-ii/description/

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
private:
    void solve1(TreeNode *root, int l, unordered_map <int, long long> &mp) {
        if(!root)
            return;
        
        mp[l] += root->val;
        
        solve1(root->left, l + 1, mp);
        solve1(root->right, l + 1, mp);
    }
    
    int ret_val(TreeNode *root, bool stat) {
        
        if(stat)
            return (root->right == NULL) ? 0 : root->right->val;
        
        else
            return (root->left == NULL) ? 0 : root->left->val;
    }
    
    void solve2(TreeNode *root, int v, int l, unordered_map <int, long long> &mp) {
        if(!root)
            return;
        
        int le = ret_val(root, true);
        int ri = ret_val(root, false);
        
        solve2(root->left, le, l + 1, mp);
        
        if(l >= 2)
            root->val = mp[l] - root->val - v;
        else
            root->val = 0;
        
        
        solve2(root->right, ri, l + 1, mp);
    }
    
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map <int, long long> mp;
        solve1(root, 0, mp);
        
        solve2(root, -1, 0, mp);
        
        return root;
    }
};
