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
        int n,l,r,k; cin>>n>>l>>r>>k; int a[n],count=0,sum=0;
        for(int i = 0; i<n; i++) cin>>a[i]; sort(a,a+n);
        int i = lower_bound(a,a+n,l)-a,j=upper_bound(a,a+n,r)-a;
        while(i<j && (sum+=a[i++])<=k) count++;cout<<count<<endl; 
    }
    return 0;
}