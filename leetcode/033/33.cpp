class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0,r = nums.size()-1;
        while(l<=r){
            int k = (l+r)/2;
            cout<<l<<' '<<r<<' '<<k<<endl;
            if(nums[k] == target)
                return k;
            else
                if(nums[l] <= nums[k]) {
                    if(nums[l] <= target && target < nums[k]) {
                        r = k - 1;
                    }
                    else {
                        l = k + 1;
                    }
                }
                else {
                    if(nums[k] < target && target <= nums[r]) {
                        l = k + 1;
                    }
                    else {
                        r = k - 1;
                    }
                }
        }
        return -1;
    }
};