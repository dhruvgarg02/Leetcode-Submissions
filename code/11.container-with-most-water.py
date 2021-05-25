class Solution:
    def maxArea(self, height: List[int]) -> int:
        max_water = 0
        n = len(height)
        print(n)
        width = n - 1
        i = 0
        j = n-1
        while(i < j):
            max_water = max(max_water, (j - i)*min(height[i], height[j]))
            if(height[i] <= height[j]):
                i = i + 1
            else:
                j = j - 1
        return max_water
        