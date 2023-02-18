#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;


void code(){
    int n,q; cin>>n>>q;
    vector<array<int,3>> Q(q);
    vector<int> ans(n+1),mx(n+1,(1<<30)-1);
    bool done[n+1]{};
    for(int i=0;i<q;i++){
        int u,v;
        cin>>u>>v>>Q[i][2];
        Q[i][0] = min(u,v);
        Q[i][1] = max(u,v);
        mx[Q[i][0]]&=Q[i][2];
        mx[Q[i][1]]&=Q[i][2];
        done[u] = done[v] = 1;
    }
    sort(Q.begin(),Q.end());
    for(int i=0;i<q;i++){
        for(int j=0;j<30;j++){
            if(!((1<<j)&Q[i][2]))continue;
            if((!((1<<j)&mx[Q[i][1]]))&&(!((1<<j)&ans[Q[i][0]])))ans[Q[i][0]]+=(1<<j);
        }
    }
    for(int i=0;i<q;i++){
        for(int j=0;j<=30;j++){
            if(!((1<<j)&Q[i][2]))continue;
            if((ans[Q[i][1]]&(1<<j))||((ans[Q[i][0]]&(1<<j))))continue;
            else ans[Q[i][1]]+=(1<<j);
        }
    }
    for(int i=1;i<=n;i++){
        if(!done[i])cout<<0<<" ";
        else cout<<ans[i]<<" ";
    }
    cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}