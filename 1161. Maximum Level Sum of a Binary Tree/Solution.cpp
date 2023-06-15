// Problem link: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/

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
    int maxLevelSum(TreeNode* root) {
        int pos = -1, maxi = INT_MIN, ind = 1;
        queue <TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size(), sum = 0;
            for(int i = 0; i < n; i++) {
                TreeNode *tmp = q.front();
                q.pop();
                sum += tmp->val;
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }

            if(sum > maxi)
                maxi = sum, pos = ind;
            ind++;
        }

        return pos;
    }
};
