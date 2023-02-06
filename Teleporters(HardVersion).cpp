#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
void code(){
    int n, c; cin>>n>>c;
    int arr[n+1]; vector<int> cost(n+1),cost2;
    for(int i=1;i<=n;i++)cin>>arr[i], cost[i] = arr[i]+min(i,n+1-i);
    int cnt = 1, mn = LLONG_MAX, idx = 0;
    vector<int> b;
    vector<pair<int,int>> a;
    for(int i=1;i<=n;i++){
        if(arr[i]+i<mn){
            mn = arr[i]+i;
            idx = i;
        }
        if(i>(n+1)/2){
            a.push_back({cost[i],i-(n+1)/2-1});
            b.push_back(arr[i]+i);
        }
    }
    if(c<mn){
        cout<<0<<endl;
        return;
    }
    else if(n==1){
        if(arr[1]+1<=c)cout<<1<<endl;
        else cout<<0<<endl;
        return;
    }
    int c2 = c;
    cost2 = cost;
    mn = LLONG_MAX, idx = 0;
    for(int i=1;i<=(n+1)/2;i++){
        if(arr[i]+i<mn){
            mn = arr[i]+i;
            idx = i;
        }
    }
    c2-=mn;
    cost2.erase(cost2.begin()+idx);
    sort(cost2.begin(),cost2.end());
    for(int i=1;i<n;i++){
        if(cost2[i]<=c2)c2-=cost2[i],cnt++;
    }
    //segmenttree section
    n = a.size();
    int tree[n*4+5];
    function<void(int,int,int)> build = [&](int node, int l, int r){
        if(l==r){
            tree[node] = a[l].F;
            return;
        }
        int mid = (l+r)>>1;
        build(2*node,l,mid);
        build(2*node+1,mid+1,r);
        tree[node] = tree[2*node]+tree[2*node+1];
    };
    function<void(int,int,int,int,int)> update = [&](int node, int l, int r, int idx, int val){
        if(l==r){
            tree[node] = val;
            return;
        }
        int mid = (l+r)>>1;
        if(idx<=mid) update(2*node,l,mid,idx,val);
        else update(2*node+1,mid+1,r,idx,val);
        tree[node] = tree[2*node]+tree[2*node+1];
    };
    function<int(int,int,int,int,int)> query = [&](int node, int l, int r, int st, int en){
        if(l>en || r<st) return 0ll;
        else if(l>=st && r<=en) return tree[node];
        int mid = (l+r)>>1;
        return query(2*node,l,mid,st,en)+query(2*node+1,mid+1,r,st,en);
    };
    sort(a.begin(),a.end());
    build(1,0,n-1);
    for(int i=0;i<n;i++){
        if(b[a[i].S]>c)continue;
        update(1,0,n-1,i,0);
        int l = 0, r = n-1, k = c-b[a[i].S];
        bool f = false;
        while(l<=r){
            int mid = (l+r)>>1;
            if(query(1,0,n-1,0,mid)<=k)l = mid+1, f=true;
            else r = mid-1;
        }
        update(1,0,n-1,i,a[i].F);
        if(!f)continue;
        l--;
        if(l<i)l++;
        cnt = max(cnt,l+1);
    }
    cout<<cnt<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}