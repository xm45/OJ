class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int size = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < size-3; i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target)
                break;
            if(nums[i] + nums[size-3]+nums[size-2]+nums[size-1] < target)
                continue;
            for(int j = i+1; j < size-2; j++)
            {
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;
                if(nums[i] + nums[j]+nums[j+1]+nums[j+2] > target)
                    break;
                if(nums[i] + nums[j] + nums[size-2]+nums[size-1] < target)
                    continue;
                //cout<<i<<" "<<j<<endl;
                int l = j+1, r = size-1;
                while(l<r)
                {
                    if(nums[i]+nums[j]+nums[l]+nums[r] == target)
                        ans.push_back(vector<int>{nums[i],nums[j],nums[l],nums[r]});
                    if(nums[i]+nums[j]+nums[l]+nums[r] <= target)
                        do
                        {
                            l++;
                        }while(l < r && nums[l] == nums[l-1]);
                    else
                        do
                        {
                            r--;
                        }while(l < r && nums[r] == nums[r+1]);
                }
            }
        }
        return ans;
    }
};