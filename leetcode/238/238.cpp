class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> output(len,1);
        int ret = 1;
        for(int i = 0; i < len; i ++){
            output[i] *= ret;
            ret *= nums[i];
        }
        ret = 1;
        for(int i = len-1; i >= 0; i --){
            output[i] *= ret;
            ret *= nums[i];
        }
        return output;
    }
};