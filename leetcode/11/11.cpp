class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int i = 0, j = len-1;
        int ans = 0;
        while(i < j)
        {
            int k = min(height[i],height[j]);
            ans = max(ans, k*(j-i));
            if(height[i] > height[j])
                j--;
            else
                i++;
        }
        return ans;
    }
};