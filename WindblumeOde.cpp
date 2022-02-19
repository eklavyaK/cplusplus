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
        int n; cin>>n; int a[n], sum = 0; bool detect = true, c = true; int odd;
        for(int i = 0; i<n; i++) {cin>>a[i];sum+=a[i];}
        int k = sqrt(sum); for(int i = 2; i<=k; i++) if(sum%i==0) {detect = false; break;}
        if(detect){cout<<n-1<<endl;for(int i = 1; i<=n; i++) {if(c && a[i-1]%2)c=false; else cout<<i<<" ";}}
        else {cout<<n<<endl;for(int i = 1; i<=n; i++) cout<<i<<" ";}cout<<endl;
    }
    return 0;
}