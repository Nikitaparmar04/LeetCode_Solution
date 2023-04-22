class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<int> dp(n);
        for (int i = n - 2; i >= 0; i--) {
            int prev = 0;
            for (int j = i + 1; j < n; j++) {
                int temp = dp[j];
                if (s[i] == s[j]) {
                    dp[j] = prev;
                } else {
                    dp[j] = min(dp[j], dp[j-1]) + 1;
                }
                prev = temp;
            }
        }
        return dp[n-1];
    }
};