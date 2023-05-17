// Problem link: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/

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
private:
    ListNode *solve(ListNode *node) {
        ListNode *prev = NULL, *next = NULL, *cur = node;

        while(cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }

public:
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head;
        
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        slow = solve(slow);
        int ans = INT_MIN;

        while(slow) {
            ans = max(ans, slow->val + head->val);
            slow = slow->next;
            head = head->next;
        }

        return ans;
    }
};
