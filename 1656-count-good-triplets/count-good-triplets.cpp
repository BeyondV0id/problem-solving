class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int cnt = 0;
        for (int i = 0; i < arr.size() - 2; i++)
            for (int j = i + 1; j < arr.size() - 1; j++)
                for (int k = j + 1; k < arr.size(); k++) {
                    int firstPair = abs(arr[i]-arr[j]);
                    int secondPair = abs(arr[j]-arr[k]);
                    int thirdPair = abs(arr[i]-arr[k]);
                    if(firstPair<=a && secondPair <=b && thirdPair <= c)
                        cnt++;

                }
        return cnt;
    }
};