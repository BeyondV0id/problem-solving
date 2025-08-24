# @leet imports start
from string import *
from re import *
from datetime import *
from collections import *
from heapq import *
from bisect import *
from copy import *
from math import *
from random import *
from statistics import *
from itertools import *
from functools import *
from operator import *
from io import *
from sys import *
from json import *
from builtins import *
import string
import re
import datetime
import collections
import heapq
import bisect
import copy
import math
import random
import statistics
import itertools
import functools
import operator
import io
import sys
import json
from typing import *
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
            while(zeroCnt > 1):
                if nums[l] == 0:
                    zeroCnt -= 1
                l += 1
            maxLen = max(maxLen,r-l)
        return maxLen

        
# @leet end
