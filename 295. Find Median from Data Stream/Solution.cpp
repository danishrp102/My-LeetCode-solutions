class MedianFinder {
public:

    priority_queue <int> pq1; // max heap
    priority_queue <int, vector <int>, greater <int> > pq2; // min heap

    MedianFinder() {
        pq1 = priority_queue <int>();
        pq2 = priority_queue <int, vector <int>, greater <int> >();
    }
    
    void addNum(int num) {
        int n1 = pq1.size(), n2 = pq2.size();
        if(n1 == n2) {
            if(n1 == 0 || num <= pq1.top())
                pq1.push(num);
            else
                pq2.push(num);
        }

        else if(n1 > n2) {
            if(num <= pq1.top()) {
                pq2.push(pq1.top());
                pq1.pop();
                pq1.push(num);
            }
            else
                pq2.push(num);
        }

        else {
            if(num >= pq2.top()) {
                pq1.push(pq2.top());
                pq2.pop();
                pq2.push(num);
            }
            else
                pq1.push(num);
        }
    }
    
    double findMedian() {
        int n1 = pq1.size(), n2 = pq2.size();
        if((n1 + n2) & 1) {
            double ans;
            if(n1 < n2) {
                ans = pq2.top();
                return ans;
            }

            else {
                ans = pq1.top();
                return ans;
            }
        }

        else {
            double ans = (pq1.top() + pq2.top()) / double(2);
            return ans;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
