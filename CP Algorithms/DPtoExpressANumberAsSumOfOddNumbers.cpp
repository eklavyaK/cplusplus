#include<bits/stdc++.h>
#define mod1 1000000007ll
typedef long long ll;
using namespace std;
ll dp[200001];     
int main(){
    int n; cin>>n;         //the number to be represented as the sum of the odd numbers

    //the order of the odd numbers is important

    dp[1]=1;dp[2]=1;
    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])%mod1;
    }
    cout<<dp[n]<<endl;
}