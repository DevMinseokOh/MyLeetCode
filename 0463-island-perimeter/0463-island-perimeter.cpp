class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int result = 0;
        int rowCnt = grid.size();
        int colCnt = grid[0].size();

        for (int rowIdx = 0; rowIdx < rowCnt; rowIdx++) {
            for (int colIdx = 0; colIdx < colCnt; colIdx++) {
                if (grid[rowIdx][colIdx] == 1) {
                    int check = 4;

                    // 위
                    if (rowIdx - 1 >= 0 && grid[rowIdx - 1][colIdx] == 1)
                        check--;
                    // 아래
                    if (rowIdx + 1 < rowCnt && grid[rowIdx + 1][colIdx] == 1)
                        check--;
                    // 왼쪽
                    if (colIdx - 1 >= 0 && grid[rowIdx][colIdx - 1] == 1)
                        check--;
                    // 오른쪽
                    if (colIdx + 1 < colCnt && grid[rowIdx][colIdx + 1] == 1)
                        check--;

                    result += check;
                }
            }
        }

        return result;
    }
};
