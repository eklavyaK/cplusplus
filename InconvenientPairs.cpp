#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

void code(){
    int n,m,k; cin>>n>>m>>k;
    int curr = -2, l = 1;
    map<int,int> uu, vv;
    for(int i=0;i<n;i++){
        int r; cin>>r;
        uu[r]=l++;
        curr = r;
    }
    uu[1e6+1] = -1;
    l = 1, curr = -2;
    for(int i=0;i<m;i++){
        int r; cin>>r;
        vv[r] = l++;
        curr = r;
    }
    vv[1e6+1] = -1;
    map<int,pair<map<int,int>,int>> uuuu,vvvv;
    for(int i=0;i<k;i++){
        int u,v; cin>>u>>v;
        if(!uu.count(u)){
            int s = uu.lower_bound(u)->F;
            uuuu[s].F[vv[v]]++; uuuu[s].S++;
        }
        else if(!vv.count(v)){
            int s = vv.lower_bound(v)->F;
            vvvv[s].F[uu[u]]++; vvvv[s].S++;
        }
    }
    int ans = 0;
    for(auto i : uuuu){
        for(auto j : i.S.F) ans += (i.S.S-j.S)*j.S;
    }
    for(auto i : vvvv){
        for(auto j : i.S.F) ans += (i.S.S-j.S)*j.S;
    }
    cout<<(ans>>1)<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}