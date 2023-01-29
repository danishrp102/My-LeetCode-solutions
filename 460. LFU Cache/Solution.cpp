// Problem link: https://leetcode.com/problems/lfu-cache/description/

class LFUCache {

private:

    int cap;
    int counter;
    unordered_map <int, pair <int, pair <int, int> > > mp; // value, freq, counter
    set <pair <int, pair <int, int> > > s; // freq, counter, key

public:
    LFUCache(int capacity) {
        cap = capacity;
        counter = 0;
    }
    
    int get(int key) {
        if(cap == 0)
            return -1;

        counter++;

        if(mp.find(key) == mp.end())
            return -1;

        int v = mp[key].first;
        int freq = mp[key].second.first;
        int coun = mp[key].second.second;

        auto x = s.find(make_pair(freq, make_pair(coun, key)));
        s.erase(x);
        mp[key] = make_pair(v, make_pair(freq + 1, counter));
        s.insert(make_pair(freq + 1, make_pair(counter, key)));

        return v;
    }
    
    void put(int key, int value) {
        if(cap == 0)
            return;
        
        counter++;

        if(mp.find(key) != mp.end()) {
            auto x = mp[key];
            int freq = x.second.first;
            int coun = x.second.second;

            auto y = s.find(make_pair(freq, make_pair(coun, key)));
            s.erase(y);
            mp[key] = make_pair(value, make_pair(freq + 1, counter));
            s.insert(make_pair(freq + 1, make_pair(counter, key)));
        }

        else {
            if(s.size() >= cap) {
                auto x = *s.begin();
                int k = x.second.second;
                s.erase(s.begin());
                mp.erase(k);
            }

            mp[key] = make_pair(value, make_pair(1, counter));
            s.insert(make_pair(1, make_pair(counter, key)));
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
