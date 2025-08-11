// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>res;
        int l=0,r=arr.size()-k;
        while(l<r){
            int mid = l + (r-l)/2;
            if(x - arr[mid] <= arr[mid + k] - x)
                r = mid;
            else {
                l = mid+1;
            }
        }
        return vector<int>(arr.begin()+l,arr.begin()+l+k);
    }
};
// @leet end
