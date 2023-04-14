# Longest Common SubSequence
### [Problem Link](https://leetcode.com/problems/longest-common-subsequence/)

## Approach-01 (Top Down - Iterative) : 
* create a 2D array (dp) to store the length of the longest common subsequence upto that point.
* We will iterate over the 2 strings and if the characters are same, we will add 1 to the length of the LCS upto the previous character.
* If the characters are not same, we will take the maximum of the LCS upto the previous character of the first string and the LCS upto the previous character of the second string.
* We will return the last element of the 2D array.

## Code : 
```cpp
// 
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
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

#### Time Complexity : O(N*M) // N and M are the lengths of the 2 strings
#### Space Complexity : O(N*M)

---

## Approach-02 (Bottom Up - Recursive) : 
* create a 2D array (dp) to store the length of the longest common subsequence upto that point.
* recursively call the function with the 2 strings and the lengths of the 2 strings.
* if the lengths of the 2 strings are 0, return 0.
* if the length of the 2 strings are not 0, check if the characters at the end of the 2 strings are same.
* if they are same, add 1 to the length of the LCS upto the previous character.
* if they are not same, take the maximum of the LCS upto the previous character of the first string and the LCS upto the previous character of the second string.
* return the last element of the 2D array.

## Code : 
```cpp
// 
class Solution {
public:
    int lcs(string s1, string s2,int n1,int n2,vector<vector<int>> &dp){
        if(0==n1 || 0==n2) return 0;
        if(-1 != dp[n1][n2]) return dp[n1][n2];
        if(s1[n1-1]==s2[n2-1]) dp[n1][n2] = 1+lcs(s1,s2,n1-1,n2-1,dp);
        else
            dp[n1][n2] = max(lcs(s1,s2,n1-1,n2,dp),lcs(s1,s2,n1,n2-1,dp));
        return dp[n1][n2];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int t1 = text1.size();
        int t2 = text2.size();
        
        int ans = lcs(text1,text2,t1,t2,dp);
        return ans;
    }
};
```

#### Time Complexity : O(N*M) // N and M are the lengths of the 2 strings
#### Space Complexity : O(N*M)

---


# Related Problems

<h3>
<details>
<summary>LeetCode</summary>

> ### 1. Problem: 516. Longest Palindromic Subsequence ( [Try It](https://leetcode.com/problems/longest-palindromic-subsequence/) )

</details>
</h3>


<h3>
<details>
<summary>GFG</summary>

> ### 1. Longest Palindromic Subsequence ( [Try It](https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1) )

</details>
</h3>