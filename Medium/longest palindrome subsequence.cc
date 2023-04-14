class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<int> dp(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            vector<int> newdp(n, 0);
            newdp[i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    newdp[j] = 2 + dp[j-1];
                } else {
                    newdp[j] = max(dp[j], newdp[j-1]);
                }
            }
            dp = newdp;
        }
        return dp[n-1];
    }
};