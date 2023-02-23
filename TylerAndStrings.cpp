#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
ll mod = 998244353, fact[200005];
ll power(ll n, ll k){
    long  long ans = 1;
    while(k>0){
        if(k&1)ans = (ans*n)%mod;
        k>>=1; n = (n*n)%mod;
    }
    return ans;
}
ll modularInverse(ll a, ll p){
    return power(a,p-2);
}
void factorial(int n){
    fact[0] = 1;
    for(int i=1;i<=n;i++){
        fact[i] = fact[i-1]*i%mod;
    }
}
const int N = 2e5+5;
int s[N], tree[4*N];
void update(int node, int l, int r, int idx, int value){
    if(l==r){
        tree[node] = value;
        return;
    }
    int mid = (l+r)>>1;
    if(idx<=mid) update(2*node, l, mid, idx, value);
    else update(2*node+1, mid+1, r, idx, value);
    tree[node] = tree[2*node]+tree[2*node+1];
}
int query(int node, int l, int r, int st, int en){
    if(st>r || en<l) return 0;
    if(st<=l && en>=r) return tree[node];
    int mid = (l+r)>>1;
    return query(2*node, l, mid, st, en)+query(2*node+1, mid+1, r, st, en);
}
void code(){
    int n,m;
    cin>>n>>m;
    vector<int> t(m);
    int den = 1, ans = 0, cnt = 0, curr = fact[n];
    for(int i=0;i<n;i++){
        int k; cin>>k;
        update(1,1,2e5,k,++s[k]);
    }
    for(int j=0;j<m;j++)cin>>t[j];
    for(auto i : s) if(i) curr = curr*modularInverse(fact[i],mod)%mod;
    for(int j=0;j<min(n,m);j++){
        curr = curr*modularInverse(n-j,mod)%mod;
        int sum = 
        ans = ans + curr*query(1,1,2e5,0,t[j]-1)%mod;
        if(!s[t[j]]){
            cnt = 0; break;
        }
        else cnt = 1;
        curr = curr*s[t[j]]%mod;
        update(1,1,2e5,t[j],--s[t[j]]);
    }
    cout<<(ans+(m>n)*cnt)%mod<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    factorial(2e5);
    int t=1; while(t--)code();
    return 0;
}