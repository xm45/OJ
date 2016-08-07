class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l<r){
            int m = l + (r - l)/2;
            if(nums[m] == target)
                return m;
            if(nums[m] > target)
                r = m;
            else
                l = m + 1;
        }
        if(nums[r] < target)
            return r + 1;
        else
            return r;
    }
};