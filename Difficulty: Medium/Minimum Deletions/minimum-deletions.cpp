class Solution {
public:
    int lcs(string &s1, string &s2) {
        int n = s1.length();
        // DP table where dp[i][j] = LCS of s1[0..i-1] and s2[0..j-1]
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(s1[i-1] == s2[j-1]) {
                    // If characters match, take diagonal value + 1
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    // Else, take the max of left or top cell
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][n]; // LCS length
    }
    
    int minDeletions(string s) {
        int n = s.length();
        string reversed_s = s; 
        reverse(reversed_s.begin(), reversed_s.end()); // Reverse the string
        
        int lps_length = lcs(s, reversed_s); // Find LCS between s and its reverse (which is LPS)
        
        // Minimum deletions = Total length - LPS length
        return n - lps_length;
    }
};