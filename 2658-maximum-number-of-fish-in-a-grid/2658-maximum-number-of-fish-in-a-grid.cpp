class Solution {
public:
    int dfs(vector<vector<int>>& grid, int rowCnt, int rowIdx, int colCnt,
            int colIdx) {
        int result = 0;

        if (rowIdx >= 0 && rowIdx < rowCnt && colIdx >= 0 && colIdx < colCnt &&
            grid[rowIdx][colIdx] != 0) {

            result += grid[rowIdx][colIdx];
            grid[rowIdx][colIdx] = 0;

            result += dfs(grid, rowCnt, rowIdx - 1, colCnt, colIdx);
            result += dfs(grid, rowCnt, rowIdx + 1, colCnt, colIdx);
            result += dfs(grid, rowCnt, rowIdx, colCnt, colIdx - 1);
            result += dfs(grid, rowCnt, rowIdx, colCnt, colIdx + 1);
        }

        return result;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int maxVal = 0;
        int rowCnt = grid.size();
        int colCnt = grid[0].size();

        for (int rowIdx = 0; rowIdx < rowCnt; rowIdx++) {
            for (int colIdx = 0; colIdx < colCnt; colIdx++) {
                int checkVal = grid[rowIdx][colIdx];
                if (checkVal > 0) {
                    maxVal =
                        max(maxVal, dfs(grid, rowCnt, rowIdx, colCnt, colIdx));
                }
            }
        }

        return maxVal;
    }
};