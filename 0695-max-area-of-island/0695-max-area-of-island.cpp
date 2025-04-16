class Solution {
public:
    int checkNumOfIsland(vector<vector<int>>& grid, int rowCnt, int rowIdx,
                         int colCnt, int colIdx) {
        int result = 0;

        if (rowIdx >= 0 && colIdx >= 0 && rowIdx < rowCnt && colIdx < colCnt &&
            grid[rowIdx][colIdx] == 1) {
            grid[rowIdx][colIdx] = 0;
            result++;
            result +=
                checkNumOfIsland(grid, rowCnt, rowIdx + 1, colCnt, colIdx);
            result +=
                checkNumOfIsland(grid, rowCnt, rowIdx - 1, colCnt, colIdx);
            result +=
                checkNumOfIsland(grid, rowCnt, rowIdx, colCnt, colIdx - 1);
            result +=
                checkNumOfIsland(grid, rowCnt, rowIdx, colCnt, colIdx + 1);
        }

        return result;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;
        int rowCnt = grid.size();
        int colCnt = grid[0].size();

        for (int rowIdx = 0; rowIdx < rowCnt; rowIdx++) {
            for (int colIdx = 0; colIdx < colCnt; colIdx++) {
                if (grid[rowIdx][colIdx] == 1) {
                    result = max(result, checkNumOfIsland(grid, rowCnt, rowIdx,
                                                          colCnt, colIdx));
                }
            }
        }

        return result;
    }
};