class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long>pq;

        for(auto num : nums){
            pq.push(num);
        }

        long long cnt = 0;

        while(!pq.empty() && k > 0){
            long long top = pq.top();
            pq.push(ceil(top/3.0));
            pq.pop();
            cnt += top;
            k--;
        }

        return cnt;
        
    }
};