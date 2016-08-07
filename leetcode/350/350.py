class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        map = {}
        for num in nums1:
            if num in map:
                map[num] += 1
            else:
                map[num] = 1
        ans = []
        for num in nums2:
            if num in map:
                if map[num] != 0:
                    map[num] -= 1
                    ans.append(num)
        return ans