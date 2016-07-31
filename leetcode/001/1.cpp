class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 1,j;
        int len = nums.size();
        map<int, int> m;
        for(j = 0; j < len; j++)
        {
            int l = target - nums[j];
            if((i= m.find(l)==m.end()?-1:m.find(l)->second) != -1)
                return vector<int>{i+1,j+1};
            m[nums[j]] = j;
        }
    }
};