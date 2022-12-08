// https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1/#
// https://www.youtube.com/watch?list=TLGGBVZP0QjfybUxNTA2MjAyMg&v=ju8vrEAsa3Q&feature=emb_imp_woyt


// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    private:
    long long m = 1000000007;
    long long mod_add(long long a, long long b) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
    long long mod_mul(long long a, long long b) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
    public:
    long long countWays(int n, int k){
        long long same_color = k*1;
        long long diff_color = k*(k-1);
        long long total = same_color+diff_color;
        if(1==n) return k;
        for(int i=3;i<=n;i++){
            same_color = mod_mul(diff_color,1);
            diff_color = mod_mul(total,(k-1));
            total = mod_add(same_color,diff_color);
        }
        return total;
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends