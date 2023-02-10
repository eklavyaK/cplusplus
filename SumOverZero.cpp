#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n; cin>>n;
    vector<int> arr(n+1), tree(4*n+5,-1e15), f(n+1);
    vector<pair<int,int>> srt;
    for(int i=1;i<=n;i++){
        int k; cin>>k;
        arr[i] = arr[i-1] + k;
        srt.push_back({arr[i],i});
    }
    srt.push_back({0,0});
    sort(srt.begin(),srt.end());
    vector<int> pos(n+1);
    for(int i=0;i<=n;i++){
        pos[srt[i].S] = i;
    }
    function<void(int,int,int,int,int)> update = [&](int node, int l, int r, int idx, int value){
        if(l==r){
            tree[node] = value;
            return;
        }
        int mid = (l+r)>>1;
        if(idx<=mid)update(2*node,l,mid,idx,value);
        else update(2*node+1,mid+1,r,idx,value);
        tree[node] = max(tree[2*node],tree[2*node+1]);
    };
    function<int(int,int,int,int,int)> query = [&](int node, int l, int r, int st, int en){
        if(l>en || st>r) return LLONG_MIN;
        if(st<=l && r<=en) return tree[node];
        int mid = (l+r)>>1;
        return max(query(2*node,l,mid,st,en),query(2*node+1,mid+1,r,st,en));
    };
    update(1,0,n,pos[0],0);
    for(int i=1;i<=n;i++){
        f[i] = max(f[i-1],query(1,0,n,0,pos[i])+i);
        update(1,0,n,pos[i],f[i]-i);
    }
    cout<<f[n]<<endl;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}