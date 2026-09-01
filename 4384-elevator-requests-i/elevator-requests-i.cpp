class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int cnt = 0;

        cnt = requests[0];

        for (int i = 1; i < requests.size(); i++) {
            cnt += abs(requests[i] - requests[i - 1]);
        }
        return cnt;
    }
};