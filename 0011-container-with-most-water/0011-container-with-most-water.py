class Solution(object):
    def maxArea(self, height):
        res = 0
        l, r = 0, len(height) - 1

        while l < r:
            w = r - l
            h = min(height[l], height[r])
            res = max(res, w * h)

            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return res
        
        