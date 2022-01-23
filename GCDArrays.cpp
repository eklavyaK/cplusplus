#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        long long l,r,k; cin>>l>>r>>k;
        if((r-l)%2)
        {
            int p = (r-l+1)/2;
            if(p<=k) cout<<"YES"<<endl; else cout<<"NO"<<endl;
        }
        else
        {
            if(l%2==0 && (r-l)/2<=k) cout<<"YES"<<endl;
            else if(l%2==1 && ((r-l)/2+1)<=k) cout<<"YES"<<endl;
            else if(l!=1 && (r-l)==0)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}