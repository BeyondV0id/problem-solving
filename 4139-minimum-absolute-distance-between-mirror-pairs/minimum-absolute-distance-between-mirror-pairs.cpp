class Solution {
private:
    int rev(int x) {
        int r = 0;
        while (x > 0) {
            r = r * 10 + (x % 10);
            x /= 10;
        }
        return r;
    }

public:
    int minMirrorPairDistance(vector<int>& nums) {

        unordered_map<int,int> indexMap;
        int res = INT_MAX;

        for (int i = nums.size() - 1; i >= 0; i--) {
            int reverse = rev(nums[i]);
            if (indexMap.count(reverse))
                res = min(res, indexMap[reverse] - i);

            if (!indexMap.count(nums[i]))
                indexMap[nums[i]] = i;
        }

        return res == INT_MAX ? -1 : res;
    }
};
