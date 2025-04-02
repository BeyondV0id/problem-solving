class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>lesser;
        vector<int>middle;
        vector<int>greater;
        for(int num:nums){
            if(num<pivot) lesser.push_back(num);
            else if(num == pivot) middle.push_back(num);
            else greater.push_back(num);
        }
        vector<int>result;
        result.insert(result.end(),lesser.begin(),lesser.end());
        result.insert(result.end(),middle.begin(),middle.end());
        result.insert(result.end(),greater.begin(),greater.end());
        return result;

        
    }
};