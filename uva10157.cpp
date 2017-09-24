dp[m][d] =
{ 1, if m = 0 & d >= 0
{ 0, if m > 0 & d = 0
{ sum( dp[k][d-1]*dp[m-k-1][d], 0 <= k < m ), if m > 0 & d > 0
