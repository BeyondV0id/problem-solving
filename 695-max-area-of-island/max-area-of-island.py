# @leet imports start
from string import *
import string
import re
import collections
import bisect
import math
import operator
from typing import *

# @leet imports end


# @leet start
class Solution:
    def __init__(self):
        self._maxarea = 0
        self._directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        R, C = len(grid), len(grid[0])

        def _dfs(r, c):
            if r < 0 or c < 0 or r >= R or c >= C or grid[r][c] == 0:
                return 0
            area = 1
            grid[r][c] = 0
            for dr, dc in self._directions:
                area += _dfs(r + dr, c + dc)
            return area

        for r in range(R):
            for c in range(C):
                if grid[r][c] == 1:
                    self._maxarea = max(self._maxarea, _dfs(r, c))
        return self._maxarea


# @leet end
