/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        return dfs(root, -(1LL << 31) - 1, (1LL << 31));
    }

    bool dfs(TreeNode *root, long long min_limit, long long max_limit)
    {
        if (root == nullptr)
            return true;

        bool left = dfs(root->left, min_limit, root->val);
        bool right = dfs(root->right, root->val, max_limit);

        if (left && right && root->val > min_limit && root->val < max_limit)
            return true;

        return false;
    }
};
// @lc code=end
