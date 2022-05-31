#include<bits/stdc++.h>
#define mp make_pair
#define mod2 998244353ll
#define mod1 1000000007ll
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
#define print(n) cout<<n<<endl
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 2e5;
int a[N], tree[4*N];
void segmentTree(int node, int l, int r){
    if(l==r){tree[node]=a[l];return;}
    int mid = (l+r)/2;
    segmentTree(2*node,l,mid);
    segmentTree(2*node+1,mid+1,r);
    tree[node]=min(tree[2*node],tree[2*node+1]);
}
int query(int node, int l, int r, int st, int en){
    if(l>en || r<st)return 1e9+1;
    if(st<=l && en>=r)return tree[node];
    int mid = (l+r)/2;
    return min(query(2*node,l,mid,st,en),query(2*node+1,mid+1,r,st,en));
}
int main(){
    rapid_iostream;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    segmentTree(1,0,n-1);
    for(int i=0;i<n;i++){
        int l = 0, r=i-1;
        while(l<=r){
            int mid = (l+r)/2;
            int k = query(1,0,n-1,mid,r);
            if(k<a[i])l=mid+1;
            else r=mid-1;
        }
        cout<<l<<' ';
    }
    return 0;
}