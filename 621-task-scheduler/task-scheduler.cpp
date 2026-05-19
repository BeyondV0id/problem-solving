#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (auto& it : tasks) {
            freq[it]++;
        }
        priority_queue<int> pq;
        for (auto& it : freq) {
            pq.push(it.second);
        }
        int time = 0;
        while (!pq.empty()) {
            vector<int> tempFreqStorage;
            int taskSet = n + 1;
            int tasksDone = 0;

            for (int i = 0; i < taskSet; i++) {
                if (!pq.empty()) {
                    int taskfreq = pq.top();
                    pq.pop();
                    tasksDone++;
                    tempFreqStorage.push_back(taskfreq);
                }
            }

            for (auto it : tempFreqStorage) {
                if (it > 1)
                    pq.push(it - 1);
            }

            time += pq.empty() ? tasksDone : taskSet;
        }
        return time;
    }
};
