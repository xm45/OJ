class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int l1 = nums1.size(),l2 = nums2.size();
        vector<int> index(l1,0);
        int now = 0;
        int num = 0;
        vector<pair<int, int>> ans;
        while(k--) {
            int ret = INT_MAX, m = -1;
            for(int i = 0; i < l1; i ++) {
                if(index[i]< l2) {
                    if(m == -1 || nums1[i] + nums2[index[i]]< ret){
                        ret = nums1[i] + nums2[index[i]];
                        m = i;
                    }
                }
            }
            if(m >= 0) {
                ans.push_back(make_pair(nums1[m],nums2[index[m]]));
                index[m] ++;
            }
        }
        return ans;
    }
};