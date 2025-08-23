# @leet imports start
from string import *
from collections import *
from math import *
from statistics import *
from itertools import *
from functools import *
import datetime
import collections
import math

# @leet imports end


# @leet start
class Twitter:

    def __init__(self):
        self.time = 0
        self.following = {}
        self.tweets = {}

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.time += 1
        if userId not in self.tweets:
            self.tweets[userId] = []
        self.tweets[userId].append((self.time, tweetId))

    def getNewsFeed(self, userId: int) -> List[int]:
        news = []
        if userId not in self.following:
            self.following[userId] = set()
        follwees = self.following[userId] | {userId}

        for uid in follwees:
            if uid not in self.tweets:
                self.tweets[uid] = []
            for tweets in self.tweets[uid]:
                news.append(tweets)

        news.sort(key=lambda x: x[0], reverse=True)
        top10news = news[:10]
        return [tweetId for _, tweetId in top10news]

    def follow(self, followerId: int, followeeId: int) -> None:
        if followerId not in self.following:
            self.following[followerId] = set()
        self.following[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if (
            followerId in self.following
            and followeeId in self.following[followerId]
            and followerId != followeeId
        ):
            self.following[followerId].remove(followeeId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
# @leet end
