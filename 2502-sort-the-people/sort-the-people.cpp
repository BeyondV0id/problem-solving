class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> heightPairs;
        for(int i=0;i<heights.size();i++){
            heightPairs.push_back({heights[i],names[i]});
        }
        sort(heightPairs.rbegin(),heightPairs.rend());
        vector<string>sortedNames;
        for(int i=0;i<heights.size();i++){
            sortedNames.push_back(heightPairs[i].second);
        }
        return sortedNames;

        
    }
};