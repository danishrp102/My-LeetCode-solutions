// Problem link: https://leetcode.com/problems/delete-nodes-and-return-forest/description/

class Solution {
public:

    void solve(TreeNode *root, unordered_map <int, TreeNode*> &parent, TreeNode *par) {

        parent[root->val] = par;

        if(root->left)
            solve(root->left, parent, root);
        if(root->right)
            solve(root->right, parent, root);
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector <TreeNode*> ans;

        if(!root)
            return ans;
        
        unordered_map <int, TreeNode*> parent, mp;
        mp[root->val] = root;
        
        solve(root, parent, NULL);

        for(auto x: to_delete) {

            if(mp.find(x) != mp.end()) {

                TreeNode *node = mp[x];

                if(node->left) {
                    parent[node->left->val] = NULL;
                    mp[node->left->val] = node->left;
                    node->left = NULL;
                }

                if(node->right) {
                    parent[node->right->val] = NULL;
                    mp[node->right->val] = node->right;
                    node->right = NULL;
                }

                if(!node->left && !node->right) {
                    mp.erase(x);
                }
            }

            else {

                TreeNode *tmp = parent[x];
                TreeNode *node;

                if(tmp->left != NULL && tmp->left->val == x) {
                    node = tmp->left;
                    tmp->left = NULL;
                    parent[x] = NULL;
                }

                else {
                    node = tmp->right;
                    tmp->right = NULL;
                    parent[x] = NULL;
                }

                if(node->left) {
                    parent[node->left->val] = NULL;
                    mp[node->left->val] = node->left;
                    node->left = NULL;
                }

                if(node->right) {
                    parent[node->right->val] = NULL;
                    mp[node->right->val] = node->right;
                    node->right = NULL;
                }

                if(!node->left && !node->right) {
                    mp.erase(x);
                }
            }
        }

        for(auto [x, y]: mp) {
            ans.push_back(y);
        }

        return ans;
    }
};
