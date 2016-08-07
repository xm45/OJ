import bisect
class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        l = bisect.bisect_left(nums, target)
        r = bisect.bisect_right(nums, target)
        if r != 0 and nums[r-1] == target:
            return [l,r-1]
        else:
            return [-1,-1]