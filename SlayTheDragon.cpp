#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n,m; cin>>n; long long a[n],res, sum = 0l;
    for(int i = 0; i<n; i++) {cin>>a[i];sum+=a[i];}
    cin>>m;sort(a,a+n);while(m--) 
    { 
        long long x,y;cin>>x>>y; res = upper_bound(a,a+n,x)-a;
        if(x+y==sum) {res==n? cout<<x-a[res-1]<<endl:res!=0?cout<<min(x-a[res-1],a[res]-x)<<endl:cout<<a[res]-x<<endl;}
        else if(x+y>sum) x<a[0]? cout<<(y-sum+a[0])<<endl:cout<<max((long long)0,y-sum+a[res-1])+x-a[res-1]<<endl;
        else
        {
            if(a[n-1]<=x)cout<<x-a[n-1]<<endl;
            else x<a[0]?cout<<max((long long)0,y-sum+a[0])<<endl:cout<<min(max((long long)0,y-sum+a[res]),x-a[res-1])<<endl;
        }
    }
    return 0;
}