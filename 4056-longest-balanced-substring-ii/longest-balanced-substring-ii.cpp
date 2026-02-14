#include <bits/stdc++.h>
using namespace std;

int pairSolve(const string& s, char a, char b) {
    if(s.size() == 1)
        return 1;
    map<int,int> mp;
    mp[0] = -1;

    int aCnt = 0, bCnt = 0;
    int res = 0;

    for(int i = 0; i < s.size(); i++) {
        if(s[i]!=a && s[i]!=b){
            mp.clear();
            mp[0] = i;
            aCnt = 0;
            bCnt = 0;
            continue;
        }
        if(s[i] == a) aCnt++;
        if(s[i] == b) bCnt++;

        int diffAB = aCnt - bCnt;

        if(mp.count(diffAB))
            res = max(res, i - mp[diffAB]);
        else
            mp[diffAB] = i;
    }
    return res;
}

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxi = 0;

        int cnt = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1])
                cnt++;
            else
                cnt = 1;
            maxi = max(maxi, cnt);
        }

        maxi = max(maxi, pairSolve(s, 'a', 'b'));
        maxi = max(maxi, pairSolve(s, 'b', 'c'));
        maxi = max(maxi, pairSolve(s, 'a', 'c'));

        map<pair<int,int>,int> preMap;
        preMap[{0,0}] = -1;

        int aCnt = 0, bCnt = 0, cCnt = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') aCnt++;
            if (s[i] == 'b') bCnt++;
            if (s[i] == 'c') cCnt++;

            int diffAB = aCnt - bCnt;
            int diffAC = aCnt - cCnt;

            pair<int,int> key = {diffAB, diffAC};

            if (preMap.count(key))
                maxi = max(maxi, i - preMap[key]);
            else
                preMap[key] = i;
        }

        return maxi;
    }
};
