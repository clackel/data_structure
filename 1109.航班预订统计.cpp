/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

// @lc code=start
class Solution
{
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        vector<int> diff(n + 1, 0);
        for (auto book : bookings)
        {
            int first = book[0];
            int last = book[1];
            int seats = book[2];

            diff[first - 1] += seats;
            diff[last] -= seats;
        }

        vector<int> ans(n, 0);
        ans[0] = diff[0];

        for (int i = 1; i < diff.size() - 1; i++)
        {
            ans[i] = ans[i - 1] + diff[i];
        }

        return ans;
    }
};
// @lc code=end
