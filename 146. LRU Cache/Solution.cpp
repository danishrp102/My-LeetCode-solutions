// Problem link: 

class LRUCache {

private:
    int cap;
    int counter;
    set <pair <int, int> > s; // counter, key
    unordered_map <int, pair <int, int> > mp; // value, counter

public:
    LRUCache(int capacity) {
        cap = capacity;
        counter = 0;
    }
    
    int get(int key) {
        counter++;

        if(mp.find(key) == mp.end())
            return -1;

        int v = mp[key].first;
        int coun = mp[key].second;

        auto x = s.find(make_pair(coun, key));
        s.erase(x);
        mp[key] = make_pair(v, counter);
        s.insert(make_pair(counter, key));

        return v;
    }
    
    void put(int key, int value) {
        counter++;

        if(mp.find(key) != mp.end()) {
            int v = mp[key].first;
            int coun = mp[key].second;

            auto x = s.find(make_pair(coun, key));
            s.erase(x);
            mp[key] = make_pair(value, counter);
            s.insert(make_pair(counter, key));
        }

        else {
            if(s.size() >= cap) {
                auto x = *s.begin();
                mp.erase(x.second);
                s.erase(s.begin());
            }

            mp[key] = make_pair(value, counter);
            s.insert(make_pair(counter, key));
        }   
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
