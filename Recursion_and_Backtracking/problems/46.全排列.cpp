/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> used(nums.size(), false);

        backtrack(nums, path, res, used);
        return res;
    }

    void backtrack(vector<int> &nums,
                   vector<int> &path,
                   vector<vector<int>> &res,
                   vector<bool> used)
    {
        if (path.size() == nums.size())
        {
            res.push_back(path); // 保存当前排列的副本
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            // 当前路径中已经有这个数，就跳过
            if (used[i])
            {
                continue;
            }

            path.push_back(nums[i]); // 选择
            used[i] = true;
            backtrack(nums, path, res, used); // 递归
            path.pop_back();                  // 撤销选择
            used[i] = false;
        }
    }
};
// @lc code=end
