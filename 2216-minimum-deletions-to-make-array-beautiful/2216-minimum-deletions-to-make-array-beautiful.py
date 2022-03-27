class Solution:
    def minDeletion(self, nums: List[int]) -> int:
        j = 0
        i = 0
        delete = 0
        n = len(nums)
        while i < n:
            if (i+1 < n and nums[i] == nums[i+1] and j%2 == 0) :
                delete += 1;
            else:
                j += 1;
            i += 1
        if j%2 != 0:
            delete += 1
        return delete
            