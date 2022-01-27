#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n,count=0;cin>>n;int a[n];
        for(int i = 0; i<n; i++) cin>>a[i];
        int in = n-1;
        while(in>0) {while(in-1>=0 && a[in-1]==a[n-1]) in--; if(in>0){in -=(n-in);count++;}}
        cout<<count<<endl;
    }
    return 0;
}