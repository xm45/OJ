class Solution {
public:
    int lowbit(int x) {
        return x&(-x);
    }
    void add(vector<int> &bit, int n, int maxV, int val) {
        while(n <= maxV) {
            bit[n] += val;
            //cout<<n<<' '<<lowbit(n)<<endl;
            n += lowbit(n);
        }
    }
    int get(vector<int> &bit, int n) {
        int ret = 0;
        while(n) {
            ret += bit[n];
            //cout<<n<<' '<<lowbit(n)<<endl;
            n -= lowbit(n);
        }
        return ret;
    }
    vector<int> countSmaller(vector<int>& nums) {
        int maxV = INT_MIN,minV = INT_MAX;
        int len = nums.size();
        for(int i = 0; i < len; i ++) {
            maxV = max(maxV, nums[i]);
            minV = min(minV, nums[i]);
        }
        maxV -= minV-1;
        for(int i = 0; i < len; i ++) {
            nums[i] -= minV-1;
        }
        vector<int> bit(maxV+1, 0);
        for(int i = 0; i < len; i ++) {
            add(bit, nums[i], maxV, 1);
        }
        vector<int> ans;
        for(int i = 0; i < len; i ++) {
            ans.push_back(get(bit, nums[i]-1));
            add(bit, nums[i], maxV, -1);
        }
        return ans;
    }
};