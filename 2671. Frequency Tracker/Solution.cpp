// Problem link: https://leetcode.com/problems/frequency-tracker/description/

class FrequencyTracker {
private:
    unordered_map <int, int> mp1, mp2;
    
public:
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        mp2[mp1[number]]--;
        mp1[number]++;
        mp2[mp1[number]]++;
    }
    
    void deleteOne(int number) {
        if(mp1[number]) {
            mp2[mp1[number]]--;
            mp1[number]--;
            mp2[mp1[number]]++;
        }
    }
    
    bool hasFrequency(int frequency) {
        return (mp2[frequency] > 0);
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
