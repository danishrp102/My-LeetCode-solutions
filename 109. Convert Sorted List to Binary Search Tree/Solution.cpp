// Problem link: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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


    ListNode *list;

    TreeNode *solve(int n) {
        if(n == 0)
            return NULL;
        
        TreeNode *tmp = new TreeNode(0);
        tmp->left = solve(n / 2);
        tmp->val = list->val;
        list = list->next;
        tmp->right = solve(n - n / 2 - 1);
        return tmp;
    }


    TreeNode* sortedListToBST(ListNode* head) {
        this->list = head;
        int n = 0;
        ListNode *tmp = head;
        while(tmp) {
            n++;
            tmp = tmp->next;
        }

        return solve(n);
    }
};
