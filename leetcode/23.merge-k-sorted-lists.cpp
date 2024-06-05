/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int ptr[10010];

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        int ptr = 0;
        ListNode* ans = nullptr;
        ListNode* lst = nullptr;
        while (1) {
            int id = -1;
            for (int i = 0; i < k; i++) {
                if (lists[i] != nullptr && ((id == -1) || lists[i]->val < lists[id]->val)) id = i;
            }
            if (id == -1) return ans;
            if (ans == nullptr) { ans = lists[id]; lst = ans; }
            else { lst->next = lists[id]; lst = lst->next; }
            lists[id] = lists[id]->next;
        }
        return ans;
    }
};
// @lc code=end

