// Problem link: https://leetcode.com/problems/search-suggestions-system/description/

// Sol1

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = products.size();
        sort(products.begin(), products.end());

        int N = searchWord.size();
        vector <vector <string> > ans(N);

        for(int i = 0; i < N; i++) {
            string tmp = searchWord.substr(0, i + 1);
            for(int j = 0; j < n; j++) {
                if(ans[i].size() == 3)
                    break;
                
                if(products[j].substr(0, i + 1) == tmp)
                    ans[i].push_back(products[j]);
            }
        }

        return ans;
    }
};


// Sol2

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector <vector <string> > ans;
        auto it = products.begin();
        sort(it, products.end());

        int N = searchWord.size();
        for(int i = 0; i < N; i++) {
            string tmp = searchWord.substr(0, i + 1);

            vector <string> v;
            it = lower_bound(it, products.end(), tmp);
            for(int j = 0; j < 3 && it + j != products.end(); j++) {
                string &s = *(it + j);
                if(s.find(tmp) != 0)
                    break;
                v.push_back(s);
            }

            ans.push_back(v);
        }

        return ans;
    }
};
