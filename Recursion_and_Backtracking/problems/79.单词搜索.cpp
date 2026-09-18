/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int rows = board.size();
        int columns = board[0].size();

        for (int row = 0; row < rows; row++)
        {
            for (int column = 0; column < columns; column++)
            {
                if (board[row][column] == word[0] &&
                    dfs(row, column, 0, board, word, rows, columns))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(int row, int column, int index,
             vector<vector<char>> &board,
             string word,
             int rows, int columns)
    {
        if (index == word.size())
            return true;

        if (row < 0 || row >= rows || column < 0 || column >= columns)
            return false;

        if (board[row][column] == '#')
            return false;

        if (board[row][column] != word[index])
            return false;

        char temp = board[row][column];
        board[row][column] = '#';

        bool found =
            dfs(row - 1, column, index + 1, board, word, rows, columns) ||
            dfs(row + 1, column, index + 1, board, word, rows, columns) ||
            dfs(row, column - 1, index + 1, board, word, rows, columns) ||
            dfs(row, column + 1, index + 1, board, word, rows, columns);

        board[row][column] = temp;

        return found;
    }
};
// @lc code=end
