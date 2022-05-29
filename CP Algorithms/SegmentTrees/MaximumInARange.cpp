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

const int N=1e5;
ll tree[N*4];            //for safety we take the value of the size of the tree as N*4
int a[N+5];

void segmentTree(int node, int l, int r){
    if(l==r){
        tree[node]=a[l];
        return;
    }
    int mid = (l+r)/2;
    segmentTree(2*node,l,mid);        
    segmentTree(2*node+1,mid+1,r);
    tree[node] = max(tree[2*node],tree[2*node+1]);   //building the segments using subsegments
}
void update(int node, int l, int r, int x, int val){
    if(l==r){tree[node]=val;return;}
    int mid = (l+r)/2;
    if(x<=mid) update(2*node,l,mid,x,val);
    else update(2*node+1,mid+1,r,x,val);
    tree[node]=max(tree[2*node],tree[2*node+1]);
}
ll query(int node, int l, int r, int st, int en){
    if(en<l || st>r)return INT_MIN;                //if range(l,r) doesn't contain any segment of range(st,en)
    if(st<=l && en>=r) return tree[node];    //if range(l,r) completely lie inside the segment(st,en)
    int mid = (l+r)/2;                                  
    return max(query(2*node,l,mid,st,en), query(2*node+1,mid+1,r,st,en));  //in case of partial overlap of range(l,r ) and range(st,en) we further divide the range l,r to get the accurate info
}
int main(){
    rapid_iostream;
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    segmentTree(1,1,n);    //initially the range(l,r) is complete array from 1 to n. This statement constructs the segmentTree
    int q;  cin>>q;
    while(q--){
        int type; cin>>type;  //type 1 query gives the sum of the range of values, type 2 query updates a value at a index
        if(type==1){
            int x, y; cin>>x>>y;
            int result = query(1,1,n,x,y);
            print(result);
        }
        else if(type==2){
            int x, val; cin>>x>>val;
            update(1,1,n,x,val);
            a[x]=val;
            for(int i=1;i<=n;i++){
                cout<<a[i]<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}