class Solution {
private:
    TreeNode* generateTree(vector<int>& nums,int left,int right){
        if(right < left)return nullptr;
        int mid  = left + (right-left)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = generateTree(nums,left,mid-1);
        node->right= generateTree(nums,mid+1,right);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)return nullptr;
        return generateTree(nums,0,nums.size()-1);
        
    }
};