#include <cstring>
class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board) {
        bool row_check[10][10], col_check[10][10], section_check[10][10];

        memset(row_check, 0, 100);
        memset(col_check, 0, 100);
        memset(section_check, 0, 100);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.')
                    continue;
                
                int num = c - '0';

                int section = i / 3 + (j / 3) * 3;

                if (row_check[i][num] || col_check[j][num] || section_check[section][num])
                    return false;
                
                row_check[i][num] = true;
                col_check[j][num] = true;
                section_check[section][num] = true;
            }
        }
        return true;
    }
};
