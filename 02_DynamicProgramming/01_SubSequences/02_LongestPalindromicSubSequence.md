# Longest Palindromic SubSequence
### [Problem Link](https://leetcode.com/problems/longest-palindromic-subsequence/)

## Approach (Iterative) : 
* it's the same as the Longest Common SubSequence problem, but we need to find the LCS of the string and it's reverse.

## Code : 
```cpp
// 
class Solution {
public:
    int longestPalindromeSubseq(string text1) {
        string text2 = text1;
        reverse(text2.begin(),text2.end());
        int t1 = text1.size();
        int t2 = text2.size();
        vector<vector<int>> dp(t1+1,vector<int>(t2+1,-1));
        for(int i=0;i<=t1;i++) dp[i][0] = 0;
        for(int j=0;j<=t2;j++) dp[0][j] = 0;
        for(int i=1;i<=t1;i++){
            for(int j=1;j<=t2;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[t1][t2];
    }
};
```

#### Time Complexity : O(N*N) // N is the length of the string
#### Space Complexity : O(N*N)

---
<!-- 
# Related Problems

<h3>
<details>
<summary>LeetCode</summary>

> ### 1. Problem: Name ( [Try It]() )

</details>
</h3>


<h3>
<details>
<summary>GFG</summary>

> ### 1. Name ( [Try It]() )

</details>
</h3> -->