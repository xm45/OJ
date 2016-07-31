class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < size-2; i++)
        {
            while(i>0 && i < size-2 && nums[i] == nums[i-1])
                i++;
            //cout<<i<<endl;
            vector<vector<int>> ret = find(nums, i+1, size-1, -nums[i]);
            int rsize = ret.size();
            for(int j = 0; j < rsize; j++)
                ans.push_back(vector<int>{nums[i],ret[j][0],ret[j][1]});
                //add(ans,vector<int>{ret[j][0],ret[j][1],nums[i]});
        }
        return ans;
    }
    vector<vector<int>> find(vector<int>& nums, int lp,int rp, int req)
    {
        int l = lp, r = rp;
        vector<vector<int>> ans;
        while(l < r)
        {
            if(nums[l] + nums[r] == req)
            {
                ans.push_back(vector<int>{nums[l],nums[r]});
                //add(ans,vector<int>{nums[l],nums[r]});
                //cout<<nums[l]<<" "<<nums[r]<<endl;
            }
            if(nums[l] + nums[r] <= req)
                do {l++;}while(nums[l] == nums[l-1] && l < r);
            else
                do {r--;}while(nums[r] == nums[r+1] && l < r);
        }
        return ans;
    }
    void add(vector<vector<int>>& ans, vector<int>& ins)
    {
        if(ans.size() == 0)
        {
            ans.push_back(ins);
            return;
        }
        vector<vector<int>>::iterator last = ans.end()-1;
        int size = ins.size();
        for(int i = 0; i < size; i++)
            if((*last)[i] != ins[i])
            {
                ans.push_back(ins);
                return;
            }
    }
};