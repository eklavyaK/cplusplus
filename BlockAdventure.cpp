#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n,m,k,detect = 0; cin>>n>>m>>k; long long sum = 0l; int a[n];
        for(int i = 0; i<n; i++) cin>>a[i]; sum = sum +m;
        for(int i = 0; i<n-1; i++) 
        {
            if(a[i+1]<=k) {sum+=a[i];continue;}
            sum = sum+a[i]-(a[i+1]-k);
            if(sum<0) {detect = 1; break;}
        }
        if(detect) cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
    return 0;
}