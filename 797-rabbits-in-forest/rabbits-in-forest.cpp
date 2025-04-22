class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        int cnt = 0;
        unordered_map<int, int> freq;
        unordered_set<int> unique;
        for (int num : answers) {
            freq[num]++;
            unique.insert(num);
        }
        for (int num : unique) {
            if (freq[num] == 0)
                continue;
            int groupsize = num + 1;
            int rabbits = freq[num];
            if (rabbits <= num) {
                cnt += groupsize;
            } else {
                int grps = (rabbits + groupsize - 1) / groupsize;
                cnt += grps * groupsize;
            }
        }
        return cnt;
    }
};