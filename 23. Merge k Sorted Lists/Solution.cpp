// Problem link: https://leetcode.com/problems/merge-k-sorted-lists/description/

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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
        
        int n = lists.size();
        
        while(n > 1) {
            
            for(int i = 0; i < n / 2; i++)
                lists[i] = merge(lists[i], lists[n - i - 1]);

            n = (n + 1) / 2;
        }

        return lists.front();
    }

    ListNode *merge(ListNode *l1, ListNode *l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        
        if(l1->val <= l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        }

        else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
};
