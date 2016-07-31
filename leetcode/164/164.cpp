class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int size = nums.size();
        int a = 0x7fffffff,b = -0x7fffffff;
        if(size < 2)
            return 0;
        vector<int> bmax;
        vector<int> bmin;
        vector<int> h;
        for(int i = 0; i < size; i++)
        {
            bmax.push_back(-0x7fffffff);
            bmin.push_back(0x7fffffff);
            h.push_back(0);
        }
        for(int i = 0; i < size; i++)
        {
            a = min(a, nums[i]);
            b = max(b, nums[i]);
        }
        if(b-a == 0)
            return 0;
        int len = (b-a) / (size-1);
        if(len == 0)
            len = 1;
        for(int i = 0; i < size; i++)
        {
            int w = (nums[i]-a)/ len;
            bmax[w] = max(bmax[w], nums[i]);
            bmin[w] = min(bmin[w], nums[i]);
            h[w] = 1;
        }
        int m = -0x7fffffff;
        int ans = -0x7fffffff;
        for(int i = 0; i < size; i++)
        {
            //cout << m <<" "<<bmin[i]<<endl;
            if(m != -0x7fffffff && h[i])
                ans = max(ans, bmin[i] - m);
            m = max(m,bmax[i]);
        }
        return ans;
    }
};