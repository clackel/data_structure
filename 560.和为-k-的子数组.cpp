/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        vector<int> preSum(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            preSum[i + 1] = preSum[i] + nums[i];
        }

        int res = 0;
        unordered_map<int, int> hashtable;
        for (int item : preSum)
        {
            int other = item - k;
            if (hashtable.count(other))
                res += hashtable[other];

            hashtable[item]++;
        }

        return res;
    }
};
// @lc code=end
