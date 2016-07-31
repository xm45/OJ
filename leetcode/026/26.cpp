class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int count = 0;
        int last = -0x7fffffff;
        for(int i = 0; i < size; i++)
        {
            if(nums[i] != last)
            {
                nums[count++] = nums[i];
                last = nums[i];
            }
        }
        return count;
    }
};