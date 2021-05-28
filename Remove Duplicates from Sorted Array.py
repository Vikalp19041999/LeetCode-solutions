class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0 or n == 1:
            return n
        
        j = 0
        for i in range (0, n-1):
            if(nums[i] != nums[i+1]):
                nums[j] = nums[i]
                j+=1
        nums[j] = nums[n-1]
        j+=1
        return j
        