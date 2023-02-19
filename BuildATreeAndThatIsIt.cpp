#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,k,l,m; cin>>n>>k>>l>>m;
    int x = (k+m-l), y = (k+l-m), z = (l+m-k);
    if(x<0||y<0||z<0||(x&1)||(y&1)||(z&1)||((x+y+z)/2>n-1)){
        cout<<"NO"<<endl; return;
    }
    else cout<<"YES"<<endl,x/=2,y/=2,z/=2;
    int node = 4, nxt = 4;
    if(x==0)node = 1;
    if(y==0)node = 2;
    if(z==0)node = 3;
    if(node==4)nxt=5;
    int curr = node;
    for(int i=1;i<x;i++){
        cout<<curr<<' '<<nxt<<endl;
        curr = nxt; nxt++;
    }
    if(node!=1)cout<<curr<<' '<<1<<endl;
    curr = node;
    for(int i=1;i<y;i++){
        cout<<curr<<' '<<nxt<<endl;
        curr = nxt; nxt++;
    }
    if(node!=2)cout<<curr<<' '<<2<<endl;
    curr = node;
    for(int i=1;i<z;i++){
        cout<<curr<<' '<<nxt<<endl;
        curr = nxt; nxt++;
    }
    if(node!=3)cout<<curr<<' '<<3<<endl;
    for(;nxt<=n;nxt++){
        cout<<1<<' '<<nxt<<endl;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}