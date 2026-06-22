class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0,right = height.size() - 1,maxi = 0;
        while(left<right){
            int h = min(height[left],height[right]),width = right-left;
            maxi = max(maxi,h*width);
            if(height[left]<height[right])
                left++;
            else
                right--;
        }
        return maxi;
    }
};

// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int maxi = INT_MIN;
//         for(int i=0;i<height.size()-1;i++){
//             for(int j=i+1;j<height.size();j++){
//                 maxi = max(maxi,(min(height[i],height[j])*(j-i)));
//             }
//         }
//         return maxi;
//     }
// };



