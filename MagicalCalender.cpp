#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        long long n,k; cin>>n>>k; 
        if(k<n) cout<<(k*(k+1)/2)<<endl;
        else cout<<(n*(n-1)/2+1)<<endl;
    }
    return 0;
}