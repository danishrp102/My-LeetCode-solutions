// Problem link: https://leetcode.com/problems/linked-list-random-node/description/

// Reservoir sampling solution

class Solution {
private:
    ListNode *head;
public:

    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        int scope = 1, chosen = 0;
        ListNode *cur = head;
        while(cur) {
            double d = rand();
            if(d < RAND_MAX / scope)
                chosen = cur->val;
            scope++;
            cur = cur->next;
        }

        return chosen;
    }
};

// unoptimized space solution

class Solution {
private:
    int n;
    vector <int> v;
public:
    Solution(ListNode* head) {
        n = 0;
        while(head) {
            v.push_back(head->val);
            n++;
            head = head->next;
        }
    }
    
    int getRandom() {
        int val = rand() % n;
        return v[val];
    }
};
