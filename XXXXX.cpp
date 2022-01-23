#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n,x; cin>>n>>x;int a[n];int l = -1,r=-1;long long sum = 0l;
        for(int i = 0; i<n; i++) {cin>>a[i];sum+=a[i];}
        if(sum%x){cout<<n<<endl;continue;}
        for(int i = 0; i<n; i++) if(a[i]%x){l=i;break;}
        for(int i = n-1; i>=0; i--) if(a[i]%x){r=i;break;}
        if(l==-1 && r==-1)cout<<-1<<endl;else cout<<max(n-1-l,r)<<endl;
    }
    return 0;
}