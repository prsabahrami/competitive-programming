/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution {
public:

    int dp[30][30];

    bool isMatch(string s, string p) {
        if (s.empty() && p.empty()) return true;
        if (p.empty()) return false;
        if (s.empty()) {
            if (p.size() & 1) return false;
            for (int i = 1; i < p.size(); i += 2) {
                if (p[i] != '*') return false;
            }
            return true;
        }
        memset(dp, -1, sizeof dp);
        dp[0][0] = 1;
        for (int i = 0; i <= s.size(); i++) {
            for (int j = 1; j <= p.size(); j++) {
                if (dp[i][j] == -1) {
                    if (p[j - 1] == '*') {
                        if (dp[i][j - 2] == 1) dp[i][j] = 1;
                        else if (i > 0 && (p[j - 2] == '.' || p[j - 2] == s[i - 1]) && dp[i - 1][j] == 1) dp[i][j] = 1;
                        else dp[i][j] = 0;
                    } else {
                        if (i > 0 && (p[j - 1] == '.' || p[j - 1] == s[i - 1]) && dp[i - 1][j - 1] == 1) dp[i][j] = 1;
                        else dp[i][j] = 0;
                    }
                }
            }
        }
        return dp[s.size()][p.size()] == 1;
    }
};
// @lc code=end

