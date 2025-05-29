class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();
        for (auto& it : nums)
            freq[it]++;
        auto comp=[&](int a, int b) { return freq[a] < freq[b]; };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        for (auto& it : freq) {
            pq.push(it.first);
        }
        vector<int> res;
        while (k-- && !pq.empty()) {
            int num = pq.top();
            res.push_back(num);
            pq.pop();
        }
        return res;
    }
}

;