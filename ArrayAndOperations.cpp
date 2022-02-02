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
        int n,k; cin>>n>>k; int a[n],sum=0;
        for(int i = 0; i<n; i++) cin>>a[i];
        sort(a,a+n); for(int i = n-1; i>=n-k; i--) {if(a[i-k]==a[i]) sum+=1;}
        for(int i = 0; i<n-2*k; i++) sum+=a[i];cout<<sum<<endl;
    }
    return 0;
}