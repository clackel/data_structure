/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i])
            {
                swap(nums[nums[i] - 1], nums[i]);
            }
            else
            {
                i++;
            }
        }

        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] != j + 1)
                return j + 1;
        }

        return nums.size() + 1;
    }
};
// @lc code=end
