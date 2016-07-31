class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int size = nums.size();
        int ans = 0;
        int flag = 0;
        for(int i = 0; i < size-2; i++)
        {
            int req = find(nums,i+1,size-1,target-nums[i]);
            check(ans,req+nums[i],target,flag);
            if(ans == target && flag != 0)
                return ans;
        }
        return ans;
    }
    int find(vector<int>& nums, int lp, int rp, int target)
    {
        int ans = 0;
        int flag = 0;
        int l,r;
        l = lp;
        r = rp;
        //less
        while(l<r)
        {
            check(ans,nums[l]+nums[r],target,flag);
            if(ans == target && flag != 0)
                break;
            if(nums[l] + nums[r] > target)
                if(l == lp)
                    r--;
                else
                    l--;
            else
                if(l+1<r && nums[l+1]+nums[r] > target)
                {
                    check(ans,nums[l+1]+nums[r],target,flag);
                    r--;
                }
                else
                    l++;
        }
        return ans;
    }
    void check(int &ans,int sum,int target,int &flag)
    {
        if(flag == 0)
        {
            ans = sum;
            flag = 1;
            return;
        }
        if(abs(ans-target) > abs(sum-target))
            ans = sum;
    }
};