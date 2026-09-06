/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {

        unordered_set<ListNode *> hs;
        ListNode *curr = head;

        while (curr != nullptr)
        {
            if (hs.count(curr))
                return curr;

            hs.insert(curr);
            curr = curr->next;
        }
        return nullptr;
    }
};
// @lc code=end
