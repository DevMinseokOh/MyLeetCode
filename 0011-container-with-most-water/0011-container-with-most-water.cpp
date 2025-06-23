class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, w = 0, h = 0;
        int l = 0;
        int r = height.size() - 1;
        while (l < r) {
            w = r - l;
            h = min(height[l], height[r]);
            res = max(res, w * h);

            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return res;
    }
};