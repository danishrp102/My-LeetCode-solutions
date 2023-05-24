// Problem link: https://leetcode.com/problems/maximum-subsequence-score/description/

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;
        int n = nums1.size();
        vector <pair <int, int> > v1(n), v2(n);
        vector <int> v(n);

        for(int i = 0; i < n; i++) {
            v1[i] = make_pair(nums1[i], i);
            v2[i] = make_pair(nums2[i], i);
        }

        sort(v2.begin(), v2.end(), greater <pair <int, int> >());
        for(int i = 0; i < n; i++)
            v[i] = nums1[v2[i].second];

        long long sum = 0, ans = -1ll;

        for(int i = 0; i < k - 1; i++) {
            pq.push(make_pair(v[i], i));
            sum += v[i];
        }
        
        for(int i = k - 1; i < n; i++) {
            long long tmp = (sum + v[i]) * v2[i].first;
            ans = max(ans, tmp);
            
            if(k > 1) {
                if(pq.top().first < v[i]) {
                    sum -= v[pq.top().second];
                    pq.pop();
                    pq.push(make_pair(v[i], i));
                    sum += v[i];
                }
            }
        }

        return ans;
    }
};
