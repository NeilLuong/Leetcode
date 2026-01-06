class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (auto& row : board) {
            std::unordered_set<char> seen{}; 
            for (auto ch : row) {
                if (!seen.insert(ch).second && ch != '.') {
                    return false;
                }
            }
        }

        for (int i = 0; i < board.size(); i++) {
            std::unordered_set<char> seen{};
            for (int j = 0; j < board.size(); j++) {
                if (!seen.insert(board[j][i]).second && board[j][i] != '.') {
                    return false;
                }
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int x1 = 3 * i;
                int y1 = 3 * j;
                int x2 = 3 * i + 2;
                int y2 = 3 * j + 2;
                std::unordered_set<char> seen{};
                for (int m = x1; m < x2 + 1; m++) {
                    for (int n = y1; n < y2 + 1; n++) {
                        if (!seen.insert(board[m][n]).second && board[m][n] != '.') {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};