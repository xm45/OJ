class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1)
            return 0;
        int touch = 0, in = 0;
        int len = nums.size();
        int count = 0;
        while(touch < len-1) {
            int now = touch;
            for(;in <= now; in ++) {
                touch = max(touch, in + nums[in]);
            }
            count ++;
            
        }
        return count;
    }
};