/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> vec;
        for (ListNode* th = head; th; th = th->next) vec.push_back(th);
        int n = vec.size();
        vec.push_back(nullptr);
        for (int i = 0; i < n; i += k) {
            int nxt = i + k;
            if (i + k > n) break;
            for (int j = nxt - 1; j > i; j--) vec[j]->next = vec[j - 1];
            vec[i]->next = vec[nxt];
            if (i) vec[i - 1]->next = vec[i + k - 1];
            for (int j = i; j < i + (k / 2); j++) {
                swap(vec[j], vec[i + i + k - j - 1]);
            }
        }
        return vec[0];
    }
};
// @lc code=end

