class Solution {
    vector<pair<int, int>> idxs;

public:
    bool checkSurrounded(vector<vector<char>>& board, int rowCnt, int rowIdx,
                         int colCnt, int colIdx) {
        bool result = true;

        if (rowIdx <= 0 || rowIdx >= rowCnt - 1 || colIdx <= 0 ||
            colIdx >= colCnt - 1) {
            result = false;
        } else {
            const vector<pair<int, int>> directions = {
                {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

            for (const auto& [dr, dc] : directions) {
                char cell = board[rowIdx + dr][colIdx + dc];
                if (cell != 'O' && cell != 'P' && cell != 'X') {
                    result = false;
                }
            }
        }
        return result;
    }
    void changePass(vector<vector<char>>& board, int rowCnt, int rowIdx,
                    int colCnt, int colIdx) {
        if (rowIdx >= 0 && colIdx >= 0 && rowIdx < rowCnt && colIdx < colCnt &&
            board[rowIdx][colIdx] == 'O') {
            board[rowIdx][colIdx] = 'P';
            idxs.push_back(make_pair(rowIdx, colIdx));

            changePass(board, rowCnt, rowIdx + 1, colCnt, colIdx);
            changePass(board, rowCnt, rowIdx - 1, colCnt, colIdx);
            changePass(board, rowCnt, rowIdx, colCnt, colIdx - 1);
            changePass(board, rowCnt, rowIdx, colCnt, colIdx + 1);
        }
    }
    void solve(vector<vector<char>>& board) {
        int rowCnt = board.size();
        int colCnt = board[0].size();

        for (int rowIdx = 0; rowIdx < rowCnt; rowIdx++) {
            for (int colIdx = 0; colIdx < colCnt; colIdx++) {

                if (board[rowIdx][colIdx] == 'O') {
                    changePass(board, rowCnt, rowIdx, colCnt, colIdx);
                    bool isSurrounded = true;
                    for (const auto& pairValue : idxs) {
                        if (checkSurrounded(board, rowCnt, pairValue.first,
                                            colCnt, pairValue.second)) {
                            continue;
                        } else {
                            isSurrounded = false;
                            break;
                        }
                    }

                    for (const auto& pairValue : idxs) {
                        board[pairValue.first][pairValue.second] =
                            (isSurrounded) ? 'X' : 'O';
                    }
                    idxs.clear();
                }
            }
        }
    }
};

/* class Solution {
    vector<pair<int, int>> idxs;

public:
    bool checkSubSurrounded(vector<vector<char>>& board, int rowCnt, int rowIdx,
                            int colCnt, int colIdx) {
        bool result = true;

        if (rowIdx <= 0 || rowIdx >= rowCnt - 1 || colIdx <= 0 ||
            colIdx >= colCnt - 1) {
            result = false;
        } else {
            const vector<pair<int, int>> directions = {
                {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

            for (const auto& [dr, dc] : directions) {
                char cell = board[rowIdx + dr][colIdx + dc];
                if (cell != 'O' && cell != 'P' && cell != 'X') {
                    result = false;
                }
            }
        }
        if (result)
            printf("T %d %d : %c\n", rowIdx, colIdx, board[rowIdx][colIdx]);
        else
            printf("F %d %d : %c\n", rowIdx, colIdx, board[rowIdx][colIdx]);
        return result;
    }

    bool checkSurrounded(vector<vector<char>>& board, int rowCnt, int rowIdx,
                         int colCnt, int colIdx) {
        bool result = false;
        if (rowIdx >= 0 && colIdx >= 0 && rowIdx < rowCnt - 1 &&
            colIdx < colCnt - 1 &&
            checkSubSurrounded(board, rowCnt, rowIdx, colCnt, colIdx)) {
            board[rowIdx][colIdx] = 'P';
            idxs.push_back(make_pair(rowIdx, colIdx));
            result =
                (checkSurrounded(board, rowCnt, rowIdx + 1, colCnt, colIdx) &&
                 checkSurrounded(board, rowCnt, rowIdx - 1, colCnt, colIdx) &&
                 checkSurrounded(board, rowCnt, rowIdx, colCnt, colIdx - 1) &&
                 checkSurrounded(board, rowCnt, rowIdx, colCnt, colIdx + 1));
        }

        return result;
    }
    void solve(vector<vector<char>>& board) {
        int rowCnt = board.size();
        int colCnt = board[0].size();

        for (int rowIdx = 0; rowIdx < rowCnt; rowIdx++) {
            for (int colIdx = 0; colIdx < colCnt; colIdx++) {
                if (board[rowIdx][colIdx] == 'O') {
                    if (checkSurrounded(board, rowCnt, rowIdx, colCnt,
                                        colIdx)) {
                        for (pair<int, int> idx : idxs) {
                            board[idx.first][idx.second] = 'X';
                            // printf("%d %d set X\n", idx.first, idx.second);
                        }
                        idxs.clear();
                    } else {
                        for (pair<int, int> idx : idxs) {
                            board[idx.first][idx.second] = 'O';
                            // printf("%d %d set O\n", idx.first, idx.second);
                        }
                        idxs.clear();
                    }
                }
            }
        }
    }
};*/