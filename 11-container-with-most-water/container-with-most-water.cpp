class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int minHeight;
        int width;
        int area = 0,maxArea =0;

        int left = 0;
        int right = size-1;
        while(left<=right){
            minHeight = min(height[left],height[right]);
            width = (right-left);
            area  = width*minHeight;
            maxArea = maxArea > area ? maxArea : area;
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }

        }
        return maxArea;
        
    }
};