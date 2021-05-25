class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        res = []
        intervals.append(newInterval)
        intervals.sort()
        check = intervals[0]
        for item in intervals[1:]:
            if check[1] >= item[0]:
                check[1] = max(check[1], item[1])
            else:
                res.append(check)
                check = item
        res.append(check)
        return res
        