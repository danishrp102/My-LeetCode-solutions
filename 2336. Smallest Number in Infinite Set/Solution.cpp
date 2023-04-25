// Problem link: https://leetcode.com/problems/smallest-number-in-infinite-set/description/

// Solution 1:

class SmallestInfiniteSet {
private:
    set <int> s;
    int mini;

public:
    SmallestInfiniteSet() {
        mini = 1;
    }
    
    int popSmallest() {
        if(!s.empty()) {
            int val = *s.begin();
            s.erase(val);
            return val;
        }

        else {
            mini++;
            return mini - 1;
        }
    }
    
    void addBack(int num) {
        if(mini > num)
            s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

// Solution 2:

class SmallestInfiniteSet {
private:
    priority_queue <int, vector <int>, greater <int> > pq;
    unordered_map <int, bool> mp;

public:
    SmallestInfiniteSet() {
        for(int i = 1; i <= 1000; i++) {
            mp[i] = true;
            pq.push(i);
        }
    }
    
    int popSmallest() {
        int val = pq.top();
        pq.pop();
        mp[val] = false;
        return val;
    }
    
    void addBack(int num) {
        if(!mp[num]) {
            mp[num] = true;
            pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
