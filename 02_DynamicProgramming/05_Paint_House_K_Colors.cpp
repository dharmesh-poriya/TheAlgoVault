// https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/paint-house-many-colors-official/ojquestion

#include <iostream>
#include <bits/stdc++.h>
using namespace std ;

int main()
{
    int n ;
    cin >> n ;
    int k ;
    cin >> k ;
    vector<vector<int>> a(n,vector<int>(k));
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin>>a[i][j];
        }
    }
    vector<vector<int>> dp(n,vector<int>(k));
    int least = INT_MAX;
    int second_least = INT_MAX;
    
    for(int j=0;j<k;j++){
        dp[0][j] = a[0][j];
        if(dp[0][j]<=least){
            second_least = least;
            least = dp[0][j];
        }else if(dp[0][j]<second_least){
            second_least = dp[0][j];
        }
    }
    
    for(int i=1;i<n;i++){
        int new_least = INT_MAX;
        int new_second_least = INT_MAX;
        for(int j=0;j<k;j++){
            if(dp[i][j]==least){
                dp[i][j] = a[i][j]+second_least;
            }else{
                dp[i][j] = a[i][j]+least;
            }
            if(dp[i][j]<=new_least){
                new_second_least = new_least;
                new_least = dp[i][j];
            }else if(dp[i][j]<new_second_least){
                new_second_least = dp[i][j];
            }
        }
        least = new_least;
        second_least = new_second_least;
    }
    
    cout<<least;
    return 0;
}