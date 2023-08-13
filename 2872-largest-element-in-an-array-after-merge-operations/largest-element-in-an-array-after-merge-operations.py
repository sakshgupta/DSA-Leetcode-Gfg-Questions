class Solution:
    def maxArrayValue(self, nums: List[int]) -> int:
        while True:
            found = False
            i = len(nums)-1
            while i>0:
                if nums[i]>=nums[i-1]:
                    found = True
                    nums[i-1] += nums[i]
                    nums.pop(i)
                    break
                i-=1
            if not found:
                break
        return max(nums)