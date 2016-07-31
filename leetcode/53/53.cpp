class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int sum2 = -0xfffffff;
        for(int i = 0; i < nums.size(); i++){
            sum = max(sum+nums[i],0);
            sum2 = max(sum2,nums[i]);
            if(sum!=0)
                sum2 = max(sum2,sum);
        }
        return sum2;
    }
};