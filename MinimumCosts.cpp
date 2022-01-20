#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n, u, v; cin>>n>>u>>v; int a[n];
        for(int i = 0; i<n; i++) cin>>a[i];int count = INT_MAX;
        for(int i = 0; i<n-1; i++) 
            if(abs(a[i] - a[i+1])>1) {count = 0; break;}
        if(count == 0) {cout<<0<<endl; continue;}
        for(int i = 0; i<n-1; i++) if(a[i]!=a[i+1]){count = min(u,v);break;}
        if(count==INT_MAX)
        {
            count = min(u+v,2*v);
            cout<<count<<endl;
        }
        else cout<<count<<endl;
    }
    return 0;
}