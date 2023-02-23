#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;


void code(){
    int n,d; cin>>n>>d;
    vector<int> pos(n+1);
    int mn = 1e9+5, mx = 0, ans = 0;
    for(int i=1;i<=n;i++){
        cin>>pos[i];
        ans = min(ans,pos[i]-pos[i-1]-1);
    }
    pos.push_back(d+1);
    int c = d-pos[n]-1;
    int forward_mx[n+1], backward_mx[n+1], forward_mn[n+1], backward_mn[n+1];
    forward_mx[0]=0,backward_mx[n]=2*c+1,forward_mn[0]=mn,backward_mn[n]=mn;
    for(int i=1;i<=n;i++){
        mx = max(mx,pos[i]-pos[i-1]-1);
        mn = min(mn,pos[i]-pos[i-1]-1);
        forward_mx[i] = mx;
        forward_mn[i] = mn;
    }
    mn = 1e9+5, mx = 2*c+1;
    for(int i=n-1;i>=0;i--){
        mx = max(mx,pos[i+1]-pos[i]-1);
        mn = min(mn,pos[i+1]-pos[i]-1);
        backward_mx[i] = mx;
        backward_mn[i] = mn;
    }
    for(int i=1;i<n;i++){
        int curr = max({forward_mx[i-1],backward_mx[i+1],pos[i+1]-pos[i-1]-1});
        ans = max(ans, min({forward_mn[i-1],backward_mn[i+1],(curr-1)>>1,pos[i+1]-pos[i-1]-1}));
    }
    cout<<max(ans,min(forward_mn[n-1],d-pos[n-1]-1))<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}