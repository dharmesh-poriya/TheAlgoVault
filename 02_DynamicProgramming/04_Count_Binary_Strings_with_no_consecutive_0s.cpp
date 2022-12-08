// https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/count-binary-strings-official/ojquestion

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
        if(2>n) return n+n;
	    vector<vector<ll>> dp(2,vector<ll>(n+1,0));
        dp[0][1]=1;
        dp[1][1]=1;
        for(int i=2;i<=n;i+=1){
            dp[0][i] = dp[1][i-1];
            dp[1][i] = dp[0][i-1]+dp[1][i-1];
        }
        return dp[0][n]+dp[1][n];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends