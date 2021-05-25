class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum = -99999999999
        max_till_now = 0
        for i in nums:
            max_till_now = max_till_now + i
            if max_till_now > max_sum:
                max_sum = max_till_now
            if max_till_now < 0:
                max_till_now = 0 
        return max_sum
            