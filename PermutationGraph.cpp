#define PROGRAM int main(){rapid_iostream;int tc=1;cin>>tc;while(tc-->0){codeforce();}return 0;}
#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define _pq(u) priority_queue<u,vector<u>, Comp>
#define binary(n,k) bitset<k>(n).to_string()
#define println(n) cout<<n<<'\n'
#define MAIN void codeforce();
#define Y() cout<<"YES"<<endl
#define print(n) cout<<n<<' '
#define N() cout<<"NO"<<endl
#define pii pair<int,int>
#define mod1 1000000007ll
#define pli pair<ll,int>
#define pil pair<int,ll>
#define mod2 998244353ll
#include<bits/stdc++.h>
#define pll pair<ll,ll>
typedef long double ld;
typedef long long ll;
#define mp make_pair
using namespace std;
#define endl '\n'
#define S second
#define F first
Compare(pii)
/***************************************************/ MAIN PROGRAM /*******************************************************/
const int N=2.5e5+5;
int tree[N*4];int a[N],n;
void segmentTree(int node, int l, int r){
    if(l==r){
        tree[node]=a[l];
        return;
    }
    int mid = (l+r)/2;
    segmentTree(2*node,l,mid);
    segmentTree(2*node+1,mid+1,r);
    tree[node] = max(tree[2*node],tree[2*node+1]);
}
int query(int node, int l, int r, int st, int en){
    if(en<l || st>r)return INT_MIN;
    if(st<=l && en>=r) return tree[node];
    int mid = (l+r)/2;
    return max(query(2*node,l,mid,st,en), query(2*node+1,mid+1,r,st,en));
}
int treemn[N*4];
void segmentTreemn(int node, int l, int r){
    if(l==r){
        treemn[node]=a[l];
        return;
    }
    int mid = (l+r)/2;
    segmentTreemn(2*node,l,mid);
    segmentTreemn(2*node+1,mid+1,r);
    treemn[node] = min(treemn[2*node],treemn[2*node+1]);
}
int querymn(int node, int l, int r, int st, int en){
    if(en<l || st>r)return INT_MAX;
    if(st<=l && en>=r) return treemn[node];
    int mid = (l+r)/2;
    return min(querymn(2*node,l,mid,st,en), querymn(2*node+1,mid+1,r,st,en));
}
int in[N];
int dist(int l, int r){
    if(l==r) return 0;
    int mrx = in[query(1,1,n,l,r)];
    int mrn1 = in[querymn(1,1,n,l,mrx)];
    int mrn2 = in[querymn(1,1,n,mrx,r)];
    if(mrn1!=mrx && mrn2!=mrx){
        return 2+dist(l,mrn1)+dist(mrn2,r);
    }
    else{
        return 1+dist(l,mrn1)+dist(mrn2,r);
    }
}
void codeforce(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        in[a[i]]=i;
    }
    segmentTree(1,1,n);
    segmentTreemn(1,1,n);
    cout<<dist(1,n)<<endl;
}