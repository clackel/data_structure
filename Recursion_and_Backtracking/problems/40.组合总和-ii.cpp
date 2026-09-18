/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        backtrack(0, 0, target, res, path, candidates);
        return res;
    }

    void backtrack(int start_index,
                   int cur_sum,
                   int target,
                   vector<vector<int>> &res,
                   vector<int> &path,
                   vector<int> &candidates)
    {
        if (cur_sum == target)
        {
            res.push_back(path);
            return;
        }

        for (int i = start_index; i < candidates.size(); i++)
        {
            if (cur_sum + candidates[i] > target)
                break;
            if (i > start_index && candidates[i] == candidates[i - 1])
                continue;
            path.push_back(candidates[i]);
            backtrack(i + 1, cur_sum + candidates[i], target, res, path, candidates);
            path.pop_back();
        }
    }
};
// @lc code=end
