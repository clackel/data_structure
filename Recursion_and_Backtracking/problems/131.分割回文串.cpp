/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> path;

        dfs(0, res, path, s);
        return res;
    }

    void dfs(int start_index, vector<vector<string>> &res, vector<string> &path, string s)
    {
        if (start_index >= s.size())
        {
            res.push_back(path);
            return;
        }

        for (int i = start_index; i < s.size(); i++)
        {
            if (is_palindrome(start_index, i, s))
            {
                path.push_back(s.substr(start_index, i - start_index + 1));
                dfs(i + 1, res, path, s);
                path.pop_back();
            }
        }
    }

    bool is_palindrome(int left, int right, string s)
    {
        while (left < right)
        {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};
// @lc code=end
