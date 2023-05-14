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
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<int> tree(n*4);
    function<void(int,int,int)> segmenttree = [&](int node, int l, int r){
        if(l==r){
            tree[node] = arr[l];
            return;
        }
        int mid = (l+r)>>1;
        segmenttree(2*node,l,mid);
        segmenttree(2*node+1,mid+1,r);
        tree[node] = gcd(tree[2*node],tree[2*node+1]);
    };
    function<int(int,int,int,int,int)> query = [&](int node, int l, int r, int st, int en){
        if(st<=l && en>=r) return tree[node];
        if(st>r || en<l) return 0ll;
        int mid = (l+r)>>1;
        return gcd(query(2*node,l,mid,st,en),query(2*node+1,mid+1,r,st,en));
    };
    segmenttree(1,0,n-1);
    int f[n]{0}, last = -1;
    if(arr[0]==1) f[0] = 1, last = 0;
    for(int i=1;i<n;i++){
        f[i] = f[i-1];
        int l = last+1, r = i;
        while(l<=r){
            int mid = (l+r)>>1;
            int g = query(1,0,n-1,mid,i);
            if(g==i-mid+1){
                f[i]++; last = i; break;
            }
            else if(g<i-mid+1) l = mid+1;
            else r = mid-1;
        }
    }
    for(auto i : f) cout<<i<<" ";cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1; while(t--)code();
    return 0;
}