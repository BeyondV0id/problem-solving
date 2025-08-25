# @leet imports start

# @leet imports end


# @leet start
class Solution:
    def longestSubarray(self, nums: List[int]) -> int:

        zeroCnt = 0
        maxLen = -1
        l = 0
        n = len(nums)
        for r in range(n):
            if nums[r] == 0:
                zeroCnt += 1
            while zeroCnt > 1:
                if nums[l] == 0:
                    zeroCnt -= 1
                l += 1
            maxLen = max(maxLen, r - l)
        return maxLen


# @leet end
