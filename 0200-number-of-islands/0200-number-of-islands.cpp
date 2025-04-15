class Solution {
public:
    void setVisit(vector<vector<char>>& grid, int rowCnt, int rowIdx,
                  int colCnt, int colIdx) {
        if (rowIdx >= 0 && colIdx >= 0 && rowIdx < rowCnt && colIdx < colCnt &&
            grid[rowIdx][colIdx] != '0') {
            grid[rowIdx][colIdx] = '0';
            setVisit(grid, rowCnt, rowIdx - 1, colCnt, colIdx);
            setVisit(grid, rowCnt, rowIdx + 1, colCnt, colIdx);
            setVisit(grid, rowCnt, rowIdx, colCnt, colIdx - 1);
            setVisit(grid, rowCnt, rowIdx, colCnt, colIdx + 1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;

        int rowCnt = grid.size();
        int colCnt = grid[0].size();

        for (int rowIdx = 0; rowIdx < rowCnt; rowIdx++) {
            for (int colIdx = 0; colIdx < colCnt; colIdx++) {
                if (grid[rowIdx][colIdx] != '0') {
                    setVisit(grid, rowCnt, rowIdx, colCnt, colIdx);
                    result++;
                }
            }
        }

        return result;
    }
};