#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n; cin>>n; int a[2][n],sum1[n],sum2[n],result = INT_MAX; cin>>sum1[0];
        for(int i = 1; i<n; i++) {cin>>a[0][i];sum1[i]=sum1[i-1]+a[0][i];} a[0][0] = sum1[0];
        cin>>sum2[0];a[1][0] = sum2[0];for(int i = 1; i<n; i++) {cin>>a[1][i];sum2[i]=sum2[i-1]+a[1][i];}
        for(int i = 0; i<n; i++) if(max(sum1[n-1]-sum1[i],sum2[i]-a[1][i])<result) result = max(sum1[n-1]-sum1[i],sum2[i]-a[1][i]);
        cout<<result<<endl;
    }
    return 0;
}