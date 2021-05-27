class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        r = {}
        for i in range(len(nums)):
            if(target - nums[i]) in r:
                return [r[target - nums[i]],i]
            else:
                r[nums[i]]=i
