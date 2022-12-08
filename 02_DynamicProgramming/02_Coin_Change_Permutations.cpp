#include <iostream>
#include <vector>
using namespace std;

int change(int amount, vector<int> &coins)
{
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int i = 0; i<amount+1; i++)
    {
        for (int j = 0; j < coins.size() && coins[j]<=i; j++)
        {
            dp[i] += dp[i - coins[i]];
        }
    }
    return dp[amount];
}

int main()
{
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < coins.size(); i++)
    {
        cin >> coins[i];
    }
    int amount;
    cin >> amount;
    cout<<change(amount, coins);
}