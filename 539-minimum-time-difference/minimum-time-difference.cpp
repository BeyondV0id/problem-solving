class Solution {
private:
    int convert(string time){

        int split = time.find(':');

        string h = time.substr(0,split);
        string m = time.substr(split+1);


        int hours = stoi(h);
        int mins = stoi(m);

        return hours*60 + mins;
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>mins;

        for(auto &time : timePoints){
            mins.push_back(convert(time));
        }
        sort(mins.begin(),mins.end());
        
        int mini = INT_MAX;

        int n = mins.size();

        for(int i = 1; i < n; i++){
            mini = min(mini, mins[i]-mins[i-1]);
        }

        mini = min(mini, mins[0] - mins[n-1] + 24*60);

        return mini;
        
    }
};