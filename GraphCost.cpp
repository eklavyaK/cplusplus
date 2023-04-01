#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

int f[1000005];

void code(){
    int n,m; cin>>n>>m;
    for(int i=n/2+1;i<=n;i++)f[i] = 0;
    for(int i=n/2;i>=2;i--){
        int c = 0, k = n/i;
        for(int j=2;j*i<=n;j++)c+=f[j*i];
        f[i] = k*(k-1)/2-c;
    }
    int ans = 0;
    for(int i=n/2;i>=2;i--){
        int c = min(f[i],m)/(i-1);
        m-=c*(i-1), ans+=c*i;
    }
    if(!m)cout<<ans<<endl;
    else cout<<-1<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}