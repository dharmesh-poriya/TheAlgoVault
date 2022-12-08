// https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/partition-into-subsets-official/ojquestion
// https://www.youtube.com/watch?list=TLGGl6zY9PhewQkxNjA2MjAyMg&v=IiAsqfjhZnY&feature=emb_imp_woyt

#include <iostream> 
#include <vector>

using namespace std ;

int main() {
    int n ;
    cin>>n ;
    int k ;
    cin>>k;
    
    vector<vector<long long>> dp(k+1,vector<long long>(n+1));
    for(int i=0;i<=k;i++) dp[i][0] = 0;
    for(int j=0;j<=n;j++) dp[0][j] = 0;
    for(int j=1;j<=n;j++) dp[1][j] = 1;
    for(int i=2;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(j<i) dp[i][j] = 0;
            else if(j==i){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = dp[i][j-1]*i + dp[i-1][j-1];
            }
        }
    }
    cout<<dp[k][n];
    return 0;
}