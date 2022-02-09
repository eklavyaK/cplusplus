#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
using namespace std;
int mod = 1000000007;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n,k,count=0; cin>>n; int a[n+1],b[n+1], result = 1; bool track[n+1] = {false};
        for(int i = 1; i<=n; i++) {cin>>a[i];};for(int i = 1; i<=n; i++) {cin>>k;b[k]=i;}
        for(int i = 1; i<=n; i++) if(!track[i]){int temp = i;while(!track[temp]){track[temp]=true;temp = b[a[temp]];}count++;}
        while(count--) result=(result*2)%mod;cout<<result<<endl;
    }
    return 0;
}