/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var nextPermutation = function(nums) {
    len = nums.length;
    for(i = len-1; i >= 1; i--)
    {
        if(nums[i] > nums[i-1])
        {
            for(j = len-1; j > i-1; j--)
            {
                if(nums[j] > nums[i-1])
                {
                    //console.log(nums[j],nums[i-1])
                    temp = nums[i-1];
                    nums[i-1] = nums[j];
                    nums[j] = temp;
                    p = nums.slice(i,len);
                    p.sort(function(a,b){return a-b;});
                    for(j = i; j < len; j++)
                        nums[j] = p[j-i];
                    return;
                }
            }
        }
    }
    nums.sort(function(a,b){return a-b;});
};