#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n,count=0; cin>>n; int a[n+1];
        for(int i = 1; i<=n; i++) cin>>a[i];
        for(int i = 1; i<=n-1; i++)
        {int j = i+a[i]-(2*i)%a[i];
        for(;j<=n;j+=a[i]) if((long long int)a[i]*a[j]==i+j) count++;} 
        cout<<count<<endl;
    }
    return 0;
}