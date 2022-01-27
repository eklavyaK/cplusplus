#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n,k; cin>>n>>k;
        if(k==n-1) 
        {if(k==3)cout<<-1<<endl;
        else{cout<<k-1<<" "<<k<<endl;cout<<1<<" "<<k-2<<endl;cout<<0<<" "<<2<<endl;for(int i = 3; i<n/2; i++)cout<<i<<" "<<n-1-i<<endl;}}
        else
        {
            cout<<k<<" "<<n-1<<endl;
            if(k!=0) cout<<0<<" "<<n-1-k<<endl;
            for(int i = 1; i<n/2; i++) if(i!=k && i!=n-1-k)cout<<i<<" "<<n-1-i<<endl;
        }
    }
    return 0;
}