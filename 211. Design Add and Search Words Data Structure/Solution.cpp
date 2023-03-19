// Problem link: https://leetcode.com/problems/design-browser-history/description/

class WordDictionary {

private:
    struct TrieNode {
        struct TrieNode *child[26];
        bool isEnd;
    };

    TrieNode *node;

public:
    WordDictionary() {
        node = new TrieNode();    
    }
    
    void addWord(string word) {
        TrieNode *cur = node;
        for(char c: word) {
            if(cur->child[c - 'a'] == NULL)
                cur->child[c - 'a'] = new TrieNode();
            cur = cur->child[c - 'a'];
        }

        cur->isEnd = true;
    }

    bool solve(const char *word, TrieNode *cur) {

        for(int i = 0; word[i] && cur; i++) {
            if(word[i] != '.')
                cur = cur->child[word[i] - 'a'];
            else {
                TrieNode *tmp = cur;
                for(int j = 0; j < 26; j++) {
                    cur = tmp->child[j];
                    if(solve(word + i + 1, cur))
                        return true;
                }
            }
        }

        return cur && cur->isEnd;
    }
    
    bool search(string word) {
        TrieNode *cur = node;
        int n = word.size();
        return solve(word.c_str(), cur);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
